#ifndef	__RS_PLATFORM_DEFINE__
#define __RS_PLATFORM_DEFINE__

//////////////////////////////////////////////////////////////////////////

#define  POSSIBLE_EXCEPT_STREAM_MAX_SIZE			0x3200000	//1024*1024*50

// OS
//#define		TARGET_WINDOWS
//#define		TARGET_POSIX

// Bits
//#define		TARGET_64BIT
//#define		TARGET_32BIT

// ByteEndian
//#define		TARGET_BBE
//#define		TARGET_LBE

// arch
//#define		TARGET_ARCH_X86
//#define		TARGTE_ARCH_NOT_X86

#if defined(BUILD_FOR_X86_WINDOWS_32)
#	define	TARGET_WINDOWS
#	define	TARGET_32BIT
#	define	TARGET_ARCH_X86
#	define	TARGET_LBE
#elif defined(BUILD_FOR_X86_WINDOWS_64)
#	define	TARGET_WINDOWS
#	define	TARGET_64BIT
#	define	TARGET_ARCH_X86
#	define	TARGET_LBE
#elif defined(BUILD_FOR_X86_POSIX_32)
#	define	TARGET_POSIX
#	define	TARGET_32BIT
#	define	TARGET_ARCH_X86
#	define	TARGET_LBE
#elif defined(BUILD_FOR_X86_POSIX_64)
#	define	TARGET_POSIX
#	define	TARGET_64BIT
#	define	TARGET_ARCH_X86
#	define	TARGET_LBE
#endif

//#define		TARGET_BBE
//////////////////////////////////////////////////////////////////////////

#define 	OS_WINDOWS				0
#define 	OS_NATIVE				2
#define 	OS_POSIX				6

#define 	CC_MSVC					0
#define 	CC_GCC					1

#define 	BYTE_ENDIAN_L			0
#define 	BYTE_ENDIAN_B			1

#define 	ARCH_32BIT				32
#define 	ARCH_64BIT				64

#define		TARGET_X86				0
#define		TARGET_NOT_X86			1
#define		TARGET_X64				2

//////////////////////////////////////////////////////////////////////////
/*
	#define		TARGET_OS
	#define		TARGET_ENDIAN
	#define		TARGET_BITS
	#define		CPP_COMPILER
*/

//////////////////////////////////////////////////////////////////////////

#ifdef TARGET_WINDOWS
#define TARGET_OS		OS_WINDOWS
#elif defined(TARGET_POSIX)
#define TARGET_OS		OS_POSIX
#endif

#if defined(TARGET_64BIT)
#define TARGET_BITS		ARCH_64BIT
#elif defined(TARGET_32BIT)
#define TARGET_BITS		ARCH_32BIT
#endif

#if defined(TARGET_BBE)
#define TARGET_ENDIAN	BYTE_ENDIAN_B
#elif defined(TARGET_LBE)
#define TARGET_ENDIAN	BYTE_ENDIAN_L
#endif

#ifdef TARGET_ARCH_X86
#	if TARGET_BITS == ARCH_64BIT
#		define TARGET_ARCH		TARGET_X64
#	else 
#		define TARGET_ARCH		TARGET_X86
#	endif
#endif

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
//	TARGET_OS
//

#ifndef TARGET_OS

	#if (defined(linux) || defined(_linux) || defined(__linux) || defined(__inux__)) || \
		(defined(FreeBSD) || defined(_FreeBSD) || defined(__FreeBSD) || defined(__FreeBSD__)) || \
		(defined(sun) || defined(_sun) || defined(__sun) || defined(__sun__)) || \
		(defined(AIX) || defined(_AIX) || defined(__AIX) || defined(__AIX__)) || \
		(defined(aix) || defined(_aix) || defined(__aix) || defined(__AIX__)) || \
		(defined(hppa) || defined(_hppa) || defined(__hppa) || defined(__hppa__)) || \
		(defined(hpux) || defined(_hpux) || defined(__hpux) || defined(__hpux__))

		#define		TARGET_OS				OS_POSIX

	#elif defined(_WIN32) || defined(_WIN64)

		#define		TARGET_OS				OS_WINDOWS

	#else

		#define		TARGET_OS				OS_NATIVE

	#endif

#endif

//////////////////////////////////////////////////////////////////////////
//
//	TARGET_BITS
//

#ifndef TARGET_BITS

	#if (defined(i386) || defined(_i386) || defined(__i386) || defined(__i386__)) || (defined(_WIN32)) || defined(_M_IX86)

		#define		TARGET_BITS				ARCH_32BIT

	#endif

	#if defined(_WIN64) || defined(__x86_64__) || defined(_M_X64)
		#undef		TARGET_BITS
		#define		TARGET_BITS				ARCH_64BIT

	#endif

	#if !defined(TARGET_BITS)

		#define		TARGET_BITS				ARCH_32BIT

	#endif

#endif

//////////////////////////////////////////////////////////////////////////
//
//	TARGET_MACH
//

#ifndef TARGET_ARCH

	#if (defined(i386) || defined(_i386) || defined(__i386) || defined(__i386__)) || defined(_M_IX86)

		#if TARGET_BITS == TARGET_64BIT
			#define TARGET_ARCH		TARGET_X64
		#else
			#define TARGET_ARCH		TARGET_X86
		#endif

	//#elif (defined(sun) || defined(_sun) || defined(__sun) || defined(__sun__)) || \
	//	(defined(AIX) || defined(_AIX) || defined(__AIX) || defined(__AIX__)) || \
	//	(defined(aix) || defined(_aix) || defined(__aix) || defined(__AIX__)) || \
	//	(defined(hppa) || defined(_hppa) || defined(__hppa) || defined(__hppa__)) || \
	//	(defined(hpux) || defined(_hpux) || defined(__hpux) || defined(__hpux__)) || \
	//	(defined(sparc) || defined(_sparc) || defined(__sparc) || defined(__sparc__))
	#else

		#define TARGET_ARCH		TARGET_NOT_X86

	#endif

#endif

//////////////////////////////////////////////////////////////////////////
//
//	TARGET_ENDIAN
//

#ifndef TARGET_ENDIAN

	#if (defined(sun) || defined(_sun) || defined(__sun) || defined(__sun__)) || \
		(defined(AIX) || defined(_AIX) || defined(__AIX) || defined(__AIX__)) || \
		(defined(aix) || defined(_aix) || defined(__aix) || defined(__AIX__)) || \
		(defined(hppa) || defined(_hppa) || defined(__hppa) || defined(__hppa__)) || \
		(defined(hpux) || defined(_hpux) || defined(__hpux) || defined(__hpux__)) || \
		(defined(sparc) || defined(_sparc) || defined(__sparc) || defined(__sparc__))

		#define		TARGET_ENDIAN			BYTE_ENDIAN_B

	#endif

	#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

		#define		TARGET_ENDIAN			BYTE_ENDIAN_L

	#endif

	#if !defined(TARGET_ENDIAN)

		#define TARGET_ENDIAN				BYTE_ENDIAN_L

	#endif

#endif

//////////////////////////////////////////////////////////////////////////
//
//	CPP_COMPILER
//

#ifndef CPP_COMPILER

	#if defined(_MSC_VER)

		#define CPP_COMPILER				CC_MSVC
		#define __attribute__(x)

	#else

		#define CPP_COMPILER				CC_GCC

	#endif

#endif


//////////////////////////////////////////////////////////////////////////

#if (TARGET_ENDIAN == BYTE_ENDIAN_B)

	#define ARCH_BIG_ENDIAN
	#define RS_BIG_ENDIAN

#else

	#define ARCH_LITTLE_ENDIAN
	#define RS_LITTLE_ENDIAN

#endif

//////////////////////////////////////////////////////////////////////////

#if (defined(AIX) || defined(_AIX) || defined(__AIX) || defined(__AIX__)) || \
	(defined(aix) || defined(_aix) || defined(__aix) || defined(__AIX__))

	#define COMPATIBILITY_AIX_PLATFORM

#endif

//////////////////////////////////////////////////////////////////////////

#if defined(__arm__) || defined(__thumb__) || defined(_ARM) || defined(_M_ARM) || defined(__aarch64__)

	#define COMPATIBILITY_ARM_PLATFORM

#endif

#if defined __APPLE__

#define COMPATIBILITY_DARWIN_PLATFORM

#endif

//////////////////////////////////////////////////////////////////////////

#if defined(__sun) && defined(__SVR4)

	#define COMPATIBILITY_SOLARIS_PLATFORM
	#define USE_SEMAPHORE

#endif

//////////////////////////////////////////////////////////////////////////

#if defined COMPATIBILITY_AIX_PLATFORM || defined COMPATIBILITY_SOLARIS_PLATFORM || defined COMPATIBILITY_DARWIN_PLATFORM

	#define COMPATIBILITY_NON_MAINSTREAM_OS

#endif

//////////////////////////////////////////////////////////////////////////

//# define COMPATIBILITY_FEDORA_ZHAOXIN_PLATFORM

//////////////////////////////////////////////////////////////////////////

#ifndef far
#	define far
#endif

/*******************************************************************************
<平台相关定义>
*******************************************************************************/
//
//	platform:	Windows
//
#include "feature.h"
#if (TARGET_OS == OS_WINDOWS)

	#if _WIN32_WINNT < 0x0502
	#	undef _WIN32_WINNT
	#	define _WIN32_WINNT    0x0502      // XP
	#endif

	#include <windows.h>
	#include <tchar.h>
	#include <wchar.h>
	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>

    #define PLATFORM_TYPE_WINDOWS

	#define snprintf		_snprintf

#elif (TARGET_OS == OS_NATIVE)

	#include "rsntddk.h"
	#define PLATFORM_TYPE_NATIVE

#elif (TARGET_OS == OS_POSIX)

	#include <sys/types.h>
	#include <sys/stat.h>
	#include <errno.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <strings.h>
	#include <stdarg.h>
	#include <stdio.h>
	#include <wchar.h>
	#include <sys/mman.h>
	#include <semaphore.h>
	#include <fcntl.h>
	#define PLATFORM_TYPE_POSIX
	#define PLATFORM_TYPE_LINUX

	#define __vswprintf			vswprintf

#endif


#if (CPP_COMPILER == CC_GCC )

	#include <stdint.h>
	typedef unsigned char				byte;
	typedef int8_t         				INT8,	*PINT8;
	typedef int16_t       				INT16,	*PINT16;
	typedef int32_t          			INT32,	*PINT32;
	typedef int64_t   					INT64,	*PINT64;
	typedef uint8_t       				UINT8,	*PUINT8;
	typedef uint16_t      				UINT16, *PUINT16;
	typedef uint32_t        			UINT32, *PUINT32;
	typedef uint64_t  					UINT64, *PUINT64;
	//////////////////////////////////////////////////////////////////////////
	typedef INT32						LONG;				// 32
	typedef UINT32						ULONG;				// 32
	typedef INT64						LONGLONG;			// 64
	typedef UINT64						ULONGLONG;			// 64
	//////////////////////////////////////////////////////////////////////////
	typedef UINT64						QWORD;				// 64
	typedef UINT32						DWORD;				// 32
	typedef UINT16						WORD;				// 16
	typedef UINT8						BYTE;				// 8

	#define _SECURE_SCL	0

	#ifndef UINT64_C
	#define UINT64_C(x)  (x ## ULL)
	#endif
	// compatible with GCC 3.3.x, or earlier.
	#ifdef LOW_GCC
	#define GCC_COMPATIBILITY_3_X_X
	#endif

#elif (CPP_COMPILER == CC_MSVC )

	#if _MSC_VER > 1500
	#	include <stdint.h>
	#else
	#	include "_stdint.h"
	#endif

	typedef int64_t				longlong;
	typedef uint64_t			ulonglong;

	#define _SECURE_SCL	0

#endif

#if TARGET_BITS == ARCH_32BIT

	typedef INT32					XLONG;
	typedef UINT32					XULONG;
	#if (!defined COMPATIBILITY_AIX_PLATFORM) && (!defined COMPATIBILITY_ARM_PLATFORM)
	typedef int32_t					ssize_t;
	#endif

#elif TARGET_BITS == ARCH_64BIT

	typedef INT64					XLONG;
	typedef UINT64					XULONG;
	#if (!defined COMPATIBILITY_AIX_PLATFORM) && (!defined COMPATIBILITY_ARM_PLATFORM) && (!defined COMPATIBILITY_DARWIN_PLATFORM)
	typedef int64_t					ssize_t;
	#endif

#endif

typedef XLONG					HOSTLONG;
typedef XULONG					HOSTULONG;

#ifndef __cplusplus
#define	STATICINLINE			static		
#else
#define STATICINLINE			static inline
#endif


STATICINLINE UINT16 _BSWAP16(UINT16 val)
{
	return (UINT16)(
		((val & (UINT16)0x00ffU) << 8) |
		((val & (UINT16)0xff00U) >> 8));
}
STATICINLINE UINT32 _BSWAP32(UINT32 val)
{
	return (UINT32)(
		((val & (UINT32)0x000000ffUL) << 24) |
		((val & (UINT32)0x0000ff00UL) <<  8) |
		((val & (UINT32)0x00ff0000UL) >>  8) |
		((val & (UINT32)0xff000000UL) >> 24));
}
STATICINLINE UINT64 _BSWAP64(UINT64 val)
{
	return (UINT64)(
		((val & (UINT64)0x00000000000000ffULL) << 56) |
		((val & (UINT64)0x000000000000ff00ULL) << 40) |
		((val & (UINT64)0x0000000000ff0000ULL) << 24) |
		((val & (UINT64)0x00000000ff000000ULL) <<  8) |
		((val & (UINT64)0x000000ff00000000ULL) >>  8) |
		((val & (UINT64)0x0000ff0000000000ULL) >> 24) |
		((val & (UINT64)0x00ff000000000000ULL) >> 40) |
		((val & (UINT64)0xff00000000000000ULL) >> 56));
}

#ifdef __cplusplus
template < class T >
STATICINLINE T BSWAPX( T v )
{
	const size_t c = sizeof(v);
	unsigned char * bp = (unsigned char *)&v;
	for( size_t i = 0; i < (c>>1); ++ i )
	{
		unsigned char t = bp[i];
		bp[i] = bp[c-1-i]; bp[c-1-i] = t;
	}
	return v;
}
template < class T, bool DO_SWAP >
STATICINLINE void PUTHX( void * p, T v )
{
	for( size_t i = 0; i < sizeof(T); ++ i )
	{
		size_t k = DO_SWAP ? (sizeof(T) - i - 1) : i;
		((char*)p)[k] = ((char*)(&v))[i];
	}
}

template < class T, bool DO_SWAP >
STATICINLINE T GETHX( const void * p )
{
	T v = 0;
	for( size_t i = 0; i < sizeof(T); ++ i )
	{
		size_t k = DO_SWAP ? (sizeof(T) - i - 1) : i;
		((char*)&v)[i] = ((char*)p)[k];
	}
	return v;
}


#ifdef ARCH_BIG_ENDIAN

	#define	NEEDSWAP				true

	#define SWAP2LE16				BSWAPX<INT16>
	#define SWAP2LE32				BSWAPX<INT32>
	#define	SWAP2LE64				BSWAPX<INT64>

	#define SET_AS_LE16(x,y)		PUTHX<INT16,true>((void*)(x),(INT16)(y))
	#define SET_AS_LE32(x,y)		PUTHX<INT32,true>((void*)(x),(INT32)(y))
	#define SET_AS_LE64(x,y)		PUTHX<INT64,true>((void*)(x),(INT64)(y))
	#define GET_AS_LE16(x)			GETHX<INT16,true>((const void*)(x))
	#define GET_AS_LE32(x)			GETHX<INT32,true>((const void*)(x))
	#define GET_AS_LE64(x)			GETHX<INT64,true>((const void*)(x))

	#define SET_AS_BE16(x,y)		PUTHX<INT16,false>((void*)(x),(INT16)(y))
	#define SET_AS_BE32(x,y)		PUTHX<INT32,false>((void*)(x),(INT32)(y))
	#define SET_AS_BE64(x,y)		PUTHX<INT64,false>((void*)(x),(INT64)(y))
	#define GET_AS_BE16(x)			GETHX<INT16,false>((const void*)(x))
	#define GET_AS_BE32(x)			GETHX<INT32,false>((const void*)(x))
	#define GET_AS_BE64(x)			GETHX<INT64,false>((const void*)(x))

#else

	#define	NEEDSWAP				false

	#define SWAP2LE16			
	#define SWAP2LE32			
	#define	SWAP2LE64			

	#define SET_AS_LE16(x,y)		PUTHX<INT16,false>((void*)(x),(INT16)(y))
	#define SET_AS_LE32(x,y)		PUTHX<INT32,false>((void*)(x),(INT32)(y))
	#define SET_AS_LE64(x,y)		PUTHX<INT64,false>((void*)(x),(INT64)(y))
	#define GET_AS_LE16(x)			GETHX<INT16,false>((const void*)(x))
	#define GET_AS_LE32(x)			GETHX<INT32,false>((const void*)(x))
	#define GET_AS_LE64(x)			GETHX<INT64,false>((const void*)(x))

	#define SET_AS_BE16(x,y)		PUTHX<INT16,true>((void*)(x),(INT16)(y))
	#define SET_AS_BE32(x,y)		PUTHX<INT32,true>((void*)(x),(INT32)(y))
	#define SET_AS_BE64(x,y)		PUTHX<INT64,true>((void*)(x),(INT64)(y))
	#define GET_AS_BE16(x)			GETHX<INT16,true>((const void*)(x))
	#define GET_AS_BE32(x)			GETHX<INT32,true>((const void*)(x))
	#define GET_AS_BE64(x)			GETHX<INT64,true>((const void*)(x))

#endif /* ARCH_BIG_ENDIAN */

// L-Endian Macros

#define SET_S16(x,y)				SET_AS_LE16(x,y)
#define SET_S32(x,y)				SET_AS_LE32(x,y)
#define SET_S64(x,y)				SET_AS_LE64(x,y)
#define SET_U16(x,y)				SET_AS_LE16(x,(UINT16)(y))
#define SET_U32(x,y)				SET_AS_LE32(x,(UINT32)(y))
#define SET_U64(x,y)				SET_AS_LE64(x,(UINT64)(y))
#define GET_S16(x)					GET_AS_LE16(x)
#define GET_S32(x)					GET_AS_LE32(x)
#define GET_S64(x)					GET_AS_LE64(x)
#define GET_U16(x)					((UINT16)GET_AS_LE16(x))
#define GET_U32(x)					((UINT32)GET_AS_LE32(x))
#define GET_U64(x)					((UINT64)GET_AS_LE64(x))

#endif

//#if (CPP_COMPILER==CC_MSVC)
//
//	#pragma message("CPP_COMPILER : CC_MSVC")
//
//	#if (TARGET_ENDIAN==BYTE_ENDIAN_B)
//		#pragma message("TARGET_ENDIAN : BIG_ENDIAN")
//	#else
//		#pragma message("TARGET_ENDIAN : LITTLE_ENDIAN")
//	#endif
//
//	#if (TARGET_OS==OS_NATIVE)
//		#pragma message("TARGET_OS : OS_NATIVE")
//	#elif (TARGET_OS==OS_WINDOWS)
//		#pragma message("TARGET_OS : OS_WINDOWS")
//	#elif (TARGET_OS==OS_POSIX)
//		#pragma message("TARGET_OS : OS_POSIX")
//	#endif
//
//	#if (TARGET_BITS==ARCH_32BIT)
//		#pragma message("TARGET_BITS : ARCH_32BIT")
//	#else
//		#pragma message("TARGET_BITS : ARCH_64BIT")
//	#endif
//
//	#if (TARGET_ARCH==TARGET_X86)
//		#pragma message("TARGET_ARCH : TARGET_X86")
//	#elif (TARGET_ARCH==TARGET_X64)
//		#pragma message("TARGET_ARCH : TARGET_X64")
//	#elif (TARGET_ARCH==TARGET_NOT_X86)
//		#pragma message("TARGET_ARCH : TARGET_NOT_X86")
//	#endif
//
//#elif (CPP_COMPILER==CC_GCC)
//
//	#warning ("CPP_COMPILER : CC_GCC")
//
//	#if (TARGET_ENDIAN==BYTE_ENDIAN_B)
//		#warning ("TARGET_ENDIAN : BIG_ENDIAN")
//	#else
//		#warning ("TARGET_ENDIAN : LITTLE_ENDIAN")
//	#endif
//
//	#if (TARGET_OS==OS_NATIVE)
//		#warning ("TARGET_OS : OS_NATIVE")
//	#elif (TARGET_OS==OS_WINDOWS)
//		#warning ("TARGET_OS : OS_WINDOWS")
//	#elif (TARGET_OS==OS_POSIX)
//		#warning ("TARGET_OS : OS_POSIX")
//	#endif
//
//	#if (TARGET_BITS==ARCH_32BIT)
//		#warning ("TARGET_BITS : ARCH_32BIT")
//	#else
//		#warning ("TARGET_BITS : ARCH_64BIT")
//	#endif
//
//	#if (TARGET_ARCH==TARGET_X86)
//		#warning ("TARGET_ARCH : TARGET_X86")
//	#elif (TARGET_ARCH==TARGET_X64)
//		#warning ("TARGET_ARCH : TARGET_X64")
//	#elif (TARGET_ARCH==TARGET_NOT_X86)
//		#warning ("TARGET_ARCH : TARGET_NOT_X86")
//	#endif
//
//#endif

#ifndef MIN
#	define	MIN(a,b) (((a) < (b)) ? (a) : (b))		//这两个宏linux下面没有定义
#endif

#ifndef MAX
#	define	MAX(a,b) (((a) > (b)) ? (a) : (b))
#endif


#if (CPP_COMPILER == CC_MSVC)
#	define _aligned(g)		__declspec(align(g))
#else
#	define _aligned(g)		__attribute__((aligned(g)))
#endif

#	define __aligned(g, type) _aligned(g) type


#define	RS_PACK_ONEBYTE		__attribute__((packed))
#define	RS_PACK_FOURBYTE	__attribute__((aligned(4)))
#define	RS_PACK_EIGHTBYTE	__attribute__((aligned(8)))


#define RS_GCC_OPTIMIZE_O0	__attribute__((optimize("O0")))
#define RS_GCC_OPTIMIZE_O1	__attribute__((optimize("O1")))
#define RS_GCC_OPTIMIZE_O2	__attribute__((optimize("O2")))
#define RS_GCC_OPTIMIZE_O3	__attribute__((optimize("O3")))

#define RS_PUBLIC_API	__attribute__((visibility("default")))
#define RS_LOCAL_API	__attribute__((visibility("hidden")))

#ifdef RS_BIG_ENDIAN
#if (TARGET_BITS == TARGET_32BIT)
	#define	RS_PACK_PTRSYZE		RS_PACK_FOURBYTE
#else
	#define	RS_PACK_PTRSYZE		RS_PACK_EIGHTBYTE
#endif
#else
	#define	RS_PACK_PTRSYZE
#endif

//
#define	USE_C_MEMORY_ALLOC

//////////////////////////////////////////////////////////////////////////
#if (TARGET_OS != OS_WINDOWS)
	#define RS_CONST_DEF
	#define XVALUE_CONVERT (Value*)
#else
	#define RS_CONST_DEF const
	#define XVALUE_CONVERT
#endif

typedef long	bool_t;

#define STR_SIZE_PAIR(X)		{X, sizeof(X)-1}
#define STR_SIZE_PAIR_Z(X)		{X, sizeof(X)}
#define STR_SIZE(x)				x, sizeof(x)-1
#define STR_SIZE_Z(X)			X, sizeof(X)
#define STR_AND_SIZE(x)			STR_SIZE(x)
#define STR_AND_SIZE_WZ(X)		STR_SIZE_Z(X)


//////////////////////////////////////////////////////////////////////////
// version
#if (TARGET_OS != OS_WINDOWS)

#define _RS_TOSTRING(x)		#x
#define RS_TOSTRING(x)		_RS_TOSTRING(x)

#ifdef TARGET_LBE
	#define RS_ENDIAN		"Little-Endian "
#else
	#define RS_ENDIAN		"Big-Endian "
#endif

#ifdef TARGET_64BIT
	#define RS_BITS			"x64 "
#else
	#define RS_BITS			"x86 "
#endif

#define RS_ENGINE_VERSION	"version: " RS_ENDIAN RS_BITS RS_TOSTRING(RS_FILEVERSION) " " RS_TOSTRING(RS_DATE) "\n"

#endif //TARGET_OS != OS_WINDOWS

#ifndef WIN32

#include <pthread.h>
#define GetCurrentThreadId			pthread_self
#define _DeleteMSLock				pthread_mutex_destroy
#define _EnterMSLock				pthread_mutex_lock
#define _LeaveMSLock				pthread_mutex_unlock
#define _InitializeMS(x,y)			pthread_mutex_init(x,y)
#define _MSLock						pthread_mutex_t

#define rx_sleep(x)					usleep((x)*1000)
#define stdext						__gnu_cxx

#define HASH_MAP_HEADER				<ext/hash_map>

#else

#define _DeleteMSLock				DeleteCriticalSection
#define _EnterMSLock				EnterCriticalSection
#define _LeaveMSLock				LeaveCriticalSection
#define _InitializeMS(x,y)			InitializeCriticalSection(x)
#define _MSLock						CRITICAL_SECTION

#define rx_sleep(x)					::Sleep(x)

#define HASH_MAP_HEADER				<hash_map>

#endif //WIN32

//////////////////////////////////////////////////////////////////////////

#ifdef COMPATIBILITY_NON_MAINSTREAM_OS
#define PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
#endif

#define	E_INVALID_MALWARE			0x8FFFFFFEL
#define	E_INVALID_LICENSE			0x8FFFFFFFL


//////////////////////////////////////////////////////////////////////////
#if TARGET_OS == OS_WINDOWS
#	ifdef _WIN64
#	define _ASM_INT_3	DebugBreak()
#	else
#	define _ASM_INT_3	_asm int 3
#	endif
#elif defined TARGET_ARCH_X86
#	define _ASM_INT_3	__asm__ __volatile__ ("int $3"::)
#else
#	define _ASM_INT_3
#endif

//////////////////////////////////////////////////////////////////////////
// darwin
//

#ifdef COMPATIBILITY_DARWIN_PLATFORM
#define lseek64			lseek
#define ftruncate64		ftruncate
#define O_LARGEFILE		0
#define off64_t			__darwin_off_t
#endif

#if defined(__clang__) || defined(__GNUC__)
#	if __cplusplus >= 201103L
#	define HAS_CPP_11	1
#	else
#	define HAS_CPP_11	0
#	endif
#elif defined(_MSC_VER)
#	if _MSC_VER >= 1700
#	define HAS_CPP_11	1
#	else
#	define HAS_CPP_11	0
#	endif
#endif



#endif //__RS_PLATFORM_DEFINE__


