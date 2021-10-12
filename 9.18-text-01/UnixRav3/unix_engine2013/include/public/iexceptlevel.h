#ifndef __RSENGINE_EXCEPTION_LEVEL_INTERFACE_H__
#define __RSENGINE_EXCEPTION_LEVEL_INTERFACE_H__


/*********
*  ���������쳣����
*********/
enum EXCEPTION_LEVEL_FIELD
{
	ELF_bEnableTraceDJ = 1,
	ELF_bAPIAsException = 2,
	ELF_bNullLoopAsException = 4,
	ELF_dwExceptionLimit = 8
};
typedef struct tagSTEXCEPTIONLEVEL
{
	DWORD dwValidFieldMask;     //��Ч���־��enum TRACE_RESULT��
	BOOL  bEnableTraceDJ;       //�Ƿ���ٽ��ܡ���ת
	BOOL  bAPIAsException;      //�ж�ָ���API�����Ƿ����쳣
	BOOL  bNullLoopAsException; //��ѭ���Ƿ����쳣
	DWORD dwExceptionLimit;     //��������쳣��
}STEXCEPTIONLEVEL;


#endif // #ifndef __RSENGINE_EXCEPTION_LEVEL_INTERFACE_H__
