#ifndef __RE_LIBLOADER_CONFIG_H__
#define __RE_LIBLOADER_CONFIG_H__

//�����ͺ���������Ӱ���ϵ��ṹ
struct ST_IndexObject_Map
{
	UINT32 dwType;
	CLSID clsid;
};
//���ļ�
struct ST_IndexLibFile_Map
{
	UINT32	dwLibFile;		//���ļ����
	CHAR	lpszFileName[0x20];	//���ļ���
};

//��洢
struct ST_IndexLibStore_MAP
{
	UINT32	dwLibType;		//����������
	UINT32	dwLibFile;		//���ļ����
};

//09PE���������Ӧ���ӿ�����
struct ST_IndexCompilerLibType_MAP
{
	UINT16	wCompiler;			//������ID
	UINT32	dwFCLibType;		//FC����������
	UINT32	dwNormalLibType;	//Normal����������
};

#endif
