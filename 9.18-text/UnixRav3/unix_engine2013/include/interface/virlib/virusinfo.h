#ifndef __rsvirusinfo_h__2007_5_29__19H52M25S
#define __rsvirusinfo_h__2007_5_29__19H52M25S

//������Ϊ���Ͷ���			
#define ACTION_VIRUS		1	//��������������������Ϊ virus �ļ�¼
#define ACTION_WORM			2	//��棺��������������Ϊ worm �ļ�¼
#define ACTION_ROOTKIT		3	//rookit���ߣ���������������Ϊ rookit�ļ�¼
#define ACTION_ADWARE		4	//�����򣺲�������������Ϊ adware �ļ�¼
#define ACTION_TROJAN		5	//ľ����������������Ϊ backdoor trojan dropper binder hack constructor harm pack jock junk    �ļ�¼
#define ACTION_BACKDOOR		6	//���ţ���������������Ϊ backdoor  �ļ�¼
#define ACTION_SUSPICOUS	7	//���ɣ�

typedef union _UNION_ACTION
{
	struct  
	{
#ifdef RS_BIG_ENDIAN
		BYTE Reserved:1;		//����λδʹ��
		BYTE IsHide:1;			//�Ƿ����أ�0��ʾ��1���ء�
		BYTE SusLevel:2;		//�Ƿ�����ɨ���ж����Ĳ�����0��������¼��1�ͼ�������¼��2�м�������¼��3�߼�������¼
		BYTE VirusActType:4;	//������Ϊ����
#else
		BYTE VirusActType:4;	//������Ϊ����
		BYTE SusLevel:2;		//�Ƿ�����ɨ���ж����Ĳ�����0��������¼��1�ͼ�������¼��2�м�������¼��3�߼�������¼
		BYTE IsHide:1;			//�Ƿ����أ�0��ʾ��1���ء�
		BYTE Reserved:1;		//����λδʹ��
#endif
	};
	BYTE bValue;
	
}UNION_ACTION;
struct STRsVirusInfo
{
	DWORD			dwVirusID;			//������¼��ID
	BYTE			byVirusType;		//��������
	UNION_ACTION	uiVirusActType;		//������Ϊ����
	CHAR			szVirusName[64];	//������
	CHAR			szAliasName[32];	//��������
};

#endif // __rsvirusinfo_h__
