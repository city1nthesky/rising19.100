#ifndef __IRSVIRUSINFOTABLE_H__
#define __IRSVIRUSINFOTABLE_H__

#include "./irstable.h"
#include "./virusinfo.h"

//----------------------------------------------------------------------------------


class IREVirusInfoLib : public IUnknown
{
public:
	RE_DECLARE_IID;

	//���ݲ���IDȡ������Ϣ
	STDMETHOD(GetVirusInfo) (DWORD dwVirusID,	STRsVirusInfo* pstRsVirusBaseInfo) PURE ;

	//���ݲ������Ͳ�������ȡ������Ϣ
	STDMETHOD(GetVirusInfo) (LPSTR lpszVirusName,BYTE byVirusType,STRsVirusInfo* pstRsVirusBaseInfo) PURE;

	//���ݲ�����ȡ����ID�����ص�ID����pdwVirusArray���棬
	//dwIDCount�ǳ���Ρ�
	//��dwIDCount=0ʱ���������سɹ���dwIDCountΪ���ϲ����������ĸ���
	STDMETHOD(GetVirusID) (LPSTR lpszVirusName, DWORD* pdwVirusArray, DWORD& dwIDCount) PURE ;

	//ȡ��󲡶�ID
	STDMETHOD_(DWORD, GetMaxVirusID) () PURE ;

	//���ݲ������Ͳ�������ȡ������Ϣ
	STDMETHOD(GetVirusInfo) (DWORD dwVirusID, IREArchive* pArchive, STRsVirusInfo* pstRsVirusBaseInfo) PURE;
};

RE_DEFINE_IID(IREVirusInfoLib, "{358E7ADD-DC05-48e7-A3D3-D858D6C0B142}",
			0x358e7add, 0xdc05, 0x48e7, 0xa3, 0xd3, 0xd8, 0x58, 0xd6, 0xc0, 0xb1, 0x42);

class IEnumVirusInfo : public IUnknown
{
public:
	RE_DECLARE_IID;
	virtual HRESULT GetCountOfVirusInfoItems( PDWORD pdwItemCount ) = 0;
	virtual HRESULT GetVirusInfoByItemID( DWORD dwItem, STRsVirusInfo* pstRsVirusBaseInfo ) = 0;
};

RE_DEFINE_IID( IEnumVirusInfo, "{BF3DEA53-E81A-435b-A823-724D6935DD33}",
			0xbf3dea53, 0xe81a, 0x435b, 0xa8, 0x23, 0x72, 0x4d, 0x69, 0x35, 0xdd, 0x33);


//====================================================================================
// {77918387-59E1-4f6f-A8EF-FD4B055612A8}
DEFINE_GUID(CLSID_CREVirusInfoLib, 
			0x77918387, 0x59e1, 0x4f6f, 0xa8, 0xef, 0xfd, 0x4b, 0x5, 0x56, 0x12, 0xa8);










#endif // __IVirusInfo_h__



