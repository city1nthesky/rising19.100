#ifndef __RsLogX_H__
#define __RsLogX_H__


#include <string>
#include <map>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


#ifdef WIN32
#include <windows.h>
#include <atlstr.h>
#else
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#endif


#ifndef Assert
	#include <assert.h>
	#define Assert   assert
#endif

#ifndef FORMAT_ARGS_STRING
	#define FORMAT_ARGS_STRING(_buf, _fmt) \
		va_list args; \
		va_start(args, _fmt); \
		int _slen = strlen(_buf), _nlen = sizeof(_buf) - _slen - 3; \
		vsnprintf(_buf + _slen, _nlen, _fmt, args); \
		va_end(args);
#endif

#ifndef LOG_LINEND
	#define LOG_LINEND                           "\r\n"
#endif


inline void GetProcessFileName(char * szFileName, int nSize)
{
	Assert(szFileName);
	Assert(nSize > 0);

	#ifdef WIN32
		// 在 windows中使用 ansi处理不了特殊的路径. 转换成 utf8. 
		wchar_t szProcPath[MAX_PATH] = {0};
		GetModuleFileNameW(0, szProcPath, _countof(szProcPath));
		if(szProcPath[0]) strcpy(szFileName, CW2A(szProcPath, CP_UTF8));
	#else
		int nRet = readlink("/proc/self/exe", szFileName, nSize - 1);
		if(nRet > 0 && nRet < nSize) szFileName[nRet] = 0;
	#endif
}

inline int  GetProcessId()
{
	#ifdef WIN32
		return GetCurrentProcessId();
	#else
		return getpid();
	#endif
}

inline int  GetThreadId()
{
	#ifdef WIN32
		return GetCurrentThreadId();
	#else
		return (int)(intptr_t)pthread_self();
	#endif
}

inline void GetNowTime(char * szTime, int nSize)
{
	time_t now;
	struct tm *curtime;		
	time(&now);
	curtime = localtime(&now);
	strftime(szTime, nSize, "%Y-%m-%d %H:%M:%S", curtime);
}


enum enumLogType
{ 
	LogType_No       = 0, 
	LogType_ProcInfo = 0x01, 
	LogType_Time     = 0x02, 
	LogType_LineEnd  = 0x04, 
	LogType_StdOut   = 0x08, 
	LogType_Default  = LogType_ProcInfo | LogType_Time | LogType_LineEnd | LogType_StdOut, 
};


class CLogF
{
public:
	static CLogF * GetInstance()
	{
		static CLogF g_logf;
		return &g_logf;
	}


	FILE * Open(const char * szName, const char * szMode = "a", int nMaxFileSizeKB = 0, int nType = 0)
	{
		std::string strFileName;

		if(!(nType & 0x1)) strFileName = m_md; strFileName += szName;
		if(nType & 0x2)  { char tmp[32] = {0}; sprintf(tmp, ".%d.log", GetProcessId()); strFileName += tmp; }

		std::map<std::string, FILE*>::const_iterator it = m_pfs.find(strFileName);
		if(it == m_pfs.end())
		{
			extern int errno;
			FILE * pf  = OpenFileImpl(strFileName.c_str(), szMode, nMaxFileSizeKB); 
			int nError = errno; Assert(pf);
			m_pfs.insert(std::make_pair(strFileName, pf));
			return pf;
		}

		return it->second;
	}

	void Log(int nLevel, int nType, FILE * pf, const char* szFormat, ...)
	{
		Assert(pf);
		if(!pf) return ;

		char szLogBuffer[1024] = {0};
		if(nType & LogType_Time)
		{
			char       szTime[32] = {0};
			GetNowTime(szTime, sizeof(szTime));
			sprintf(szLogBuffer, "%s", szTime);
		}

		if(nType & LogType_ProcInfo)
		{
			sprintf(szLogBuffer + strlen(szLogBuffer), "<%4d, %4u> ", GetProcessId(), GetThreadId());
		}

		FORMAT_ARGS_STRING(szLogBuffer, szFormat);
		if(nType & LogType_LineEnd) strcat(szLogBuffer, LOG_LINEND);

		fseek(pf, 0, SEEK_END);
		fwrite(szLogBuffer, strlen(szLogBuffer), 1, pf);
		if(nType & LogType_StdOut) printf(szLogBuffer);
		fflush(pf);
	}


private:
	CLogF()
	{
		char szModule[1024] = {0};
		GetProcessFileName(szModule, sizeof(szModule));
		m_md = szModule;
	}

	~CLogF()
	{
		for(std::map<std::string, FILE*>::const_iterator it = m_pfs.begin(); 
			it != m_pfs.end(); it++)
		{
			fclose(it->second);
		}
		m_pfs.clear();
	}

	FILE * OpenFileImpl(const char * szFileName, const char * szMode, int nMaxSizeKB)
	{
		FILE * pf = fopen(szFileName, szMode);

		char szTmp[16] = {0};
		strcpy(szTmp, szMode);
		char * p = strchr(szTmp, 'a');

		if(pf && p && nMaxSizeKB > 0)
		{
			nMaxSizeKB *= 1024;
			fseek(pf, 0, SEEK_END);
			int nLen = (int)ftell(pf);
			if(nLen > nMaxSizeKB)
			{
				*p = 'w';
				fclose(pf);
				pf = fopen(szFileName, szTmp);
			}
		}

		return pf;
	}


private:
	std::map<std::string, FILE*>   m_pfs;
	std::string                    m_md;
};


#ifndef LOGF_NAME
	#define LOGF_NAME                            ".def.log"
#endif

#ifndef LOGF_MODE
	#define LOGF_MODE                            "wbc"
#endif

#ifndef LOGF_DEFAULT_SIZE
	#define LOGF_DEFAULT_SIZE                    0
#endif

#ifndef LOGF_TYPE
	#define LOGF_TYPE                            LogType_Default
#endif

#define LOGF_PATH_ABSOLUTE                       1
#define LOGF_PATH_PROCID                         2
#ifndef LOGF_CREATE_PATH
	#define LOGF_CREATE_PATH                     0
#endif

#define LOGF_IMPL                                Log
#define LOG_PF                                   CLogF::GetInstance()
#define LOG_FILE                                 LOG_PF->Open(LOGF_NAME, LOGF_MODE, LOGF_DEFAULT_SIZE, LOGF_CREATE_PATH)


#ifdef __RSLOG_ENABLE__
	#ifdef WIN32
		#define LOG_FLOG(_level, _fmt, ...)      LOG_PF->LOGF_IMPL(_level, LOGF_TYPE, LOG_FILE, _fmt, __VA_ARGS__)
	#else
		#define LOG_FLOG(_level, _fmt, args...)  LOG_PF->LOGF_IMPL(_level, LOGF_TYPE, LOG_FILE, _fmt, ##args)
	#endif
#else
	#ifdef WIN32
		#define LOG_FLOG(...)                    
	#else
		#define LOG_FLOG(args...)                
	#endif
#endif


// 使用说明: 
// 
// #define LOGF_NAME    ".xxx.log"
// #include "rslogx.h"
// #define RSLOGX       LOG_FLOG
// RSLOGX(0, "%s", "this is a test");
// 


#endif  // __RsLogX_H__
