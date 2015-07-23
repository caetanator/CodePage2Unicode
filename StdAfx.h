// StdAfx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#pragma once

// Special macro flags
// * The NDEBUG macro controls if the assert macro is enabled in <assert.h> and <cassert>
#ifdef _DEBUG
#   ifdef NDEBUG
    // Enables the assert macro
#   undef NDEBUG
#       endif
#else
    // Disable the assert macro
#   define NDEBUG
#endif

#if _MSC_VER
	// * The _USE_MATH_DEFINES enables non ANSI C/C++ defines like M_PI in <math.h> and <cmath> for MS VC++
#	define _USE_MATH_DEFINES
#elif defined(__GNUC__ )
	// * The _BSD_SOURCE enables non ANSI C/C++ defines like M_PI in <math.h> and <cmath> for GNU GCC
#	ifndef _BSD_SOURCE
#		define _BSD_SOURCE
#		define ___MY_ERRASE_BSD_SOURCE
#	endif
// * The _GNU_SOURCE enables non ANSI C/C++ defines like M_PIl in <math.h> and <cmath> for GNU GCC
#	ifndef _GNU_SOURCE
#		define _GNU_SOURCE
#		define ___MY_ERRASE_GNU_SOURCE
#	endif
#endif

#if defined(__cplusplus)
// C++ Standard Header Files
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#ifdef __has_include
#   if __has_include(<codecvt>)
#       include <codecvt>
#       define __HAS_INCLUDE_CODECVT
#   endif
#else
#   if (defined(_MSC_VER) && (_MSC_VER >= 1600)) || (defined(__clang__) && (__clang_major__ >= 3))
#       include <codecvt>
#       define __HAS_INCLUDE_CODECVT
#   endif
#endif
#include <cmath>
#ifdef __has_include
#   if __has_include(<cuchar>)
#       include <cuchar>
#       define __HAS_INCLUDE_CUCHAR
#   endif
#else
#   if (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(__clang__) && (__clang_major__ >= 3))
#       include <cuchar>
#       define __HAS_INCLUDE_CUCHAR
#   endif
#endif
#include <cwchar>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <new>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>
#else
// C Standard Header Files
#include <assert.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#endif      // __cplusplus

// Cleanup
#ifdef ___MY_ERRASE_BSD_SOURCE
#   undef _BSD_SOURCE
#   undef ___MY_ERRASE_BSD_SOURCE
#endif
#ifdef ___MY_ERRASE_GNU_SOURCE
#   undef _GNU_SOURCE
#   undef ___MY_ERRASE_GNU_SOURCE
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
    // Windows Specific
#   include "Windows/TargetVer.h"
    // Windows Header Files
#   include <tchar.h>
#   if defined(_MBCS)
#       include <mbstring.h>
#   endif
#   include <windows.h>
#   include <shlobj.h>
#   include <strsafe.h>
#   include <fcntl.h>
#   include <io.h>
#   define __HAS_INCLUDE_WINDOWS
#else
    // POSIX Specific
#   include <sys/stat.h>
#   include <sys/types.h>
#   include <dirent.h>
#   include <fcntl.h>
#   include <unistd.h>
#   define __HAS_INCLUDE_POSIX
#endif

// Compiler Abstraction Header Files
#include "cpp_feature.h"
#include "CompilerInfo.h"
#include "CompilerConfig.h"

#endif // __STDAFX_H__
