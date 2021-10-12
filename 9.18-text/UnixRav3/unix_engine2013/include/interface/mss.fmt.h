#ifndef __MSS_FILE_DEFINE__
#define __MSS_FILE_DEFINE__

#include "xsf.fmt.h"

// Table Attributes
enum
{
	MSTA_BAN		= 0x80000000,			// �ñ� �Ѿ�����ֹʹ��
	MSTA_COMPATIBLE = 0x01000000,			// �ñ� ���ݱ�TABLENAMEΪLibType
											// {���ݱ����ÿ�д��ʽӳ��}
											// ��Ĭ�ϰ����� MSTA_WRITEABLE

	MSTA_WINK		= 0x00000001,			// �ñ� ����פ�ڴ�
	MSTA_WRITEABLE	= 0x00000004,			// �ñ� ���ڴ����ǿ�д��
	MSTA_EXECUTABLE	= 0x00000008,			// �ñ� ���ڴ����ǿ�ִ�е�
	// �ڲ�ʹ��
	MSTA_SHMEM		= 0x00100000,			// �ñ� ʹ�ù����ڴ棬���Դ���������
	MSTA_FLY		= 0x00200000,			// �ñ� ���ǿ��ļ��еı�
};

//
// IGlmLibFile::GetTable
//
enum
{
	GTF_WINK = 1,		// ȡ��� ����פ�ڴ�
};

typedef xsf::SNAME			MSTNAME;
typedef MSTNAME*			LPMSTNAME;
 typedef const MSTNAME *	LPCMSTNAME;

#pragma pack(1)

typedef struct MSTINFO
{
	LE_UI32			AttrU;				// see Table Attributes

	LE_UI32			RNumU;				// if MSTA_COMPATIBLE set, else it's can be any value

	LE_UI32			VerEU;				// End Version
										// �����汾������������ʽ��ʾ
										// �ڼ��ݱ��У�Ϊ��Ľ����汾(������ԭ��)
										// ���������У���ֵ����ʹ�ñ����ݼ����

	LE_UI32			VerBU;				// Begin Version, Option, // if MSTA_COMPATIBLE set

	//////////////////////////////////////
	LE_UI16			TagU;				// Always set 0

	LE_UI16			DiffM;				// 'F' : FLRDiff, 'J' : JDiff(BinDiff), 'O': Override

	UINT8			DiffParam[8];		// ����Ƚ��Լ��ϲ��㷨����ز�����Ŀǰֻ��FLRDiff�в�����������XLR_PARAM�ṹ
	
}RS_PACK_ONEBYTE MSTINFO, *LPMSTINFO;

//////////////////////////////////////////////////////////////////////////

namespace mss
{
	enum FMARK
	{
		MARK_MSLF		= 0x4D534C46,   //'MSLF'
		MARK_MSLP		= 0x4D534C50,   //'MSLP',
	};

	enum DIFFID
	{
		DID_INVALID		=  0 ,
		DID_JDIFF		= 'J',
		DID_FLRDIFF		= 'F',
		DID_VLRDIFF		= 'V',
		DID_OVERRIDE	= 'O',
	};

	// In SectionHeader.DiffParam
	struct XLR_PARAM
	{
		UINT8	KeyLen;
		LE_UI32	RecLen;	// Only DIFF_FLRDIFF
	} RS_PACK_ONEBYTE;

	enum _FIXMID8
	{
		CMD_DROP		= 'D',				// Section.Size === 0;
		CMD_OVERRIDE	= 'O',				// Section.Data = NewTable
		CMD_MODIFY		= 'M',				// Section.Data = delta
	};

	typedef UINT8	FIXMID8;
	typedef UINT8	DIFFID8;

	struct TABINF_HDR : xsf::SHDR
	{
		MSTINFO	Ext;
	} RS_PACK_ONEBYTE;

	struct TABFIX_HDR : xsf::SHDR
	{
		FIXMID8	FixCmd;
	} RS_PACK_ONEBYTE;

	struct LIBTYPENAME
	{
		LE_UI32 Mark;
		LE_UI32	LibType;
	} RS_PACK_ONEBYTE;

#pragma pack()

	enum { LIBTYPE_MARK = 0x4C425450 /*'LBTP'*/ };

	static inline VOID TabIdToName( DWORD dwId, MSTNAME& rName )
	{
		LIBTYPENAME& rTypeName = *(LIBTYPENAME*)&rName;
		LIBTYPENAME TypeName;
		TypeName.Mark = mss::LIBTYPE_MARK;
		TypeName.LibType = (UINT32)dwId;
		rTypeName = TypeName;
	}
	static inline HRESULT TabNameToId( DWORD& dwId, MSTNAME& rName )
	{
		LIBTYPENAME& rTypeName = *(LIBTYPENAME*)&rName;
		if( rTypeName.Mark != mss::LIBTYPE_MARK )
			return E_UNEXPECTED;
		dwId = (UINT32)rTypeName.LibType;
		return S_OK;
	}


};

#endif

