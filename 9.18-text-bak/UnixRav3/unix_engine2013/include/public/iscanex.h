#ifndef __RE_SCANEX_INTERFACE_H_2010__
#define __RE_SCANEX_INTERFACE_H_2010__

/////////////////////////////////////////////////////////////////////////////////////////////////
// extend scan method:
// enum LOCATION_POINTER_TYPE
// {
// 	POINTER_EOF = 0 ,  // -> ������
// 	POINTER_FILE ,	 // -> �ļ�ƫ��
// 	POINTER_MEM ,	  // -> �ڴ����Ե�ַ
// 	POINTER_VALUE ,	// -> ��ֵ
// 
// 	POINTER_INVALID = 0xFFFFFFFF,  // ��Ч
// };
// 
// typedef struct tagPELocation
// {
// 	union
// 	{
// 		DWORD linear ; // �ڴ����Ե�ַ
// 		DWORD offset ; // �ļ�ƫ��
// 		DWORD data ;   // ��ֵ����
// 	};
// 	DWORD type ; // LOCATION_POINTER_TYPE
// } PELocation, *PPELocation ;
// 
// 
// // ��׼����֮װ����
// class IPEEngStash : public IUnknown
// {
// public:
// 	// pe�ļ�����
// 	STDMETHOD(GetPEArc)(IREPEArchive **pppearc) = 0;
// 	// ���������
// 	STDMETHOD(GetVMObj)(IREVM **ppvmobj) = 0;
// 	// ��׼��������չ����ָ��ʹ�С
// 	STDMETHOD_(const BYTE*,GetStdExtLibData)(OUT WORD &wSize) = 0 ;  // return NULL if failed
// 	// ��˷���÷������
// 	STDMETHOD(GetLocationData)( int index, PELocation &loc ) = 0;
// public:
// 	RE_DECLARE_IID;
// };
// RE_DEFINE_IID(IPEEngStash, "{36EA966F-E05A-419a-A429-54B8D31455DB}",
// 			  0x36ea966f, 0xe05a, 0x419a, 0xa4, 0x29, 0x54, 0xb8, 0xd3, 0x14, 0x55, 0xdb);
// 
// 
// typedef IUnknown IREPEMethodParam;
// 
// // ��׼����
// class IREPEStdMethod : public IUnknown
// {
// public:
// 	STDMETHOD(Invoke)(IUnknown* punk, IREPEMethodParam* /*pstk*/, OUT PELocation *presult) = 0;
// public:
// 	RE_DECLARE_IID;
// };
// RE_DEFINE_IID(IREPEStdMethod, "{9A9B2485-119B-4dca-A3A1-997C09646D25}",
// 			  0x9a9b2485, 0x119b, 0x4dca, 0xa3, 0xa1, 0x99, 0x7c, 0x9, 0x64, 0x6d, 0x25);

// ��չ�鶾��������
// {E3BEFA13-39DA-44d2-92A4-21B80B211BFA}
DEFINE_GUID(CLSID_PESTDEX_ScanEx, 
0xe3befa13, 0x39da, 0x44d2, 0x92, 0xa4, 0x21, 0xb8, 0xb, 0x21, 0x1b, 0xfa);
#define CLSID_CREPEStdMethodScanEx	CLSID_PESTDEX_ScanEx
/////////////////////////////////////////////////////////////////////////////////////////////////


class IREEngineScanEx : public IUnknown
{
public:
	STDMETHOD_(DWORD, Scan)(IUnknown *punkArchive, void *pvparam) = 0;
	STDMETHOD_(DWORD, Kill)(IUnknown *punkArchive, void *pvparam) = 0;
public:
	RE_DECLARE_IID;
};
RE_DEFINE_IID(IREEngineScanEx, "{132CE9E9-242B-4e76-AA0C-0FEE19CCA959}",
0x132ce9e9, 0x242b, 0x4e76, 0xaa, 0xc, 0xf, 0xee, 0x19, 0xcc, 0xa9, 0x59);


// ��ǰ��չ��/ɱ������
// {C96AA3EC-447A-4ecb-9719-9D916A598EAF}
DEFINE_GUID(CLSID_CREEngineScanExPre, 
0xc96aa3ec, 0x447a, 0x4ecb, 0x97, 0x19, 0x9d, 0x91, 0x6a, 0x59, 0x8e, 0xaf);

// �����չ��/ɱ������
// {3B216068-5205-4a40-804B-C80330716D4A}
DEFINE_GUID(CLSID_CREEngineScanExPost, 
0x3b216068, 0x5205, 0x4a40, 0x80, 0x4b, 0xc8, 0x3, 0x30, 0x71, 0x6d, 0x4a);

// ��չɱ������
// {E7F0D28C-2451-4ea1-93C5-6EFFB5F36CC5}
DEFINE_GUID(CLSID_CREEngineKillEx, 
0xe7f0d28c, 0x2451, 0x4ea1, 0x93, 0xc5, 0x6e, 0xff, 0xb5, 0xf3, 0x6c, 0xc5);

// ��չ��ɱδ֪���岡������
// {6838FC2A-60D2-4c89-AF35-5A1B6DD28F38}
DEFINE_GUID(CLSID_CREEngineUnkVirusEx, 
0x6838fc2a, 0x60d2, 0x4c89, 0xaf, 0x35, 0x5a, 0x1b, 0x6d, 0xd2, 0x8f, 0x38);


//////////////////////////////////////////////////////////////////////////


// ��չ����PE��Դ�������������ĵ�
// {4C7EF6CF-53F5-4a05-ACDA-48E4C487AB24}
DEFINE_GUID(CLSID_CREArchivePEResDropperEx, 
0x4c7ef6cf, 0x53f5, 0x4a05, 0xac, 0xda, 0x48, 0xe4, 0xc4, 0x87, 0xab, 0x24);


//////////////////////////////////////////////////////////////////////////


// PE�ļ����ò鶾���棨Interface IREEngine����
// {20BC865A-BEAA-4249-8751-ED9E1B1FD7F7}
DEFINE_GUID(CLSID_CREPEPostEngine, 
0x20bc865a, 0xbeaa, 0x4249, 0x87, 0x51, 0xed, 0x9e, 0x1b, 0x1f, 0xd7, 0xf7);


//////////////////////////////////////////////////////////////////////////

// PE �����ļ�ɨ������ ( Interface IREEngine����
// 2009/3/19
// {F367899A-701A-47f7-A510-AD143CE9009D}
DEFINE_GUID( CLSID_CREScanSuspEx,
0xf367899a, 0x701a, 0x47f7, 0xa5, 0x10, 0xad, 0x14, 0x3c, 0xe9, 0x0, 0x9d);

// ��չ����PE Overlay�����ĵ�
// {08C11513-B379-4098-959F-1CEE6AE8C82D}
DEFINE_GUID( CLSID_CREPEOverlayCompoundArchive, 
0x8c11513, 0xb379, 0x4098, 0x95, 0x9f, 0x1c, 0xee, 0x6a, 0xe8, 0xc8, 0x2d);


//////////////////////////////////////////////////////////////////////////


// PE Overlay�鶾���棨Interface IREEngine, IREEngineJudgeCompound����
// {1C481601-9B30-425c-80CE-65882D84B525}
DEFINE_GUID( CLSID_COverlayJudgeEngine, 
0x1c481601, 0x9b30, 0x425c, 0x80, 0xce, 0x65, 0x88, 0x2d, 0x84, 0xb5, 0x25);


//////////////////////////////////////////////////////////////////////////

// {2e689935-04fb-4306-b0be-2715174720c5} ��ǵ�ʱ���õ�����ֹ�ڶ��β���
DEFINE_GUID(PID_SCENEX_PACKER_SCANED, 
			0x2e689935, 0x04fb, 0x4306, 0xb0, 0xbe, 0x27, 0x15, 0x17, 0x47, 0x20, 0xc5);

// {C0E98E74-03FA-4d24-8F2B-05B690EBDB6A} �ж��Ƿ��а汾��Ϣ��ʱ����
DEFINE_GUID(PID_FILE_PE_VERSION,
			0xc0e98e74, 0x3fa, 0x4d24, 0x8f, 0x2b, 0x5, 0xb6, 0x90, 0xeb, 0xdb, 0x6a);

// {0CE07187-4A8C-4174-9852-92AF07781081} �ж��Ƿ�������ǩ��ʱ����
DEFINE_GUID(PID_FILE_PE_CERTIFICATE, 
			0xce07187, 0x4a8c, 0x4174, 0x98, 0x52, 0x92, 0xaf, 0x7, 0x78, 0x10, 0x81);

//////////////////////////////////////////////////////////////////////////


/*********
* Only defined for ScanEx:
*********/
#ifndef	_E2234C58_D03C_43F3_92A2_D45522D22F21_

#define I_EAX	0
#define I_ECX	1
#define I_EDX	2
#define I_EBX	3
#define I_ESP	4
#define I_EBP	5
#define I_ESI	6
#define I_EDI	7

#define I_ES	0
#define I_CS	1
#define I_SS	2
#define I_DS	3
#define I_FS	4
#define I_GS	5

#include "iexceptlevel.h"

// Where decode reference?
#define EXEC_DEC_AT_IMAGE	(0)
#define EXEC_DEC_AT_STACK	(1<<6)

#endif //#ifndef _E2234C58_D03C_43F3_92A2_D45522D22F21_


/*********
* Environment parameters:
*********/
class IExecExport;
typedef struct tagSTEXECEXP_ENVPARAM
{
	BOOL	bBadFile;
	DWORD	idVirus;
	DWORD	dwParam_1;
	DWORD	dwParam_2;
	IExecExport *pcExecExport;
}STEXECEXP_ENVPARAM;


typedef BOOL (*PFNSTEPCALLBACK)(LPCVOID pUserParam);


class IExecExport
{
public:
	enum ERROR_CODE
	{
		EC_SUCCESS = 0,
		EC_VE_NEW_DECODE, //��ƥ�䵽�˴���תǰ���ֲ������µĽ���
		EC_VE_NORECORD,   //û�������ת��¼(δ���������¼̫���ѱ�����)
		EC_VE_RUN_API,	//��һ��ָ�����ж�ָ���һ��API����
		EC_MALLOC,		//�ڴ����ʧ��
		EC_INIT,		  //δ����ʼ�����ʼ��ʧ��
		EC_VE_OVERFLOW,   //IP��ַ��¼�����
		EC_VE_NULLLOOP,   //�ﵽ����ѭ������
		EC_VM,			//������쳣(�������˳��������쳣)
		EC_FILE,		  //�����ļ���������
		EC_NOMATCHING,	//��ƥ��
		EC_ERROR		  //����δ֪����
	};
	enum FILE_SEEK_POSITION 
	{ 
		SPBegin = 0x0,   //���ļ�ͷ
		SPCurrent = 0x1, //�ӵ�ǰλ��
		SPEnd = 0x2	  //���ļ�β
	};

	//ȡ�����һ�εĴ����ʶ
	virtual DWORD GetLastError(void) = 0;
	//ȡ��ĳ���鶾�����Ľ����ַ��
	virtual BOOL GetSMResultAddr(DWORD idSM, OUT DWORD *pdwAddr) = 0;

	/*********
	* ����ִ��:
	*********/
	//��λ���������������и��ټ�¼��Ϣ
	virtual bool ResetVM(void) = 0;
	//���������ڴ�ҳ������
	virtual bool EnableMemoryWriteProtect(bool bEnable) = 0;
	//�����������ִ�в���
	virtual void SetMaxVESteps(DWORD dwMaxSteps) = 0;
	//�����쳣����
	virtual void SetExceptionLevel(STEXCEPTIONLEVEL *pstEL) = 0;
	//����쳣��־
	virtual void ClearExceptionMark(void) = 0;
	//��õ�ǰ�쳣����
	virtual DWORD GetExceptionCount(void) = 0;
	//��õ�һ���쳣��ַ��0 = ʧ�ܣ�
	virtual DWORD GetFirstExceptionLinear(void) = 0;
	//�����һ���쳣��ַ��0 = ʧ�ܣ�
	virtual DWORD GetNextExceptionLinear(void) = 0;
	//���ӳ����ػ�ַ
	virtual DWORD GetImageBase(void) = 0;
	//����ִ��
	virtual BOOL Step(DWORD dwSteps = 1) = 0;
	virtual BOOL ConditionStep(PFNSTEPCALLBACK pfnCallBack, void* pUserParam) = 0;
	//���е�ָ���Ľ�����ת������
	virtual BOOL GoDecodeJumpTimes(DWORD dwDecodeTimes, DWORD dwJumpTimes) = 0;
	//ȡ�õ�ǰ������ת����
	virtual DWORD GetDecodeJumpTimes(OUT DWORD *pdwJumpTimes = NULL) = 0;
	//ȡ��ָ��������ת�����ļ�¼
	virtual BOOL GetDecodeJumpRecord(DWORD dwDecodeTimes, DWORD dwJumpTimes,
									 OUT DWORD *pdwLinearBeg, OUT DWORD *pdwLinearEnd,
									 DWORD ufWhere = EXEC_DEC_AT_IMAGE) = 0;
	//�����ڴ��д
	virtual BOOL VirtualMemRead(DWORD dwLinear, OUT void *pvBuffer, DWORD dwLength) = 0;
	virtual BOOL VirtualMemReadDeReloc(DWORD dwLinear, OUT void *pvBuffer, DWORD dwLength) = 0;
	virtual BOOL VirtualMemWrite(DWORD dwLinear, void *pvData, DWORD dwLength) = 0;
	//��ȡͨ�üĴ����� I_EAX, I_EBX, I_ECX, I_EDX, I_ESP, I_EBP, I_EDI, I_ESI
	virtual DWORD GetGeneralReg(DWORD dwRegIndex) = 0;
	virtual void  SetGeneralReg(DWORD dwRegIndex, DWORD dwValue) = 0;
	//��ȡָ��ָ��Ĵ���
	virtual DWORD GetEIPReg(void) = 0;
	virtual void  SetEIPReg(DWORD dwValue) = 0;
	//��ȡ��־�Ĵ���
	virtual DWORD GetEFlagReg(void) = 0;
	virtual void  SetEFlagReg(DWORD dwValue) = 0;
	//��ȡ�μĴ���
	virtual WORD GetSegmentReg(DWORD dwSegIndex) = 0;
	virtual void SetSegmentReg(DWORD dwSegIndex, WORD wValue) = 0;

	/*********
	* �����ļ�����:
	*********/
	//���ļ������ض�д�ֽ���
	virtual DWORD Read(void *pvBuffer, DWORD dwLen) = 0;
	//ָ��λ�ö������ض�д�ֽ���
	virtual DWORD ReadPos(void *pvBuffer, DWORD dwPos, DWORD dwLen) = 0;
	//д�ļ������ض�д�ֽ���
	virtual DWORD Write(void *pvBuffer, DWORD dwLen) = 0;
	//ָ��λ��д�����ض�д�ֽ���
	virtual DWORD WritePos(void *pvBuffer, DWORD dwPos, DWORD dwLen) = 0;
	//�ƶ��ļ�ָ��
	virtual HRESULT Seek(DWORD dwPos, WORD wFrom = SPBegin) = 0;
	//ȡ��ǰ�ļ�ָ�룬0xFFFFFFFF������
	virtual DWORD Tell(void) = 0;
	//ȡ�ļ���С��0xFFFFFFFF������
	virtual DWORD GetLength(void) = 0;
	//���ļ���С
	virtual BOOL SetLength(DWORD dwNewLen) = 0;
	//ɾ���ļ�
	virtual BOOL Remove(void) = 0;
	//�������ݿ�(����)
	virtual BOOL CopyDataBlock(DWORD dwFileOffsetDest,DWORD dwLength,
							   DWORD dwAddrSrc, BOOL bSrcIsMem = TRUE) = 0;
	//�ƶ����ݿ�(����)
	virtual BOOL MoveDataBlock(DWORD dwFileOffsetDest,DWORD dwLength,
							   DWORD dwAddrSrc, BOOL bSrcIsMem = TRUE) = 0;
	//�������ݿ�(����)
	virtual BOOL InsertDataBlock(DWORD dwFileOffsetDest, void *pvData,
								 DWORD dwLength) = 0;
	//�޸����ݿ�(����)
	virtual BOOL ModifyDataBlock(DWORD dwFileOffsetDest, void *pvData, DWORD dwLength) = 0;
	//������ݿ�(����)
	virtual BOOL FillDataBlock(DWORD dwFileOffsetDest, BYTE byValue, DWORD dwLength) = 0;
	//ɾ�����ݿ�
	virtual BOOL DeleteDataBlock(DWORD dwFileOffsetDest, DWORD dwLength) = 0;
	//�������ڴ��е��ļ�ӳ���ύ�������ļ�
	virtual BOOL VirtualMemCommitFile(void) = 0;
	//���������ļ��������ڴ��еĶ�����ƥ�䴮�������ļ����ֽ���
	virtual BOOL FloatingSearch(DWORD dwAddrBeg, DWORD dwRange, BYTE *pbyFind,
								DWORD dwFindLen, OUT DWORD *pdwAddrMatch,
								BOOL bSearchInMem = TRUE) = 0;

	/*********
	* Ѱַת��:
	*********/
	//���ڴ��е����Ե�ַת��Ϊ�ļ���������ļ�ͷ���ļ�ƫ��
	virtual BOOL ConvertLinearToFileOffset(DWORD dwLinear,  OUT DWORD *pdwFileOffset) = 0;
	//���ļ���������ļ�ͷ���ļ�ƫ��ת��Ϊ�ڴ��е����Ե�ַ
	virtual BOOL ConvertFileOffsetToLinear(OUT DWORD *pdwLinear, DWORD dwFileOffset) = 0;

	/*********
	* Misc:
	*********/
	virtual BOOL CalculateCheckSum(void) = 0;
};


#endif // #ifndef __RE_SCANEX_INTERFACE_H__
