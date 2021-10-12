/*
 * Hacker Disassembler Engine 32
 * Copyright (c) 2006-2009, Vyacheslav Patkov.
 * All rights reserved.
 *
 * hde32.h: C/C++ header file
 *
 */

#ifndef _RX_COM_HDE32_H_
#define _RX_COM_HDE32_H_

/* stdint.h - C99 standard header
 * http://en.wikipedia.org/wiki/stdint.h
 *
 * if your compiler doesn't contain "stdint.h" header (for
 * example, Microsoft Visual C++), you can download file:
 *   http://www.azillionmonkeys.com/qed/pstdint.h
 * and change next line to:
 *   #include "pstdint.h"
 */

#include <stdint.h>
#include "../bptr.h"

#define F32_MODRM			0x00000001
#define F32_SIB				0x00000002
#define F32_IMM8			0x00000004
#define F32_IMM16			0x00000008
#define F32_IMM32			0x00000010
#define F32_DISP8			0x00000020
#define F32_DISP16			0x00000040
#define F32_DISP32			0x00000080
#define F32_RELATIVE		0x00000100
#define F32_2IMM16			0x00000800
#define F32_ERROR			0x00001000
#define F32_ERROR_OPCODE	0x00002000
#define F32_ERROR_LENGTH	0x00004000
#define F32_ERROR_LOCK		0x00008000
#define F32_ERROR_OPERAND	0x00010000
#define F32_PREFIX_REPNZ	0x01000000
#define F32_PREFIX_REPX		0x02000000
#define F32_PREFIX_REP		0x03000000
#define F32_PREFIX_66		0x04000000
#define F32_PREFIX_67		0x08000000
#define F32_PREFIX_LOCK		0x10000000
#define F32_PREFIX_SEG		0x20000000
#define F32_PREFIX_ANY		0x3f000000
#define F32_GROUP			0x40000000

#define PREFIX_SEGMENT_CS   0x2e
#define PREFIX_SEGMENT_SS   0x36
#define PREFIX_SEGMENT_DS   0x3e
#define PREFIX_SEGMENT_ES   0x26
#define PREFIX_SEGMENT_FS   0x64
#define PREFIX_SEGMENT_GS   0x65
#define PREFIX_LOCK         0xf0
#define PREFIX_REPNZ        0xf2
#define PREFIX_REPX         0xf3
#define PREFIX_OPERAND_SIZE 0x66
#define PREFIX_ADDRESS_SIZE 0x67

//#ifdef __cplusplus
//extern "C" {
//#endif
//
///* __cdecl */
//unsigned int hde32_disasm(bptr_t& code, hde64s *hs = 0);
//
//#ifdef __cplusplus
//}
//#endif

#endif /* _RX_COM_HDE32_H_ */
