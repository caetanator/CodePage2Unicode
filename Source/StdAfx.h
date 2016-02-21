/**
 * StdAfx.h
 *
 * ABSTRACT
 *  Include file for standard system include files, or project specific include files that
 *  are used frequently, but are changed infrequently.
 *
 * CONTACTS
 *  E-mail regarding any portion of the "CodePage2Unicode" project:
 *      José Caetano Silva, jcaetano@users.sourceforge.net
 *
 * COPYRIGHT
 *  This file is distributed under the terms of the GNU General Public
 *  License (GPL) v3. Copies of the GPL can be obtained from:
 *      ftp://prep.ai.mit.edu/pub/gnu/GPL
 *  Each contributing author retains all rights to their own work.
 *
 *  (C) 20011 - 20015   José Caetano Silva
 *
 * HISTORY
 *  2013-01-11: Created.
 *  2015-07-17: Fixed typos.
 */

#ifndef __STDAFX_H__
#define __STDAFX_H__

#pragma once

#include "ThirdParty/Boost/include/cpp_feature.h"

// Special macro flags
// * The NDEBUG macro controls if the assert macro is enabled in <assert.h> and <cassert>
#ifdef _DEBUG
#   ifdef NDEBUG
        // Enables the assert macro
#       undef NDEBUG
#   endif
#else
    // Disable the assert macro
#   define NDEBUG
#endif

#if defined(_MSC_VER) && !defined(__clang__)
	// * The _USE_MATH_DEFINES enables non ANSI C/C++ defines like M_PI in <math.h> and <cmath> for MS VC++
#	define _USE_MATH_DEFINES
#elif defined(__GNUC__)
	// * The _DEFAULT_SOURCE enables non ANSI C/C++ defines like M_PI in <math.h> and <cmath> for GNU GCC
#	ifndef _DEFAULT_SOURCE
#		define _DEFAULT_SOURCE
#		define ___MY_ERRASE_DEFAULT_SOURCE
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
#ifdef __has_include
#   if __has_include(<codecvt>)
#       include <codecvt>
#       define __HAS_INCLUDE_CODECVT    1
#   endif
#else
#   if (defined(_MSC_VER) && (_MSC_VER >= 1600)) || (defined(__clang__) && (__clang_major__ >= 3))
#       include <codecvt>
#       define __HAS_INCLUDE_CODECVT    1
#   endif
#endif
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifdef __has_include
#   if __has_include(<cuchar>)
#       include <cuchar>
#       define __HAS_INCLUDE_CUCHAR     1
#   endif
#else
#   if (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(__clang__) && (__clang_major__ >= 3))
#       include <cuchar>
#       define __HAS_INCLUDE_CUCHAR     1
#   endif
#endif
#include <cwchar>
#include <cwctype>
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
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#if (defined(_MSC_VER) && (_MSC_VER >= 1800)) || (defined(__clang__) && (__clang_major__ >= 3))
#   include <uchar.h>
#   define __HAS_INCLUDE_UCHAR_H    1
#endif
#include <wchar.h>
#include <wctype.h>
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

#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
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
#   include <richedit.h>
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
#include "CompilerInfo.h"
#include "CompilerConfig.h"
#include "CompilerEnvironment.h"

#endif // __STDAFX_H__
