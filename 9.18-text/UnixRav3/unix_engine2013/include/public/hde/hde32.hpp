/*
* Hacker Disassembler Engine 32 C
* Copyright (c) 2008-2009, Vyacheslav Patkov.
* All rights reserved.
*
*/

/* #include <stdint.h> */
#ifndef __RX_COM_HDE32_H_H_H__
#define __RX_COM_HDE32_H_H_H__

#include "hde32.h"
#include "table32.h"

#ifdef __cplusplus
extern "C" {
#endif

STATICINLINE unsigned int hde32_disasm(bptr_t& code, hde64s *hs)
{
	if(!hs) return 0;

	uint8_t x, c, cflags, opcode, pref = 0;
	uint8_t *ht = hde32_table, m_mod, m_reg, m_rm, disp_size = 0;
	uint8_t u8;
	uint16_t u16;
	uint32_t u32;
	unsigned char* start = code.ptr();

	bptr_t & p = code;
	memset(hs,0,sizeof(hde64s));

	for (x = 16; x; x--)
	{
		if( !p.next(c) ) return 0;
		switch (c)
		{
		case 0xf3:
			hs->p_rep = c;
			pref |= PRE32_F3;
			break;
		case 0xf2:
			hs->p_rep = c;
			pref |= PRE32_F2;
			break;
		case 0xf0:
			hs->p_lock = c;
			pref |= PRE32_LOCK;
			break;
		case 0x26: case 0x2e: case 0x36:
		case 0x3e: case 0x64: case 0x65:
			hs->p_seg = c;
			pref |= PRE32_SEG;
			break;
		case 0x66:
			hs->p_66 = c;
			pref |= PRE32_66;
			break;
		case 0x67:
			hs->p_67 = c;
			pref |= PRE32_67;
			break;
		default:
			goto pref_done;
		}
	}
pref_done:

	if( x<=1 ) return 0;

	hs->flags = (uint32_t)pref << 23;

	if (!pref)
		pref |= PRE32_NONE;

	if ((hs->opcode = c) == 0x0f)
	{
		if( !p.next(c) ) return 0;
		hs->opcode2 = c;
		ht += DELTA32_OPCODES;
	}
	else if (c >= 0xa0 && c <= 0xa3)
	{
		if (pref & PRE32_67)
			pref |= PRE32_66;
		else
			pref &= ~PRE32_66;
	}

	opcode = c;
	cflags = ht[ht[opcode / 4] + (opcode % 4)];

	if (cflags == C32_ERROR) {
		hs->flags |= F32_ERROR | F32_ERROR_OPCODE;
		cflags = 0;
		if ((opcode & -3) == 0x24)
			cflags++;
	}

	x = 0;
	if (cflags & C32_GROUP) {
		uint16_t t;
		t = GETWORD(ht + (cflags & 0x7f));
		cflags = (uint8_t)t;
		x = (uint8_t)(t >> 8);
		hs->flags |= F32_GROUP;
	}

	if (hs->opcode2) {
		ht = hde32_table + DELTA32_PREFIXES;
		if (ht[ht[opcode / 4] + (opcode % 4)] & pref)
			hs->flags |= F32_ERROR | F32_ERROR_OPCODE;
	}

	if (cflags & C32_MODRM) {
		hs->flags |= F32_MODRM;
		if( !p.next(c) ) return 0;
		hs->modrm = c;
		hs->modrm_mod = m_mod = c >> 6;
		hs->modrm_rm = m_rm = c & 7;
		hs->modrm_reg = m_reg = (c & 0x3f) >> 3;

		if (x && ((x << m_reg) & 0x80))
			hs->flags |= F32_ERROR | F32_ERROR_OPCODE;

		if (!hs->opcode2 && opcode >= 0xd9 && opcode <= 0xdf) {
			uint8_t t = opcode - 0xd9;
			if (m_mod == 3) {
				ht = hde32_table + DELTA32_FPU_MODRM + t*8;
				t = ht[m_reg] << m_rm;
			} else {
				ht = hde32_table + DELTA32_FPU_REG;
				t = ht[t] << m_reg;
			}
			if (t & 0x80)
				hs->flags |= F32_ERROR | F32_ERROR_OPCODE;
		}

		if (pref & PRE32_LOCK) {
			if (m_mod == 3) {
				hs->flags |= F32_ERROR | F32_ERROR_LOCK;
			} else {
				uint8_t *table_end, op = opcode;
				if (hs->opcode2) {
					ht = hde32_table + DELTA32_OP2_LOCK_OK;
					table_end = ht + DELTA32_OP_ONLY_MEM - DELTA32_OP2_LOCK_OK;
				} else {
					ht = hde32_table + DELTA32_OP_LOCK_OK;
					table_end = ht + DELTA32_OP2_LOCK_OK - DELTA32_OP_LOCK_OK;
					op &= -2;
				}
				for (; ht != table_end; ht++)
					if (*ht++ == op) {
						if (!((*ht << m_reg) & 0x80))
							goto no_lock_error;
						else
							break;
					}
					hs->flags |= F32_ERROR | F32_ERROR_LOCK;
no_lock_error:
					;
			}
		}

		if (hs->opcode2) {
			switch (opcode) {
			case 0x20: case 0x22:
				m_mod = 3;
				if (m_reg > 4 || m_reg == 1)
					goto error_operand;
				else
					goto no_error_operand;
			case 0x21: case 0x23:
				m_mod = 3;
				if (m_reg == 4 || m_reg == 5)
					goto error_operand;
				else
					goto no_error_operand;
			}
		} else {
			switch (opcode) {
			case 0x8c:
				if (m_reg > 5)
					goto error_operand;
				else
					goto no_error_operand;
			case 0x8e:
				if (m_reg == 1 || m_reg > 5)
					goto error_operand;
				else
					goto no_error_operand;
			}
		}

		if (m_mod == 3)
		{
			uint8_t *table_end;
			if (hs->opcode2) {
				ht = hde32_table + DELTA32_OP2_ONLY_MEM;
				table_end = ht + sizeof(hde32_table) - DELTA32_OP2_ONLY_MEM;
			} else {
				ht = hde32_table + DELTA32_OP_ONLY_MEM;
				table_end = ht + DELTA32_OP2_ONLY_MEM - DELTA32_OP_ONLY_MEM;
			}
			for (; ht != table_end; ht += 2)
				if (*ht++ == opcode) {
					if (*ht++ & pref && !((*ht << m_reg) & 0x80))
						goto error_operand;
					else
						break;
				}
				goto no_error_operand;
		}
		else if (hs->opcode2)
		{
			switch (opcode) {
			case 0x50: case 0xd7: case 0xf7:
				if (pref & (PRE32_NONE | PRE32_66))
					goto error_operand;
				break;
			case 0xd6:
				if (pref & (PRE32_F2 | PRE32_F3))
					goto error_operand;
				break;
			case 0xc5:
				goto error_operand;
			}
			goto no_error_operand;
		} else
			goto no_error_operand;

error_operand:
		hs->flags |= F32_ERROR | F32_ERROR_OPERAND;
no_error_operand:

		if( !p.next(c) ) return 0;
		//c = *p++;
		if (m_reg <= 1) {
			if (opcode == 0xf6)
				cflags |= C32_IMM8;
			else if (opcode == 0xf7)
				cflags |= C32_IMM_P66;
		}

		switch (m_mod) {
		case 0:
			if (pref & PRE32_67) {
				if (m_rm == 6)
					disp_size = 2;
			} else
				if (m_rm == 5)
					disp_size = 4;
			break;
		case 1:
			disp_size = 1;
			break;
		case 2:
			disp_size = 2;
			if (!(pref & PRE32_67))
				disp_size <<= 1;
		}

		if (m_mod != 3 && m_rm == 4 && !(pref & PRE32_67)) {
			hs->flags |= F32_SIB;
			if( !p.seek(1) ) return 0;
			//p++;
			hs->sib = c;
			hs->sib_scale = c >> 6;
			hs->sib_index = (c & 0x3f) >> 3;
			if ((hs->sib_base = c & 7) == 5 && !(m_mod & 1))
				disp_size = 4;
		}

		if( !p.seek(-1) )
			return 0;
		//////////////////////////////////////////////////////////////////////////
		hs->len2 = p.ptr() - start;
		//p--;
		switch (disp_size) {
		case 1:
			hs->flags |= F32_DISP8;
			if( !p.peek( u8 ) )
				return 0;
			hs->disp.disp8 = u8;
			break;
		case 2:
			hs->flags |= F32_DISP16;
			if( !p.peek( u16) )
				return 0;
			hs->disp.disp16 = u16;
			break;
		case 4:
			hs->flags |= F32_DISP32;
			if( !p.peek( u32 ) )
				return 0;
			hs->disp.disp32 = u32;
		}
		p.seek(disp_size);
		//p += disp_size;
	}
	else if (pref & PRE32_LOCK)
	{
		hs->flags |= (F32_ERROR | F32_ERROR_LOCK);
	}

	if( !hs->len2 )
		hs->len2 = p.ptr() - start;

	if (cflags & C32_IMM_P66)
	{
		hs->len2 = p.ptr() - start;

		if (cflags & C32_REL32)
		{
			if (pref & PRE32_66) {
				hs->flags |= F32_IMM16 | F32_RELATIVE;
				if( !p.fetch( u16 ) )
					return 0;
				hs->imm.imm16 = u16;
				//p += 2;
				goto disasm_done;
			}
			goto rel32_ok;
		}
		if (pref & PRE32_66) {
			hs->flags |= F32_IMM16;
			if( !p.fetch( u16 ) )
				return 0;
			hs->imm.imm16 = u16;
			//p += 2;
		} else {
			hs->flags |= F32_IMM32;
			if( !p.fetch( u32 ) )
				return 0;
			hs->imm.imm32 = u32;
			//p += 4;
		}
	}
	if (cflags & C32_IMM16)
	{
		hs->len2 = p.ptr() - start;

		//hs->len2 = p.ptr() - start;
		if (hs->flags & F32_IMM32) {
			hs->flags |= F32_IMM16;
			if( !p.fetch( u16 ) )
				return 0;
			hs->disp.disp16 = u16;
		} else if (hs->flags & F32_IMM16) {
			hs->flags |= F32_2IMM16;
			if( !p.fetch( u16 ) )
				return 0;
			hs->disp.disp16 = u16;
		} else {
			hs->flags |= F32_IMM16;
			if( !p.fetch( u16 ) )
				return 0;
			hs->imm.imm16 = u16;
		}
		//p += 2;
	}
	if (cflags & C32_IMM8)
	{
		hs->len2 = p.ptr() - start;

		//hs->len2 = p.ptr() - start;
		hs->flags |= F32_IMM8;
		if( !p.fetch( u8 ) )
			return 0;
		hs->imm.imm8 = u8;
	}

	if (cflags & C32_REL32)
	{
rel32_ok:
		hs->len2 = p.ptr() - start;
		hs->flags |= F32_IMM32 | F32_RELATIVE;
		if( !p.fetch( u32 ) )
			return 0;
		hs->imm.imm32 = u32;
		//p += 4;
	}
	else if (cflags & C32_REL8)
	{
		hs->len2 = p.ptr() - start;
		hs->flags |= F32_IMM8 | F32_RELATIVE;
		if( !p.fetch( u8 ) )
			return 0;
		hs->imm.imm8 = u8;
	}

disasm_done:
	if ((hs->len = (uint8_t)(p.ptr() - start/*-(uint8_t *)code*/)) > 15) {
		hs->flags |= F32_ERROR | F32_ERROR_LENGTH;
		//hs->len = 15;
	}
	return (unsigned int)hs->len;
}

#ifdef __cplusplus
}
#endif

#endif //__RX_COM_HDE32_H_H_H__
