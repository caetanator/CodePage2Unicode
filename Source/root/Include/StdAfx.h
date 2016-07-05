/**
 * StdAfx.h
 *
 * ABSTRACT:
 *  Include file for standard system include files, or project specific include files that
 *  are used frequently, but are changed infrequently.
 *
 * CONTACTS:
 *  E-mail regarding any portion of the "CodePage2Unicode" project:
 *      José Caetano Silva, jcaetano@users.sourceforge.net
 *
 * COPYRIGHT:
 *  This file is distributed under the terms of the GNU General Public
 *  License (GPL) v3. Copies of the GPL can be obtained from:
 *      ftp://prep.ai.mit.edu/pub/gnu/GPL
 *  Each contributing author retains all rights to their own work.
 *
 *  (C) 20011 - 20016   José Caetano Silva
 *
 * HISTORY:
 *  2013-01-11: Created.
 *  2015-07-17: Fixed typos.
 *  2016-03-12: Fixed typos and coments.
 */

#ifndef __STDAFX_H__
#define __STDAFX_H__

#pragma once

#include "ThirdParty/Boost/include/cpp_feature.h"

/**
 * Special macro flags, to tune up the API.
 */
// The NDEBUG macro controls if the assert macro is enabled in <assert.h> and <cassert>
#ifdef _DEBUG
// Enables the assert macro
#   ifdef NDEBUG
#       undef NDEBUG
#   endif
#else
// Disable the assert macro
#	ifndef NDEBUG
#		define NDEBUG
#   endif
#endif

// Enables non ANSI C/C++ defines like M_PI in <math.h> and <cmath>
#if defined(_MSC_VER) && !defined(__clang__)
// The _USE_MATH_DEFINES enables non ANSI C/C++ defines like M_PI for MS VC++
#	define _USE_MATH_DEFINES
#elif defined(__GNUC__)
// The _DEFAULT_SOURCE enables non ANSI C/C++ defines like M_PI for GNU GCC
#	ifndef _DEFAULT_SOURCE
#		define _DEFAULT_SOURCE
#		define ___MY_ERRASE_DEFAULT_SOURCE
#	endif
// The _GNU_SOURCE enables non ANSI C/C++ defines like M_PIl for GNU GCC
#	ifndef _GNU_SOURCE
#		define _GNU_SOURCE
#		define ___MY_ERRASE_GNU_SOURCE
#	endif
#endif


/**
 * C/C++/Windows/POSIX standard header files.
 */
#if defined(__cplusplus)
// C++ Standard Header Files
#	include <algorithm>
#	include <cassert>
#	ifdef __has_include
#		if __has_include(<codecvt>)
#			include <codecvt>
#			define __HAS_INCLUDE_CODECVT    1
#		endif
#	else
#		if (defined(_MSC_VER) && (_MSC_VER >= 1600)) || (defined(__clang__) && (__clang_major__ >= 3))
#			include <codecvt>
#			define __HAS_INCLUDE_CODECVT    1
#		endif
#	endif
#	include <cctype>
#	include <cerrno>
#	include <climits>
#	include <cmath>
#	include <cstdint>
#	include <cstdio>
#	include <cstdlib>
#	include <cstring>
#	ifdef __has_include
#		if __has_include(<thread>)
#			include <thread>
#			define __HAS_INCLUDE_THREAD     1
#		endif
#	else
#		if (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(__clang__) && (__clang_major__ >= 3))
#			include <thread>
#			define __HAS_INCLUDE_THREAD     1
#		endif
#	endif
#	ifdef __has_include
#		if __has_include(<cuchar>)
#			include <cuchar>
#			define __HAS_INCLUDE_CUCHAR     1
#		endif
#	else
#		if (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(__clang__) && (__clang_major__ >= 3))
#			include <cuchar>
#			define __HAS_INCLUDE_CUCHAR     1
#		endif
#	endif
#	include <cwchar>
#	include <cwctype>
#	include <exception>
#	include <fstream>
#	include <functional>
#	include <iomanip>
#	include <iostream>
#	include <locale>
#	include <map>
#	include <new>
#	include <sstream>
#	include <stdexcept>
#	include <string>
#	include <typeinfo>
#	include <vector>
#else
// C Standard Header Files
#	include <assert.h>
#	include <ctype.h>
#	include <errno.h>
#	include <limits.h>
#	include <locale.h>
#	include <math.h>
#	include <stdint.h>
#	include <stdio.h>
#	include <stdlib.h>
#	include <string.h>
#	include <time.h>
#	if (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(__clang__) && (__clang_major__ >= 3))
#		include <uchar.h>
#		define __HAS_INCLUDE_UCHAR_H    1
#	endif
#	include <wchar.h>
#	include <wctype.h>
#endif      // __cplusplus

// Cleanup
#ifdef ___MY_ERRASE_DEFAULT_SOURCE
#   undef _DEFAULT_SOURCE
#   undef ___MY_ERRASE_DEFAULT_SOURCE
#endif
#ifdef ___MY_ERRASE_GNU_SOURCE
#   undef _GNU_SOURCE
#   undef ___MY_ERRASE_GNU_SOURCE
#endif

// Windows OS specific headers
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
// Windows OS target/version definition
#   include "Windows/TargetVer.h"
// Windows OS API header files
#   include <tchar.h>
#   if defined(_MBCS)
#       include <mbstring.h>
#   endif
#   include <windows.h>
#   include <shlobj.h>
#   include <strsafe.h>
#   include <fcntl.h>
#   include <io.h>
#   include <richedit.h>
#   define __HAS_INCLUDE_WINDOWS
#elif defined(__MACOSX__) || (defined(__APPLE__) && defined(__MACH__))
// Mac OS X
#   define __HAS_INCLUDE_MACOS_X
#elif defined(__MACOS__) || defined(macintosh) || defined(Macintosh)
// Mac OS 9 or earlier
#   define __HAS_INCLUDE_MACOS_CLASSIC
#elif defined(__posix__) || defined(_POSIX_VERSION) || defined(_POSIX2_VERSION) || defined(_POSIX2_C_VERSION)
// POSIX Specific
#   include <sys/stat.h>
#   include <sys/types.h>
#   include <sys/utsname.h>
#   include <sys/wait.h>
#   include <dirent.h>
#   include <fcntl.h>
#   include <fenv.h>
#   include <iconv.h>
#   include <pthread.h>
#   include <unistd.h>
#   include <utime.h>
#   define __HAS_INCLUDE_POSIX
#elif defined(__unix__) || defined(__unix) || defined(unix)
// UNIX
#   include <unistd.h>
#   include <utime.h>
#   define __HAS_INCLUDE_UNIX
#endif

// Compiler Abstraction Header Files
#include "CompilerInfo.h"
#include "CompilerConfig.h"
#include "CompilerEnvironment.h"

#endif // __STDAFX_H__
