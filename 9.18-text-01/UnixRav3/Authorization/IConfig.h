////////////////////////////////////////////////////////////////////////////////
//	��Ŀ���ƣ�����ģ��ӿ�
//	�ļ����ƣ�IConfig.h
//	ʵ�ֹ��ܣ�
//		���õĽṹ��һ�����ͽṹ��Ҷ��������ʾ�������֦������ʾ��㣬
//			�û��ڴ�һ����������£����Է���ض���Ҷ�ӽ��з��ʡ�
//		����������������ý���ڵ�ǰ����ж�����һ��Ψһ�� ID����ͬ����е�����������ý�㣬
//			���Ծ�����ͬ�� ID�������ǵ� ID ȫ·������������ϵͳ����Ψһ�ġ�
//		�����  �����ͽṹ��Ҷ�ӣ�������������������
//		���ý�㣺�����ͽṹ��֦�������������ӽ�����Ȩ�޹�����Ҳ�߱��������ȫ������
//
//		ģ���ʹ�ã���ģ��Ϊ������DLL�������õ�������NewConfigObject�����һ�����ö���IConfig��
//					����IConfig�����ý��з��ʣ�ʹ��ReleaseConfigObject���ͷ�һ�����ö���
//	��    �ߣ�ZhangLingang
//	��д���ڣ�2004-3-11 10:49:07
//
//	�޸���ʷ�����¶�����д ���ݰ���������  �޸���  �޸�˵����
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __ICONFIG_H__
#define __ICONFIG_H__

#include "RSCFGDEF.H"

struct STCONFIGHEADER
{
	RS_DWORD dwFileFlag;				//�ļ���־
	RS_DWORD dwVersion;					//�����ļ��汾	
	RS_DWORD dwHeaderLen;				//�ļ�ͷ�ĳ���
	RS_DWORD dwFileLen;					//�ļ�����

	RS_DWORD dwReserved1;				//����1
	RS_DWORD dwReserved2;				//����2
	RS_DWORD dwReserved3;				//����3
	RS_DWORD dwReserved4;				//����4

	RS_DWORD dwProductID;				//��Ʒ��־ID
	RS_DWORD dwDataOffset;				//���ݵ���ʼƫ��	
	RS_DWORD dwCheckSum1;				//�ļ�У��ֵ1
	RS_DWORD dwCheckSum2;				//�ļ�У��ֵ2

	RS_CHAR  szProductName[16];			//��Ʒ����

	RS_CHAR  szCreateTime[20];			//��Ʒ����(4)
	RS_CHAR  szReleaseTime[20];			//����ʱ��
	RS_DWORD dwSHMLength;				//�����ڴ����ĳ���
	RS_DWORD dwPrivate;					//˽��

	RS_DWORD dwEncryptMethod;			//���ܷ���
	RS_DWORD dwEncryptKeyLen;			//��Կ���ȣ����ܳ���32
	RS_DWORD dwCompressMethod;			//ѹ������
	RS_DWORD dwCompressKeyLen;			//��ѹ�����ȣ����ܳ���32

	RS_BYTE  byEncryptKey[32];			//��Կ��(2)
	RS_BYTE  byCompressKey[32];			//��ѹ������(2)

	RS_CHAR  szFileName[320];			//�����ļ�����(20)
	RS_CHAR  szPrivateData[256];		//˽��������(16)
};

typedef struct STConfigItem
{
	RS_DWORD	m_dwId;				// ��� ID
	RS_DWORD	m_dwLevel;			// ���ļ�����������ʱ�˽��û��
	RS_DWORD	m_dwStatus;			// ����״̬������
	RS_DWORD	m_dwAccess;			// ����Ȩ��
	RS_DWORD	m_dwDataType;		// �洢����������
	RS_DWORD	m_dwDataLen;		// ���ݳ���
	RS_BYTE*	m_pData;			// ����ָ��
	RS_CHAR*	m_pName;			// ����ָ��
	RS_CHAR*	m_pMemo;			// ��עָ��
	RS_DWORD*	m_pdwUserId;		// �û�IDָ��
}*PSTConfigItem;

class IConfig
{
public:
	// ��ȫ·���������һ����㣬һ����㴴���ɹ�����Ȼ��
	// pdwIdPath: �˲���Ϊһ�� RS_DWORD ���飬��С����Ϊ 64��������ʾ��� ID ��ȫ·��, �� 0 Ϊ·���Ľ�����־.
	// dwAccess: �򿪻򴴽��˽��ʱ��Ҫ��Ȩ�ޣ�����ʱ��ʹ�� CONFIG_ACCESS_CREATE
	// pdwUserId: �û��� ID ��ʶ��UserId �ĳ�����ʹ���߶��壨һ��Ϊһ�� 128 λ�����ݣ�
	// �ɹ����� ERR_SUCCESS�����򷵻ش�����
	virtual RS_RESULT CreateNode(const RS_DWORD* pdwIdPath, RS_DWORD &dwAccess, const RS_DWORD* pdwUserId, IConfig** ppConfig) = 0;

	// �ر��Ѿ��򿪵Ľ��
	virtual RS_RESULT CloseNode() = 0;

	// ɾ�����
	virtual RS_RESULT DeleteNode() = 0;
	//����һ���������һ�����ý��
#ifdef FOR_TEST
	virtual RS_RESULT Create(PSTConfigItem pstItem, IConfig** ppConfig) = 0;
#endif
	virtual RS_RESULT Delete(RS_DWORD dwId) = 0;

	// ȡ�ý���ȫ·��
	// pdwPath: ȫ·���ķ��ؽ��
	virtual RS_RESULT GetNodePath(RS_DWORD* pdwPath, RS_DWORD& dwPathLen) = 0;

	// ����һ��������
	// dwItemId: �������ID
	virtual RS_RESULT CreateItem(RS_DWORD dwItemId) = 0;

	// ɾ��һ��������
	// dwItemId: �������ID
	virtual RS_RESULT DeleteItem(RS_DWORD dwItemId) = 0;

	// ��ȡһ���������ֵ
	// dwItemId: �������ID
	// pbyData: ���������
	// dwSize: ���ݵĳ���
	virtual RS_RESULT GetItemValue(RS_DWORD dwItemId, RS_BYTE* pbyData, RS_DWORD& dwSize) = 0;

	// ����һ���������ֵ
	// dwItemId: �������ID
	// pbyData: ���ݻ�����
	// dwSize: ���ݳ���
	virtual RS_RESULT SetItemValue(RS_DWORD dwItemId, RS_BYTE* pbyData, RS_DWORD& dwSize) = 0;

	virtual RS_RESULT GetItemValueBYTE(RS_DWORD dwItemId, RS_BYTE& byData) = 0;
	virtual RS_RESULT SetItemValueBYTE(RS_DWORD dwItemId, RS_BYTE byData) = 0;
	virtual RS_RESULT GetItemValueWORD(RS_DWORD dwItemId, RS_WORD& wData) = 0;
	virtual RS_RESULT SetItemValueWORD(RS_DWORD dwItemId, RS_WORD wData) = 0;
	virtual RS_RESULT GetItemValueDWORD(RS_DWORD dwItemId, RS_DWORD& dwData) = 0;
	virtual RS_RESULT SetItemValueDWORD(RS_DWORD dwItemId, RS_DWORD dwData) = 0;
	virtual RS_RESULT GetItemValueString(RS_DWORD dwItemId, RS_CHAR* pbyData, RS_DWORD& dwSize) = 0;
	virtual RS_RESULT SetItemValueString(RS_DWORD dwItemId, RS_CHAR* pbyData, RS_DWORD& dwSize) = 0;

	// ��ȡ���������ĸ�����Ϣ, dwItemId Ϊ IVALID_ITEMID ʱ��ʾ��ý�㱾�����Ϣ
	// dwItemId: ������ ID
	// dwInfoId: ��Ϣ�� ID
	// pbyBuffer: ��������ݻ�����
	// dwBufSize: ���ݻ�������С
	virtual RS_RESULT GetInfo(RS_DWORD dwItemId, RS_DWORD dwInfoId, RS_BYTE* pbyBuffer, RS_DWORD& dwBufSize) = 0;

	// �������������ĸ�����Ϣ, dwItemId Ϊ IVALID_ITEMID ʱ��ʾ��ý�㱾�����Ϣ
	// dwItemId: ������ ID
	// dwInfoId: ��Ϣ�� ID
	// pbyBuffer: ��������ݻ�����
	// dwBufSize: ���ݻ�������С
	virtual RS_RESULT SetInfo(RS_DWORD dwItemId, RS_DWORD dwInfoId, const RS_BYTE* pbyBuffer, RS_DWORD dwBufSize) = 0;
	
	// ʹ��ͬһ�� IConfig �����ȡ���ӽ��
	// dwId: ��� ID
	// dwAccess: �򿪻򴴽��˽��ʱ��Ҫ��Ȩ�ޣ�����ʱ��ʹ�� CONFIG_ACCESS_CREATE
	// pdwUserId: �û��� ID ��ʶ��UserId �ĳ�����ʹ���߶��壨һ��Ϊһ�� 128 λ�����ݣ�
	virtual RS_RESULT GetChildNode(RS_DWORD dwId, RS_DWORD dwAccess, const RS_DWORD* pdwUserId) = 0;

	// ��һ��������ĺ��ӽ�㣬���� IConfig ����ָ��
	// dwId: ��� ID
	// ppConfig: IConfig ����ָ��
	virtual RS_RESULT GetChildNode(RS_DWORD dwId, RS_DWORD &dwAccess, const RS_DWORD* pdwUserId, IConfig** ppConfig) = 0;

	// ʹ��ͬһ�� IConfig �����ȡ�ֵܽ��
	// dwId: ��� ID
	// dwAccess: �򿪻򴴽��˽��ʱ��Ҫ��Ȩ�ޣ�����ʱ��ʹ�� CONFIG_ACCESS_CREATE
	// pdwUserId: �û��� ID ��ʶ��UserId �ĳ�����ʹ���߶��壨һ��Ϊһ�� 128 λ�����ݣ�
	virtual RS_RESULT GetSiblingNode(RS_DWORD dwId, RS_DWORD dwAccess, const RS_DWORD* pdwUserId) = 0;
#ifdef FOR_TEST
	virtual RS_RESULT GetSiblingNode(RS_DWORD dwId, RS_DWORD &dwAccess, const RS_DWORD* pdwUserId, IConfig** ppConfig) = 0;
#endif
	//װ��һ�������ļ�,����һ�����ö���, ppConfig==RS_NULLʱ,�ö�����װ��
	virtual RS_RESULT LoadConfig(const RS_CHAR* pszFilename, IConfig** ppConfig = RS_NULL) = 0;
	//��1�����ö�����ӵ�������ö�����
	virtual RS_RESULT AddConfig(IConfig* pConfig) = 0;
	
	//�������ļ����뵽������ö�����
	//�ھ���Ȩ�޵������,��������ظ�����,����и��Ƕ���������ʾ
	virtual RS_RESULT Import(RS_CHAR *pszFileName) = 0;
	virtual	RS_RESULT ImportToRoot(RS_CHAR *pszFileName) = 0;
	//��������ö��󵼳���Ϊһ�������ļ�
	//�ھ���Ȩ�޵������,������ļ��Ѿ�����,�򸲸Ǵ��ļ�����������ʾ
	virtual RS_RESULT Export(RS_CHAR *pszFileName) = 0;
	virtual RS_RESULT ExportAll(RS_CHAR *pszFileName) = 0;
	//����һ��������
	//���dwId==INVALID_ITEMID,���ʾ�˶����㱾��
	virtual RS_RESULT Lock(RS_DWORD dwId) = 0;
	//����һ��������
	//���dwId==INVALID_ITEMID,���ʾ�˶����㱾��
	virtual RS_RESULT Unlock(RS_DWORD dwId) = 0;
	//����ͬ��
	virtual RS_RESULT Synchronize(RS_VOID *pParam = RS_NULL) = 0;


	//===========================���·������༭��ʹ��===========================
	virtual HITEM GetRoot() = 0;
	virtual HITEM GetSibling(HITEM hParent) = 0;
	virtual HITEM GetChild(HITEM hParent) = 0;
	
	virtual RS_RESULT Create(const RS_DWORD* pdwIdPath, PHITEM phItem, RS_DWORD &dwAccess, const RS_DWORD* pdwUserId) = 0;
	virtual RS_RESULT Close(PHITEM phItem) = 0;
	
	virtual RS_RESULT GetInfo(HITEM hItem, RS_DWORD& dwId, RS_DWORD& dwLevel, RS_DWORD& dwStatus, RS_CHAR* pszName, RS_CHAR* pszMemo) = 0;
	virtual RS_RESULT SetInfo(HITEM hItem, RS_DWORD dwId, RS_DWORD dwLevel, RS_DWORD dwStatus, RS_CHAR* pszName, RS_CHAR* pszMemo) = 0;
	virtual RS_RESULT GetValue(HITEM hItem, RS_DWORD& dwDataType, RS_BYTE* pbyData, RS_DWORD& dwSize) = 0;
	virtual RS_RESULT SetValue(HITEM hItem, RS_DWORD dwDataType, RS_BYTE* pbyData, RS_DWORD dwSize) = 0;		
	virtual RS_RESULT GetMemo(HITEM hItem, RS_CHAR* pszMemo) = 0;
	virtual RS_RESULT SetMemo(HITEM hItem, RS_CHAR* pszMemo) = 0;
	virtual RS_BOOL Save(HITEM hItem) = 0;
	virtual RS_DWORD DeleteNode(HITEM hItem) = 0;
	//�������к�ȡ�ò�ƷID������lPrtIDΪ-1����ȡ����Ӧ���к������Ժ�Ĳ�ƷID��������ԭʼ��ƷID��
	virtual RS_RESULT GetProductID(RS_CHAR *pszSN, RS_LONG &lPrtID) = 0;
	virtual RS_RESULT GetConfigHeader(RS_DDWORD &dwHeaderAddr) = 0;
	virtual RS_RESULT QueryUser(RS_DWORD *pUserID) = 0;
};

#endif // __ICONFIG_H__
