#include "Stdafx.h"

/*
struct STUSERACCESS				// Ȩ�޺͵ȼ����սṹ
{
	RS_DWORD dwAccess;			// Ȩ��ֵ
	RS_DWORD dwItemLevel;		// ��Ҫ�����Ŀ�ȼ�
};

// �û� ID ��
const RS_DWORD g_adwUserTable[USER_NUMBER][RS_USERID_LEN] = 
{
	{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF},
	{0xFFFFFFFF, 0, 0, 1},		//��װ����
	{0xFFFFFFFF, 0, 0, 2},		//������
	{0, 0, 0, 0}
};

// �û�Ȩ������Ŀ�ȼ��Ķ��ձ�
const STUSERACCESS g_astUserAccess[USER_NUMBER][ACCESS_NUMBER] =
{
	{
		{CONFIG_ACCESS_READ,	1},
		{CONFIG_ACCESS_WRITE,	1},
		{CONFIG_ACCESS_CREATE,	1},
		{CONFIG_ACCESS_DELETE,	1},
		{CONFIG_ACCESS_IMPORT,	1},
		{CONFIG_ACCESS_EXPORT,	1},
		{CONFIG_ACCESS_LOCK,	1},
		{CONFIG_ACCESS_UNLOCK,	1},
		{CONFIG_ACCESS_CREATETMP,	1},
		{CONFIG_ACCESS_QUERY,	1},
		{CONFIG_ACCESS_SHARE,	1}
	},
	{
		{CONFIG_ACCESS_READ,	1},
		{CONFIG_ACCESS_WRITE,	1},
		{CONFIG_ACCESS_CREATE,	1},
		{CONFIG_ACCESS_DELETE,	5},
		{CONFIG_ACCESS_IMPORT,	1},
		{CONFIG_ACCESS_EXPORT,	1},
		{CONFIG_ACCESS_LOCK,	1},
		{CONFIG_ACCESS_UNLOCK,	1},
		{CONFIG_ACCESS_CREATETMP,	1},
		{CONFIG_ACCESS_QUERY,	1},
		{CONFIG_ACCESS_SHARE,	1}
	},
	{
		{CONFIG_ACCESS_READ,	4},
		{CONFIG_ACCESS_WRITE,	4},
		{CONFIG_ACCESS_CREATE,	4},
		{CONFIG_ACCESS_DELETE,	2},
		{CONFIG_ACCESS_IMPORT,	1},
		{CONFIG_ACCESS_EXPORT,	1},
		{CONFIG_ACCESS_LOCK,	1},
		{CONFIG_ACCESS_UNLOCK,	1},
		{CONFIG_ACCESS_CREATETMP,	1},
		{CONFIG_ACCESS_QUERY,	1},
		{CONFIG_ACCESS_SHARE,	1}
	},
	{
		{CONFIG_ACCESS_READ,	2},
		{CONFIG_ACCESS_WRITE,	2},
		{CONFIG_ACCESS_CREATE,	2},
		{CONFIG_ACCESS_DELETE,	2},
		{CONFIG_ACCESS_IMPORT,	1},
		{CONFIG_ACCESS_EXPORT,	1},
		{CONFIG_ACCESS_LOCK,	1},
		{CONFIG_ACCESS_UNLOCK,	1},
		{CONFIG_ACCESS_CREATETMP,	1},
		{CONFIG_ACCESS_QUERY,	1},
		{CONFIG_ACCESS_SHARE,	1}
	}
};

// ȡ��һ���ȼ�����Ŀ����Ӧ��Ȩ��
RS_RESULT GetUserAccess(const RS_DWORD* pdwUser, RS_DWORD dwItemLevel, RS_DWORD& dwAccess)
{
	if(pdwUser == NULL)
		return ERR_FAILED;

	for(int i=0; i<USER_NUMBER; i++)
	{
		if(memcmp(g_adwUserTable[i], pdwUser, sizeof(RS_DWORD) * RS_USERID_LEN) == 0)
			break;
	}

	if(i == USER_NUMBER)	// ��ʾû���ҵ����û�
		return ERR_CFG_USER_NOTFOUND;

	dwAccess = 0;
	for(int j=0; j<ACCESS_NUMBER; j++)
	{
		if(g_astUserAccess[i][j].dwItemLevel <= dwItemLevel)
			dwAccess |= g_astUserAccess[i][j].dwAccess;
	}

	return ERR_SUCCESS;
}
*/