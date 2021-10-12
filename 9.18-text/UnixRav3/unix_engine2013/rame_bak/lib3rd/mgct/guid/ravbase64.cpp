// RavBase64.cpp: implementation of the CRavBase64 class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "RavBase64.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#ifndef	ERROR_WRONGCHARCODE
#define ERROR_WRONGCHARCODE	-1
#endif

#ifndef ERROR_EXCEPTION
#define ERROR_EXCEPTION		-2
#endif

CRavBase64::CRavBase64()
{
	InitialBaseTable();
}

CRavBase64::~CRavBase64()
{

}

////////////////////////////////////////////////////////////////////////////////
//	�������ƣ�void InitialBaseTable()
//	ʵ�ֹ��ܣ���ʼ��Base64��Ӧ��
//	��ȫ�ֱ�����Ӱ�죺��
//	����˵������
//	���ؽ��˵����
////////////////////////////////////////////////////////////////////////////////
void CRavBase64::InitialBaseTable()
{
	int nPos = 0;
	int i = 0;
	for(i = 0;i < 26;i ++)
		chBaseTable[nPos++]  = static_cast<char>(0x41 + i);
	for(i = 0;i < 26;i ++)
		chBaseTable[nPos++]  = static_cast<char>(0x61 + i);
	for(i = 0;i < 10;i ++)
		chBaseTable[nPos ++] = static_cast<char>(0x30 + i);
	chBaseTable[nPos ++] = 0x2b;
	chBaseTable[nPos] = 0x2f;
}

////////////////////////////////////////////////////////////////////////////////
//	�������ƣ�int EncodeBase64(
//				char * chInBuf,
//				char *chOutBuf,
//				int nInLen ) 
//	ʵ�ֹ��ܣ���Base64��ʽ����
//	��ȫ�ֱ�����Ӱ�죺��
//	����˵����
//		chInBuf				�봮
//		chOutBuf			����
//		nInLen				�봮����
//	���ؽ��˵�������ش�����,-1Ϊԭ������ȷ,-2Ϊϵͳ���������Ǵ����ڴ�������
////////////////////////////////////////////////////////////////////////////////
int CRavBase64::EncodeBase64(char * chInBuf, char *chOutBuf , int nInLen /* = 0 */)
{
	try
	{
		if(!nInLen)
			nInLen = strlen(chInBuf);
		if(nInLen < 1)
		{
			chOutBuf[0] ='\0';
			return 0;
		}
		else
		{
			int nFree = 0;
			int nInPos = 0 , nOutPos = 0;
			int nValue = 0;
			do
			{
				
				if(nFree >= 6)
				{
					chOutBuf[nOutPos ++] = chBaseTable[(nValue >> (nFree - 6)) & 0x3f];
					nFree -= 6;
				}
				else
				{
					if(nInPos < nInLen)
					{
						nFree += 8;
						nValue <<= 8;
						nValue += (unsigned char)chInBuf[nInPos ++];
					}
					else
					{
						if(nFree > 0)
							chOutBuf[nOutPos ++] = chBaseTable[(nValue << (6 - nFree))&0x3f];
						break;
					}
				}
			}while(true);
			chOutBuf[nOutPos] = '\0';
			return nOutPos;
		}
	}
	catch(...)
	{
		return ERROR_EXCEPTION;
	}
}

#define DBASE64(a) (a>='A' && a<='Z')?a-'A': \
                   (a>='a'&&a<='z')?(a-'a')+26: \
                   (a>='0'&&a<='9')?(a-'0')+52: \
                   (a=='+')?(62):(a=='/')?(63): -1

////////////////////////////////////////////////////////////////////////////////
//	�������ƣ�int DecodeBase64(
//				char * chInBuf,
//				char *chOutBuf ) 
//	ʵ�ֹ��ܣ���Base64��ʽ����
//	��ȫ�ֱ�����Ӱ�죺��
//	����˵����
//		chInBuf				���봮
//		chOutBuf			�����
//	���ؽ��˵�������ش�����,-1Ϊԭ������ȷ,-2Ϊϵͳ���������Ǵ����ڴ�������
////////////////////////////////////////////////////////////////////////////////
int CRavBase64::DecodeBase64(char * chInBuf, char *chOutBuf)
{
	try
	{	
		int nInLen = strlen(chInBuf);
		if(nInLen < 1)
		{
			chOutBuf[0] = '\0';
			return 0;
		}
		else
		{
			int nValue = 0;
			int nFree = 0;
			int nInPos = 0 , nOutPos = 0;
			do
			{
				if(nFree >= 8)
				{
					chOutBuf[nOutPos ++] = static_cast<char>(nValue >> (nFree - 8));
					nFree -= 8;
				}
				else
				{
					if(nInPos < nInLen)
					{
						nValue <<= 6;
						int nTempValue = DBASE64((unsigned int)chInBuf[nInPos]);
						if(nTempValue < 0)
							return ERROR_WRONGCHARCODE;
						else
						{
							nValue |= nTempValue & 0x3f;
							nFree += 6;
							nInPos ++;
						}
					}
					else
						break;
				}
			}while(true);
			chOutBuf[nOutPos] = '\0';
			return nOutPos;
		}
	}
	catch(...)
	{
		return ERROR_EXCEPTION;
	}
}

////////////////////////////////////////////////////////////////////////////////
//	�������ƣ�int EncodeLen( int nLen ) 
//	ʵ�ֹ��ܣ�������ܺ�Ĵ�����(������������)
//	��ȫ�ֱ�����Ӱ�죺��
//	����˵����
//		nLen				ԭ����
//	���ؽ��˵�������ش���
////////////////////////////////////////////////////////////////////////////////
int CRavBase64::EncodeLen(int nLen)
{
	return (nLen / 3) * 4 + ((nLen % 3) ? (nLen % 3 + 1) : 0);
}

////////////////////////////////////////////////////////////////////////////////
//	�������ƣ�int DecodeLen( int nLen ) 
//	ʵ�ֹ��ܣ�������ܺ�Ĵ�����(������������)
//	��ȫ�ֱ�����Ӱ�죺��
//	����˵����
//		nLen				ԭ����
//	���ؽ��˵�������ش���
////////////////////////////////////////////////////////////////////////////////
int CRavBase64::DecodeLen(int nLen)
{
	return (nLen / 4) * 3 + ((nLen % 4) ? (nLen % 4 - 1) : 0);
}
