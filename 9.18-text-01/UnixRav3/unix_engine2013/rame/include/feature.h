#ifndef __FEATURE_H__
#define __FEATURE_H__

/********************************************************************************/
//������Ȩ��֤����
//#define	ENABLE_CERTIFICATION
#ifdef ENABLE_CERTIFICATION
	
	//�������֤�鶼�Ǽ��ܵ�
	//�ڲ����ܲ���ʱ����ʹ������֤�飬��ֹ��ع�����й
	#define	USE_ENCRYPT_CERTIFICATION
#endif


//�¹��ܲ��Կ��أ���̨�Զ�����rush����ʱ�ᶨ��˺�
#define RUSH_TESTING_FALG	0


#define MASK_VIRUS_NAME		0


#define	ONLY_SCAN_VIRUS		0

#define COMPRESS_PACKAGE_BOMB_CHECK	1

// use memory or not when loadling viruslib on linux
#define USE_MEMORY_RATHER_THAN_FILE 0


//���ش���δѹ���Ĳ�����
//1> �����������δѹ����  2> ��֧��������
//#define	LOAD_HUGE_UNCOMPRESS_MALWARE_MODE


//������ʹ��rxsecns�е������棬����ʹ��cloundcom
//#define ENABLE_CAV_RXSECNS
//#define ENABLE_CAV_ZDR17

/************************************ Algorithm Setting ***********************************/

//����һ��lzmaprop.dc�Ĵ�С����ֹ���������ڴ�
#define LZMA_MAX_DC_SIZE			(256 * 1024 * 1024)	

/************************************* Archive Setting ************************************/

/************************************** 250 platform **************************************/

//���ø�ʽ���˹���
#define	ENABLE_PROCESS_FILETER

//������ʹ�ÿɻ����ļ�ϵͳ������ʹ��ԭ�ļ�ϵͳ
#define USE_REVOKE_VFILE_SYSTEM


#endif //__FEATURE_H__
