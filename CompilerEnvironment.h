#ifndef _COMPILERENVIRONMENT_H_
#define _COMPILERENVIRONMENT_H_

#pragma once

// Machine native narrow, wide and default character size and type
/*
    These macros are for detect the machine character type

    __CHAR_NARROW_TYPE is set as follows:
        * __CHAR_NARROW_TYPE_UNKNOWN    -> Unknown
        * __CHAR_NARROW_TYPE_ASCII      -> 8 bit ASCII code page
        * __CHAR_NARROW_TYPE_UTF8       -> 8 bit UNICODE (UTF-8)


    __CHAR_WIDE_TYPE is set as follows:
        * __CHAR_WIDE_TYPE_UNKNOWN      -> Unknown
        * __CHAR_WIDE_TYPE_UTF16        -> 16 bit Unicode (UTF-16 / USC-2)
        * __CHAR_WIDE_TYPE_UTF32        -> 32 bit Unicode (UTF-32 / UCS-4)


    __CHAR_API_TYPE is set as follows:
        * __CHAR_API_TYPE_NARROW   -> Use native C/C++ narrow char APIs
        * __CHAR_API_TYPE_WIDE     -> Use native C/C++ wide char APIs
 */
#define __CHAR_NARROW_TYPE_UNKNOWN  0
#define __CHAR_NARROW_TYPE_ASCII    1
#define __CHAR_NARROW_TYPE_UTF8     8

#define __CHAR_WIDE_TYPE_UNKNOWN    0
#define __CHAR_WIDE_TYPE_UTF16      16
#define __CHAR_WIDE_TYPE_UTF32      32

#define __CHAR_API_TYPE_NARROW    0
#define __CHAR_API_TYPE_WIDE      1

// Default OS settings
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
    // Microsoft Windows:
    //  All currently known Windows platforms don't use UTF-8 for 'char',
	//  and is not supported by the console/shell. Windows use ASCII code pages.
    // Windows NT use UCS-2 for 'wchar_t' and Windows 2000 and above use UTF-16.
#   define __CHAR_NARROW_TYPE   __CHAR_NARROW_TYPE_ASCII
#   define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF16
#else
	// UNIX, Linux, BSD, Mac OS X and POSIX:
    //  All currently known platforms use UTF-8 for 'char' as default. UNIX/POSIX use UTF-32 for 'wchar_t'.
#   define __CHAR_NARROW_TYPE   __CHAR_NARROW_TYPE_UTF8
#   define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF32
#endif

// Compute 'wchar_t' size by the info from the compiler
#ifdef __STDC_ISO_10646__
	// For any compiler that provides this, 'wchar_t' is guaranteed to hold any Unicode
	// value with a single code point (32-bit or larger)
#   ifdef __CHAR_WIDE_TYPE
#       undef   __CHAR_WIDE_TYPE
#   endif
#   define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF32
#else
#   if defined(WCHAR_MAX)
		// 'WCHAR_MAX' is defined in <wchar.h>
#       ifdef __CHAR_WIDE_TYPE
#           undef   __CHAR_WIDE_TYPE
#       endif
#       if WCHAR_MAX <= 0xFFFF
			// 'wchar_t' is not larger than 16-bit
#           define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF16
#       elif WCHAR_MAX <= 0xFFFFFFFF
			// 'wchar_t' is not larger than 32-bit
#           define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF32
#       endif
#   endif
#endif

#if !defined(__CHAR_NARROW_TYPE) || !defined(__CHAR_WIDE_TYPE)
#   error "Could't compute native narrow and wide char types"
#endif

// Use narrow or wide APIs
#ifdef _UNICODE
#   define __CHAR_API_TYPE  __CHAR_API_TYPE_WIDE
#else
#   define __CHAR_API_TYPE  __CHAR_API_TYPE_NARROW
#endif


// C/C++ structure packing
/*
	These macros are for structure alignment
 */
#if defined(_MSC_VER) && (_MSC_VER >= 1200)
	// MS Visual C++ v6.0 and above
#   define ALIGN_1_BYTE __declspec(align(1))
#   define ALIGN_2_BYTE __declspec(align(2))
#   define ALIGN_4_BYTE __declspec(align(4))
#   define ALIGN_8_BYTE __declspec(align(8))
#elif defined(__GNUC__) && (__GNUC__ >= 3) && (__GNUC_MINOR__ >= 3)
	// GCC v3.3 and above
#   define ALIGN_1_BYTE __attribute__((aligned(1)))
#   define ALIGN_2_BYTE __attribute__((aligned(2)))
#   define ALIGN_4_BYTE __attribute__((aligned(4)))
#   define ALIGN_8_BYTE __attribute__((aligned(8)))
#else
	// Unknown compiler
#   define ALIGN_1_BYTE
#   define ALIGN_2_BYTE
#   define ALIGN_4_BYTE
#   define ALIGN_8_BYTE
#endif


// Dynamic Linked Library support
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
#	ifdef BUILDING_DLL
#		ifdef __GNUC__
#			define DLL_PUBLIC __attribute__ ((dllexport))
#		else
//          Note: actually GCC seems to also supports this syntax.
#			define DLL_PUBLIC __declspec(dllexport)
#		endif
#	else
#		ifdef __GNUC__
#			define DLL_PUBLIC __attribute__ ((dllimport))
#		else
//          Note: actually GCC seems to also supports this syntax.
#			define DLL_PUBLIC __declspec(dllimport)
#		endif
#	endif
#	define DLL_LOCAL
#else
#	if (__GNUC__ >= 4)
#		define DLL_PUBLIC __attribute__ ((visibility ("default")))
#		define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#	else
#		define DLL_PUBLIC
#		define DLL_LOCAL
#	endif
#endif


// Compiler C++11, C++14 and C++17 features detection
#ifdef __cpp_constexpr
#	define CPP11_CONSTEXPR constexpr
#else
#	define CPP11_CONSTEXPR
#endif

#ifdef __cpp_noexcept
#	define CPP11_NOEXCEPT noexcept
#else
#	define CPP11_NOEXCEPT throw()
#endif

#ifdef __cpp_override_control
#	define CPP11_OVERRIDE override
#else
#	define CPP11_OVERRIDE
#endif

// Compiler version validation
#if defined(__clang__)
	// CLang compiler detected
#	if (__clang_major__ < 3) || ((__clang_major__ == 3) && (__clang_minor__ < 1))
		// CLang 3.1 or lower
#		error "CLang version < 3.1 will not be able to compile this code because of missing C++11 features."
#	endif
#elif defined(__MINGW64__)
	// MinGW64 compiler detected
#   if (__MINGW64_VERSION_MAJOR < 4) || ((__MINGW64_VERSION_MAJOR == 4) && (__MINGW64_VERSION_MINOR < 6))
		// MINGW64 4.6 or lower
#       error "MinGW64 version < 4.6 will not be able to compile this code because of missing C++11 features."
#   endif
#elif defined(__MINGW32__)
	// MinGW32 compiler detected
#   if (__MINGW32_VERSION_MAJOR < 4) || ((__MINGW32_VERSION_MAJOR == 4) && (__MINGW64_VERSION_MINOR < 6))
        // MINGW32 4.6 or lower
#       error "MinGW32 version < 4.6 will not be able to compile this code because of missing C++11 features."
#   endif
#elif defined(__GNUC__)
	// GCC compiler detected
#	if (__GNUC__ < 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6))
		// GCC 4.6 or lower
#		error "GCC version < 4.6 will not be able to compile this code because of missing C++11 features."
#	endif
#elif defined(_MSC_VER)
	// VC++ compiler detected
#	if (_MSC_VER < 1600)
		// Visual Studio 2010 or lower
#		error "Visual C++ version < 16.0 (Visual Studio 2010) will not be able to compile this code because of missing C++11 features."
#	endif
#else
	// Unknown compiler
#   error "Unknown compiler will not be able to compile this code because of missing C++11 features."
#endif

#endif // __COMPILERENVIRONMENT_H_
