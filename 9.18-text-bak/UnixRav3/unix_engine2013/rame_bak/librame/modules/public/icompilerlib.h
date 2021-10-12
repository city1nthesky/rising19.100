#ifndef _I_COMPILER_LIB_H_
#define _I_COMPILER_LIB_H_

// ʶ��ָ�����г���
#define CODE_SEQUENCE_LEN 0x10

// ʶ���
class ICodeRecordLib : public IUnknown
{
public:
	virtual HRESULT AddCodeRecord (
		IN  CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		IN  BOOL   bEnabled,  // ʶ��ָ�������Ƿ���Ч
		OUT 	PDWORD  pdwIndex = NULL  // ʶ���¼����
		) PURE;
	virtual HRESULT IsCodeRecordExists (
		IN  	CONST  PCHAR   pccCodeSequence  // ʶ��ָ������
		) PURE;
	virtual HRESULT IsCodeRecordExists (
		IN  	DWORD   dwIndex  // ��¼��λ������ֵ
		) PURE;
	virtual HRESULT GetCodeRecordInsertIndex (
		IN  	CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		OUT 	PDWORD  pdwIndex  // ʶ���¼����
		) PURE;
	virtual HRESULT  AddCodeRecordItem(
		IN  CONST  PCHAR  pccCodeSequence,  // ʶ��ָ������
		IN  CONST  PCHAR  pccResult,  // ʶ�����ʶ������
		IN  DWORD  dwIndex = -1  // ʶ���¼������
		) PURE;
	virtual HRESULT IsCodeRecordItemExists (
		IN  CONST  PCHAR  pccCodeSequence,  // ʶ��ָ������
		IN  CONST  PCHAR  pccResult  // ʶ�����ʶ������
		) PURE;
	virtual HRESULT IsCodeRecordItemExists (
		IN  DWORD	dwIndex,  // ��¼��λ������ֵ
		IN  CONST  PCHAR  pccResult  // ʶ�����ʶ������
		) PURE;
	virtual HRESULT  AddMethod(
		IN  CONST  PCHAR  pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwItemIndex, 	 	// ʶ���¼������
		IN  CONST  PCHAR   pccMethod,		// ����������
		IN  DWORD  dwIndex = -1		// ����������λ��
		) PURE;
	virtual HRESULT IsMethodExists (
		IN  CONST  PCHAR  pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwItemIndex, 	 	// ʶ���¼������
		IN  CONST  PCHAR   pccMethod		// ����������
		) PURE;
	virtual HRESULT IsMethodExists (
		IN  DWORD	dwIndex,  // ��¼��λ������ֵ
		IN  DWORD  dwItemIndex, 	 	// ʶ���¼������
		IN  CONST  PCHAR   pccMethod		// ����������
		) PURE;
	virtual HRESULT EnableCodeRecord (
		IN  CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		IN  BOOL   bEnabled  // ʶ��ָ�������Ƿ���Ч
		) PURE;
	virtual HRESULT EnableCodeRecord (
		IN  DWORD  dwIndex,  // ��¼����
		IN  BOOL    bEnabled  // ʶ��ָ�������Ƿ���Ч
		) PURE;
	virtual HRESULT SetCodeRecord (
		IN  CONST  PCHAR  pccSourCodeSequence,  // Դʶ��ָ������
		IN  CONST  PCHAR  pccDestCodeSequence  // Ŀ��ʶ��ָ������
		) PURE;
	virtual HRESULT SetCodeRecord (
		IN  DWORD  dwIndex,  // ��¼����
		IN  CONST  PCHAR  pccDestCodeSequence  // ʶ��ָ������
		) PURE;
	virtual HRESULT  CodeRecordItemCount (
		IN  CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		OUT  PDWORD  pdwCodeRecordItemCount  // ʶ��������
		) PURE;
	virtual HRESULT  MethodCount (
		IN  CONST  PCHAR  pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwItemIndex, 	 	// ʶ���¼������
		OUT  PDWORD  pdwMethodCount  // ʶ�𷽷�����
		) PURE;
	virtual HRESULT  GetCodeRecord (
		IN  DWORD  dwIndex,  // ʶ���¼������ֵ
		OUT  PCHAR  pcCodeSequence,  // ʶ��ָ������
		OUT  PBOOL  pbEnabled = NULL // ʶ��ָ�������Ƿ���Ч
		) PURE;
	virtual HRESULT  GetCodeRecord (
		IN  	CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		OUT 	PDWORD  pdwIndex,  // ʶ���¼����
		OUT  PBOOL   pbEnabled = NULL // ʶ��ָ�������Ƿ���Ч
		) PURE;
	virtual HRESULT  GetCodeRecordItem (
		IN  CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwIndex,  // ʶ���¼������
		OUT  PCHAR  pcResult,   // ʶ���¼���ʶ����
		IN OUT  PDWORD  pdwBufSize	 // ʶ�����ֽ���
		) PURE;
	virtual HRESULT  GetMethod (
		IN  CONST  PCHAR  pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwItemIndex, 	 	// ʶ���¼������
		IN   DWORD  dwIndex, 	// ʶ�𷽷�������ֵ
		OUT  PCHAR   pcMethod,  // ʶ�𷽷���
		IN OUT  PDWORD  pdwBufSize	 // �����ֽ�����
		) PURE;
	virtual HRESULT  RemoveCodeRecordItem(
		IN  CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwIndex  // ʶ��������
		) PURE;
	virtual HRESULT  RemoveMethod(
		IN  CONST  PCHAR   pccCodeSequence,  // ʶ��ָ������
		IN  DWORD  dwItemIndex, 	 	// ʶ���¼������
		IN   DWORD  dwIndex 	// ʶ�𷽷�������ֵ
		) PURE;
	virtual HRESULT  CodeRecordCount (
		IN  PDWORD  pdwCodeRecordCount  // ʶ���¼����
		) PURE;
	virtual HRESULT  RemoveCodeRecord (
		IN  CONST  PCHAR  pccCodeSequence  // ʶ��ָ������
		) PURE;
	virtual HRESULT  RemoveCodeRecord (
		IN  DWORD  dwIndex  // ʶ���¼������ֵ
		) PURE;
	virtual HRESULT  ClearCodeRecord (void) PURE;
	virtual HRESULT  ToAscii (
		IN  CONST  PBYTE  pcbyCodeSequence,  // ʶ��ָ������
		OUT  PCHAR  pAsciiBuf  // ����ʶ��ָ������Ascii����ʽ
		) PURE;
	virtual HRESULT  ToBinary (
		IN  CONST  PCHAR  pccAsciiBuf,  // ʶ��ָ������Ascii����ʽ
		OUT  PBYTE  pbyCodeSequence  // ʶ��ָ������
		) PURE;
	virtual HRESULT  MakeLibrary (
		IN  CONST  PCHAR  pcFilePath,  // �ļ�·��
		IN  BOOL  bFailIfExists	// �Ƿ���Ҫ���ļ�����ʱʹ�ò���ʧ�ܣ�
		) PURE;
	virtual HRESULT  GetSequenceFromPE (
		IN  CONST  CHAR  *pcFilePath,  // PE�ļ�·��
		OUT  PCHAR  pcCodeSequence  // ʶ��ָ������
		) PURE;
	virtual HRESULT  ImportDescription(
		IN  CONST  CHAR*  pcFilePath,  // �����ļ�·��
		OUT  DWORD*  pdwLine,  // ������
		OUT  CHAR*   pcContent,  // ��������
		IN  DWORD  dwContentSize,  // �����ֽ���
		OUT  CHAR*   pcErrorMsg,  // ������Ϣ
		IN  DWORD  dwErrorMsgSize  //������Ϣ����
		) PURE;
public:
	RE_DECLARE_IID;
};
typedef ICodeRecordLib *PICodeRecordLib;

/////////////////////////////////////////////////////////////////////////////////////////

// {15873747-3E73-4081-997C-F1D8E60793C4}
RE_DEFINE_IID(ICodeRecordLib, "{15873747-3E73-4081-997C-F1D8E60793C4}",
			0x15873747, 0x3e73, 0x4081, 0x99, 0x7c, 0xf1, 0xd8, 0xe6, 0x7, 0x93, 0xc4);

// {B71C3948-2EF5-4348-80DF-9035758FDEF5}
DEFINE_GUID(CLSID_CodeRecordLib, 
			0xb71c3948, 0x2ef5, 0x4348, 0x80, 0xdf, 0x90, 0x35, 0x75, 0x8f, 0xde, 0xf5);

/////////////////////////////////////////////////////////////////////////////////////////

#endif //_I_COMPILER_LIB_H_


