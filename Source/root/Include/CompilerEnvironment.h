/**
 * CodePage2Unicode.cpp
 *
 * ABSTRACT:
 *  Implementation of the CodePage2Unicode API and objects that convert strings from ASCII to Unicode and vice versa.
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

#ifndef _COMPILERENVIRONMENT_H_
#define _COMPILERENVIRONMENT_H_

#pragma once

/**
 * These macros are for detect the OS native character type and size.
 *
 *     __CHAR_NARROW_TYPE is set as follows:
 *         * __CHAR_NARROW_TYPE_UNKNOWN    -> Unknown
 *         * __CHAR_NARROW_TYPE_MBCS       -> 8-bit MBCS code page
 *         * __CHAR_NARROW_TYPE_ASCII      -> 8-bit ASCII code page
 *         * __CHAR_NARROW_TYPE_UTF8       -> 8-bit Unicode (UTF-8)
 *
 *     __CHAR_WIDE_TYPE is set as follows:
 *         * __CHAR_WIDE_TYPE_UNKNOWN      -> Unknown
 *         * __CHAR_WIDE_TYPE_UTF16        -> 16-bit Unicode (UTF-16 / USC-2)
 *         * __CHAR_WIDE_TYPE_UTF32        -> 32-bit Unicode (UTF-32 / UCS-4)
 *
 *    __CHAR_API_TYPE is set as follows:
 *       * __CHAR_API_TYPE_MBCS     -> Use native C/C++ MBCS APIs
 *       * __CHAR_API_TYPE_NARROW   -> Use native C/C++ narrow char APIs
 *       * __CHAR_API_TYPE_WIDE     -> Use native C/C++ wide char APIs
 */
#define __CHAR_NARROW_TYPE_UNKNOWN  0
#define __CHAR_NARROW_TYPE_ASCII    1
#define __CHAR_NARROW_TYPE_MBCS     2
#define __CHAR_NARROW_TYPE_UTF8     8

#define __CHAR_WIDE_TYPE_UNKNOWN    0
#define __CHAR_WIDE_TYPE_UTF16      16
#define __CHAR_WIDE_TYPE_UTF32      32

#define __CHAR_API_TYPE_NARROW    0
#define __CHAR_API_TYPE_WIDE      1
#define __CHAR_API_TYPE_MBCS      2

/**
 * Compute the default OS settings for 'char' and 'wchar_t' types.
 */
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
    // Microsoft Windows:
    //  All currently known Windows platforms don't use UTF-8 for 'char' and it's not supported by the console/shell.
    //  Windows narrow char use ASCII or MBCS code pages.
    //  Windows NT and 9x use UCS-2 for 'wchar_t' and Windows 2000 and above use UTF-16.
#   if defined(_MBCS)
#       define __CHAR_NARROW_TYPE   __CHAR_NARROW_TYPE_MBCS
#   else
#       define __CHAR_NARROW_TYPE   __CHAR_NARROW_TYPE_ASCII
#   endif
#   define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF16
#else
	// UNIX, Linux, BSD, Mac OS X and POSIX:
    //  All currently known platforms use UTF-8 for 'char' as default.
    //  UNIX/POSIX/Mac OS X use UTF-32 for 'wchar_t'.
#   define __CHAR_NARROW_TYPE   __CHAR_NARROW_TYPE_UTF8
#   define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF32
#endif

/**
 * Compute 'wchar_t' size by the info from the compiler.
 */
#if defined(WCHAR_MAX)
	// 'WCHAR_MAX' is defined in <wchar.h>
#	ifdef __CHAR_WIDE_TYPE
#		undef   __CHAR_WIDE_TYPE
#   endif
#   if WCHAR_MAX <= 0xFFFF
		// 'wchar_t' is not larger than 16-bit
#		define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF16
#   elif WCHAR_MAX <= 0xFFFFFFFF
		// 'wchar_t' is not larger than 32-bit
#		define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF32
#   else
#		define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UNKNOWN
#   endif
#endif

#if !defined(__CHAR_NARROW_TYPE) || !defined(__CHAR_WIDE_TYPE)
#   error "Could't compute native narrow and/or wide char types"
#endif


/**
 * C/C++ features.
 */
#if defined(__STDC_VERSION__) || defined(__cplusplus)
#	if (__STDC_VERSION__ >= 199901L) || (__cplusplus >= 201103L)
	// C99 and C++11
#		if defined(__STDC_ISO_10646__)
			// Expands to an integer constant of the form yyyymmL, if 'wchar_t' can contain a single Unicode 
			// code point (32-bit or larger), the date indicates the latest revision of Unicode supported
#			ifdef __CHAR_WIDE_TYPE
#				undef   __CHAR_WIDE_TYPE
#			endif
#			define __CHAR_WIDE_TYPE     __CHAR_WIDE_TYPE_UTF32
#		endif
#		if defined(__STDC_HOSTED__) && (__STDC_HOSTED__ == 1)
			// Expands to the integer constant 1 if the implementation is hosted 
			// (runs under an OS), ​0​ if freestanding (runs without an OS)
#		endif
#	endif
#	if (__STDC_VERSION__ >= 201112L) || (__cplusplus >= 201103L)
		// C11 and C++11
#		if defined(__STDC_MB_MIGHT_NEQ_WC__) && (__STDC_MB_MIGHT_NEQ_WC__ == 1)
			// Expands to 1 if wide character encoding of the basic character set may not equal their narrow encoding
#		endif
#	endif
#endif


/**
 * C features.
 */
#if defined(__STDC__) && defined(__STDC_VERSION__)
#	if (__STDC_VERSION__ >= 201112L)
		// C11
#		if defined(__STDC_UTF_16__) && (__STDC_UTF_16__ == 1)
			// Expands to 1 if 'char16_t' use UTF-16 encoding
#		endif
#		if defined(__STDC_UTF_16__) && (__STDC_UTF_16__ == 1)
			// Expands to 1 if 'char32_t' use UTF-32 encoding
#		endif
#		if defined(__STDC_ANALYZABLE__) && (__STDC_ANALYZABLE__ == 1)
			// Expands to 1 if analyzability is supported
#		endif
#		if defined(__STDC_LIB_EXT1__)
			// Expands to an integer constant 201112L if bounds-checking interfaces are supported
#		endif
#		if defined(__STDC_NO_ATOMICS__) && (__STDC_NO_ATOMICS__ == 1)
			// Expands to 1 if atomic types and atomic operations library are not supported
#		endif
#		if defined(__STDC_NO_COMPLEX__) && (__STDC_NO_COMPLEX__ == 1)
			// Expands to 1 if complex types and complex math library are not supported
#		endif
#		if defined(__STDC_NO_THREADS__) && (__STDC_NO_THREADS__ == 1)
			// Expands to 1 if multithreading is not supported
#		endif
#		if defined(__STDC_NO_VLA__) && (__STDC_NO_VLA__ == 1)
			// Expands to 1 if variable-length arrays are not supported
#		endif
#	endif
#	if (__STDC_VERSION__ >= 199901L)
		// C99
#		if defined(__STDC_IEC_559__) && (__STDC_IEC_559__ == 1)
			// Expands to 1 if IEC 60559 is supported
#		endif
#		if defined(__STDC_IEC_559_COMPLEX__) && (__STDC_IEC_559_COMPLEX__ == 1)
			// Expands to 1 if IEC 60559 complex arithmetic is supported
#		endif
#	endif
#endif


/**
 * C++ features.
 */
#if defined(__cplusplus)
#	if (__cplusplus >= 201103L)
		// C++11
#		if defined(__STDCPP_STRICT_POINTER_SAFETY__) && (__STDCPP_STRICT_POINTER_SAFETY__ == 1)
			// Expands to 1 if the implementation has strict std::pointer_safety
#		endif
#		if defined(__STDCPP_THREADS__) && (__STDCPP_THREADS__ == 1)
			// Expands to 1 if if the program can have more than one thread of execution
#		endif
#	endif
#endif


/**
 * Set the C/C++/Windows narrow, wide or MBCS APIs to be used.
 */
#if defined(_UNICODE) && defined(__CHAR_WIDE_TYPE) && (__CHAR_WIDE_TYPE != __CHAR_WIDE_TYPE_UNKNOWN)
#   define __CHAR_API_TYPE  __CHAR_API_TYPE_WIDE
#elif defined(_MBCS) && defined(__CHAR_NARROW_TYPE) && (__CHAR_NARROW_TYPE == __CHAR_NARROW_TYPE_MBCS)
#   define __CHAR_API_TYPE  __CHAR_API_TYPE_MBCS
#else
#   define __CHAR_API_TYPE  __CHAR_API_TYPE_NARROW
#endif


/**
 * These macros are for C/C++ structure alignment and packing.
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


/**
 * These macros are for C/C++ DLL (Dynamic Linked Library) support.
 */
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
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


/**
 * Compiler C++11, C++14 and C++17 features detection fixes.
 */
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


/**
 * Compiler version validation.
 */
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
#elif defined(__CYGWIN__)
 // CygWin compiler detected
#	if (__GNUC__ < 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6))
 // GCC 4.6 or lower
#		error "CygWin version < 4.6 will not be able to compile this code because of missing C++11 features."
#	endif
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
