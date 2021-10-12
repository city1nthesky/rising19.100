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

//
//�ƿ���  0:close, 1:open
//
#define ZDR_HTTP_CLIENT_FLAG		1

#define USE_ZSTD_LIBRARY	1


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

//////////////////////////////////////////////////////////////////////////
//1��ʾʹ�ö��߳������ļ�ϵͳ��0��ʾ�ɻ����ļ�ϵͳ
//
#define USE_VIRTFILE_V2							1


/************************************** Virtual File System **************************************/

#define DEFAULT_MEM_BLOCK_SIZE					0x1000

#define _1K										1024
#define _1M										(1024UL * _1K)

#define DEFAULT_AVAILABLE_MEM_SIZE				(255ULL * _1M)
#define MAX_AVAILABLE_MEM_SIZE					(888ULL * _1M)
#define MIN_AVAILABLE_MEM_SIZE					(40UL * _1K)
#define DEFAULT_RESIDENT_MEM_SIZE				(5ULL * _1M)
#define MAX_RESIDENT_MEM_SIZE					(1000ULL * _1M)

#if USE_VIRTFILE_V2
#define DEFAULT_TOTAL_MEM_SIZE					(256ULL * _1M)
#define MAX_TOTAL_MEM_SIZE						(1024ULL * _1M)
#define DEFAULT_REISDENT_MEM_SIZE				(4ULL * _1M)
#define MAX_REISDENT_MEM_SIZE					(256ULL * _1M)
#endif


#endif //__FEATURE_H__
