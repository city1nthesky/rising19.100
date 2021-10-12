#ifndef __RX_RUN_TIME__
#define __RX_RUN_TIME__

#include "rxiface.h"

// COM
HRESULT STDAPICALLTYPE RoCreateInstanceNCT( LPCSTR progid, IUnknown* outer, REFIID riid, void** ppv, IUnknown* rot = 0 );
HRESULT STDAPICALLTYPE RoCreateInstance( TCLSIDREF rclsid, IUnknown* outer, REFIID riid, void** ppv, IUnknown* rot = 0 );
HRESULT STDAPICALLTYPE RoCreateInstanceEx( TCLSIDREF rcatid, DWORD idcls, IUnknown* outer, REFIID riid, void** ppv, IUnknown* rot = 0 );
HRESULT STDAPICALLTYPE RoRegisterClass( TCLSIDREF rclsid, HMODULE hModule );
HRESULT STDAPICALLTYPE RoRevokeClass( TCLSIDREF rclsid );
// Variant
HRESULT STDAPICALLTYPE RoSetVariant( PROPVARIANT* propOut, const PROPVARIANT*  propIn );
HRESULT STDAPICALLTYPE RoClearVariant( PROPVARIANT* propIn );
// MSS Lib
HRESULT STDAPICALLTYPE MssLoadLibFile( LPCSTR wFileName, IMssLibFile** ppLibFile, IUnknown* prot );

HRESULT STDAPICALLTYPE MssLoadLibFile2W( LPCWSTR wFileName, LPCSTR aObNamePrefix, IMssLibFile** ppLibFile, IUnknown* prot );

HRESULT STDAPICALLTYPE MssLoadLibFile2( LPCSTR wFileName, LPCSTR aObNamePrefix, IMssLibFile** ppLibFile, IUnknown* prot );

enum  LOADOPTS
{
	MSFLOAD_DIRECT		= 1,		// ֱ��ʹ���ļ����أ����ļ������ǲ�ѹ���ģ����ļ�����
	MSFLOAD_EXCLUSIVE	= 2,		// ����MSFLOAD_DIRECT���д�λ�������Զ�ռ��ʽ�򿪿��ļ�
};

typedef struct MSF_LOAD_PARAM
{
	SIZE_T		cbStruct;
	LPCSTR		aFileName;			// ԭʼ�������ļ�����·��
	LPCSTR		aDriectFile;		// �������ֱ�Ӽ��ص�Ӱ���ļ�����ѹ����
									// ��ָ��������£�ʹ��aFileName�����ڴ�Ӱ���ļ������
									// ָ����ʹ�ø��ļ����أ����������VCCB
									// ���ʹ����aShadowFile���أ���VCCB����ʱ����
	IUnknown*	oLibCallback;		// 
	IUnknown*	oObjTable;			// 
	LPCSTR		aObNamePrefix;		// Mutex/Section... Name-Prefix

	OUT	BOOL	aDirectFileUsed;	// 
} MLPARAM, *LPMLPARAM;

HRESULT STDAPICALLTYPE MssLoadLibFileEx( LPMLPARAM lpParam, IMssLibFile** ppLibFile );

HRESULT STDAPICALLTYPE MssCreateInstance( TCLSIDREF rclsid, IUnknown* outer, REFIID riid, void** ppv, IUnknown* rot );

HANDLE	STDAPICALLTYPE MssCreateMutexOfFile( LPCWSTR wFileName, BOOL bInitOwner, LPSECURITY_ATTRIBUTES psa );

HRESULT STDAPICALLTYPE MssSetCacheSize( SIZE_T uCacheBytes );

// 2010
HRESULT STDAPICALLTYPE REInitROT10( IREROT* lpROT, ILibLoader* lpLibLoader, IREProperty2** ppConfig );
EXTERN_C HRESULT STDAPICALLTYPE RECreateInstance( REFCLSID clsid, IUnknown* outer, REFIID riid, void ** ppv, IUnknown* prot );
// Home
LPCSTR	STDAPICALLTYPE RxHome();		// return rxtuntim path
LPCWSTR	STDAPICALLTYPE RxHomeW();		// return rxtuntim path
VOID	STDAPICALLTYPE RxSetHome( LPCSTR aHome );

void STDAPICALLTYPE memleak_check_begin(LPCSTR name);
void STDAPICALLTYPE memleak_check_end(LPCSTR name);
#endif