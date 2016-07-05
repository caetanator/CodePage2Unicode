/**
 * CompilerInfo.h
 *
 * ABSTRACT:
 *  Include file for detecting compiler related information.
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

#ifndef _COMPILERINFO_H_
#define _COMPILERINFO_H_

#pragma once


/**
 * These macros are for detect the compiler language (C/C++) standard.
 *
 * __COMPILER_LANGUAGE_STANDARD is set as follows:
 *
 * __COMPILER_LANGUAGE_STANDARD_UNKNOWN	-> Unknown
 * __COMPILER_LANGUAGE_STANDARD_C1989	-> C89 - ANSI X3.159-1989
 * __COMPILER_LANGUAGE_STANDARD_C1990	-> C90 (same as C89) - ISO/IEC 9899:1990
 * __COMPILER_LANGUAGE_STANDARD_C1990_1	-> C95  (C90 + Normative Amendment 1) - ISO/IEC 9899/AMD1:1995
 * __COMPILER_LANGUAGE_STANDARD_C1994	-> C95  (C90 + Normative Amendment 1) - ISO/IEC 9899-1:1994
 * __COMPILER_LANGUAGE_STANDARD_C1995	-> C95  (C90 + Normative Amendment 1) - ISO/IEC 9899/AMD1:1995
 * __COMPILER_LANGUAGE_STANDARD_C1999	-> C99 - ISO/IEC 9899:1999
 * __COMPILER_LANGUAGE_STANDARD_C2011	-> C11 - ISO/IEC 9899:2011
 * __COMPILER_LANGUAGE_STANDARD_CPP1998	-> C++98 - ISO/IEC 14882:1998
 * __COMPILER_LANGUAGE_STANDARD_CPP2011	-> C++11 - ISO/IEC 14882:2011
 * __COMPILER_LANGUAGE_STANDARD_CPP2014	-> C++14 - ISO/IEC 14882:2014
 * __COMPILER_LANGUAGE_STANDARD_CPP2017	-> C++17 - ISO/IEC C++1z
 */
#define __COMPILER_LANGUAGE_STANDARD_UNKNOWN	0
#define __COMPILER_LANGUAGE_STANDARD_C1989		198990L
#define __COMPILER_LANGUAGE_STANDARD_C1990		__COMPILER_LANGUAGE_STANDARD_C1989
#define __COMPILER_LANGUAGE_STANDARD_C1990_1	199409L
#define __COMPILER_LANGUAGE_STANDARD_C1994		__COMPILER_LANGUAGE_STANDARD_C1990_1
#define __COMPILER_LANGUAGE_STANDARD_C1995		__COMPILER_LANGUAGE_STANDARD_C1994
#define __COMPILER_LANGUAGE_STANDARD_C1999		199901L
#define __COMPILER_LANGUAGE_STANDARD_C2011		201112L
#define __COMPILER_LANGUAGE_STANDARD_CPP1998	199711L
#define __COMPILER_LANGUAGE_STANDARD_CPP2011	201103L
#define __COMPILER_LANGUAGE_STANDARD_CPP2014	201402L
#define __COMPILER_LANGUAGE_STANDARD_CPP2017	201403L
#define __COMPILER_LANGUAGE_STANDARD_STRING	(																				\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_C1990) ? _T("ANSI C89/ISO C90") : (						\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_C1995) ? _T("ISO C95 (C90 + Normative Amendment 1)") : (	\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_CPP1998) ? _T("ISO C++98") : (							\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_C1999) ? _T("ISO C99") : ( 								\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_CPP2011) ? _T("ISO C++11") : (							\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_C2011) ? _T("ISO C11") : (								\
	(__COMPILER_LANGUAGE_STANDARD <= __COMPILER_LANGUAGE_STANDARD_CPP2014) ? _T("ISO C++11") : ( 							\
	(__COMPILER_LANGUAGE_STANDARD == __COMPILER_LANGUAGE_STANDARD_CPP2017) ? _T("ISO C++17/C++1z") : (						\
	_T("Unknown")))))))))																									\
)


/**
 * These macros are for detect the machine compiler type.
 *
 * __COMPILER_TYPE is set as follows:
 *
 * __COMPILER_TYPE_UNKNOWN  -> Unknown
 * __COMPILER_TYPE_MSVC     -> Microsoft Visual C++
 * __COMPILER_TYPE_GCC      -> GNU Compiler Collection
 * __COMPILER_TYPE_CLANG    -> CLang/LLVM
 * __COMPILER_TYPE_BORLAND  -> Borland C++ Builder/Turbo C
 * __COMPILER_VERSION_MAJOR	-> Compiler major version
 * __COMPILER_VERSION_MINOR	-> Compiler minor version
 * __COMPILER_VERSION_BUILD	-> Compiler build version
 * __COMPILER_VERSION_PATCH	-> Compiler patch level version
 * __COMPILER_VERSION		-> Compiler full version
 */
#define __COMPILER_TYPE_UNKNOWN     0
#define __COMPILER_TYPE_MSVC        1
#define __COMPILER_TYPE_GCC         2
#define __COMPILER_TYPE_CLANG       3
#define __COMPILER_TYPE_BORLAND     4
#define __COMPILER_TYPE_STRING	(																\
	(__COMPILER_TYPE == __COMPILER_TYPE_MSVC) ? _T("Microsoft Visual C++") : ( 					\
	(__COMPILER_TYPE == __COMPILER_TYPE_GCC) ? _T("GCC - GNU Compiler Collection") : ( 			\
	(__COMPILER_TYPE == __COMPILER_TYPE_CLANG) ? _T("CLang/LLVM") : (							\
	(__COMPILER_TYPE == __COMPILER_TYPE_BORLAND) ? _T("Borland C++/Turbo C") : (	\
	_T("Unknown")))))																			\
)


/**
 *  These macros are for detect the machine compiler toolset.
 *
 * __COMPILER_TOOLSET is set as follows:
 *
 * __COMPILER_TOOLSET_UNKNOWN			-> Unknown
 * __COMPILER_TOOLSET_MSVC				-> Microsoft C1xx/C2
 * __COMPILER_TOOLSET_MSVC_CLANG_LLVM	-> Microsoft CLang/LLVM
 * __COMPILER_TOOLSET_MSVC_CLANG_C2		-> Microsoft CLang/C2
 * __COMPILER_TOOLSET_GCC				-> GCC
 * __COMPILER_TOOLSET_GCC_MINGW			-> MinGW
 * __COMPILER_TOOLSET_GCC_CYGWIN		-> CygWin
 * __COMPILER_TOOLSET_CLANG				-> CLang/LLVM
 * __COMPILER_TOOLSET_BORLAND_CPP		-> Borland C++
 * __COMPILER_TOOLSET_BORLAND_TC		-> Borland Turbo C
 */
#define __COMPILER_TOOLSET_UNKNOWN			0
#define __COMPILER_TOOLSET_MSVC				101
#define __COMPILER_TOOLSET_MSVC_CLANG_LLVM	102
#define __COMPILER_TOOLSET_MSVC_CLANG_C2    103
#define __COMPILER_TOOLSET_GCC				201
#define __COMPILER_TOOLSET_GCC_MINGW		202
#define __COMPILER_TOOLSET_GCC_CYGWIN		203
#define __COMPILER_TOOLSET_CLANG			301
#define __COMPILER_TOOLSET_BORLAND_TC		401
#define __COMPILER_TOOLSET_BORLAND_CPP		402
#define __COMPILER_TOOLSET_STRING	(																			\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_MSVC) ? _T("Microsoft Visual C++ C1xx/C2") : ( 				\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_MSVC_CLANG_LLVM) ? _T("Microsoft Visual C++ CLang/LLVM") : (	\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_MSVC_CLANG_C2) ? _T("Microsoft Visual C++ CLang/C2") : ( 		\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_GCC) ? _T("GCC - GNU Compiler Collection") : (				\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_GCC_MINGW) ? _T("MinGW - Minimalist GNU for Windows") : (		\
    (__COMPILER_TOOLSET == __COMPILER_TOOLSET_GCC_CYGWIN) ? _T("CygWin") : ( 								\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_CLANG) ? _T("CLang/LLVM") : (									\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_BORLAND_TC) ? _T("Borland Turbo C") : ( 						\
	(__COMPILER_TOOLSET == __COMPILER_TOOLSET_BORLAND_CPP ? _T("Borland C++") : (							\
	_T("Unknown"))))))))))																					\
)


/**
 * These macros are for detect the machine platform OS type.
 *
 * __COMPILER_PLATFORM_TYPE is set as follows:
 *
 * __COMPILER_PLATFORM_TYPE_UNKNOWN     -> Unknown
 * __COMPILER_PLATFORM_TYPE_DOS         -> DOS
 * __COMPILER_PLATFORM_TYPE_WINDOWS     -> Windows
 * __COMPILER_PLATFORM_TYPE_MACOS       -> Mac OS
 * __COMPILER_PLATFORM_TYPE_LINUX       -> Linux
 * __COMPILER_PLATFORM_TYPE_BSD         -> BSD
 * __COMPILER_PLATFORM_TYPE_UNIX        -> UNIX based OS
 * __COMPILER_PLATFORM_TYPE_POSIX       -> POSIX compatible OS
 *
 *    Note: UNIX and POSIX are generic.
 */
#define __COMPILER_PLATFORM_TYPE_UNKNOWN    0
#define __COMPILER_PLATFORM_TYPE_WINDOWS    1
#define __COMPILER_PLATFORM_TYPE_LINUX      2
#define __COMPILER_PLATFORM_TYPE_MACOS      3
#define __COMPILER_PLATFORM_TYPE_UNIX       4
#define __COMPILER_PLATFORM_TYPE_POSIX      5
#define __COMPILER_PLATFORM_TYPE_BSD        6
#define __COMPILER_PLATFORM_TYPE_DOS        7
#define __COMPILER_PLATFORM_TYPE_STRING	(														 \
    (__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_DOS) ? _T("Microsoft DOS") : (		 \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_WINDOWS) ? _T("Microsoft Windows") : ( \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_LINUX) ? _T("Linux") : ( 				 \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_MACOS) ? _T("Apple Mac OS") : ( 		 \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_BSD) ? _T("BSD") : (					 \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_UNIX) ? _T("UNIX") : ( 				 \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_POSIX) ? _T("POSIX") : (				 \
	_T("Unknown"))))))))																		 \
)


/**
 *  These macros are for detect the machine platform OS hardware.
 *
 * __COMPILER_PLATFORM_SUBTYPE is set as follows:
 *
 * __COMPILER_PLATFORM_SUBTYPE_UNKNOWN			-> Unknown
 * __COMPILER_PLATFORM_SUBTYPE_DOS_16		    -> DOS 16-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE		-> Windows CE 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET	-> Windows CE.NET 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_RT		-> Windows RT ARM 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16       -> Windows 16-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32       -> Windows 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64       -> Windows 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_MINGW_32			-> MinGW Windows 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_MINGW_64			-> MinGW Windows 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_CYGWIN_32		-> CygWin Windows 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_CYGWIN_64		-> CygWin Windows 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_LINUX_32         -> Linux 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_LINUX_64         -> Linux 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_MACOS_32		    -> Mac OS Classic (version 9 or earlier) 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_MACOS_X_32		-> Mac OS X 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_MACOS_X_64		-> Mac OS X 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32   -> FreeBSD 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_64   -> FreeBSD 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32    -> NetBSD 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_64    -> NetBSD 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32   -> OpenBSD 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64   -> OpenBSD 64-bit
 */
#define __COMPILER_PLATFORM_SUBTYPE_UNKNOWN         0
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16      101
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32      102
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64      103
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE      104
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET  105
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_RT      106
#define __COMPILER_PLATFORM_SUBTYPE_MINGW_32        107
#define __COMPILER_PLATFORM_SUBTYPE_MINGW_64        108
#define __COMPILER_PLATFORM_SUBTYPE_CYGWIN_32		109
#define __COMPILER_PLATFORM_SUBTYPE_CYGWIN_64		110
#define __COMPILER_PLATFORM_SUBTYPE_LINUX_32        201
#define __COMPILER_PLATFORM_SUBTYPE_LINUX_64        202
#define __COMPILER_PLATFORM_SUBTYPE_MACOS_32        301
#define __COMPILER_PLATFORM_SUBTYPE_MACOS_X_32      302
#define __COMPILER_PLATFORM_SUBTYPE_MACOS_X_64      303
#define __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32  601
#define __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_64  602
#define __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32   603
#define __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_64   604
#define __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32  605
#define __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64  606
#define __COMPILER_PLATFORM_SUBTYPE_DOS_16          701
#define __COMPILER_PLATFORM_SUBTYPE_STRING	(															\
    (__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_DOS_16) ? _T("MSDOS16") : (			    \
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16) ? _T("Win16") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32) ? _T("Win32") : ( 			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64) ? _T("Win64") : ( 			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE) ? _T("WinCE") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET) ? _T("WinCE.NET") : (   \
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_RT) ? _T("WinRT") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MINGW_32) ? _T("MinGW32") : ( 			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MINGW_64) ? _T("MinGW64") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_CYGWIN_32) ? _T("CygWin32") : ( 		\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_CYGWIN_64) ? _T("CygWin64") : ( 		\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_LINUX_32) ? _T("Linux32") : ( 			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_LINUX_64) ? _T("Linux64") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MACOS_32) ? _T("MacOS32") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MACOS_X_32) ? _T("MacOS_X32") : (		\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MACOS_X_64) ? _T("MacOS_X64") : (		\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32) ? _T("FreeBSD32") : (	\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_64) ? _T("FreeBSD64") : (	\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32) ? _T("NetBSD32") : (		\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_64) ? _T("NetBSD64") : (		\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32) ? _T("OpenBSD32") : (	\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64) ? _T("OpenBSD64") : (	\
	_T("Unknown")))))))))))))))))))))))																	\
)


/**
 *  These macros are for detect the machine CPU family´.
 *
 * __COMPILER_CPU_FAMILY is set as follows:
 *
 * __COMPILER_CPU_FAMILY_UNKNOWN	-> Unknown
 * __COMPILER_CPU_FAMILY_INTEL_IA16	-> IA16 16-bit (Intel x86, 80286, 80186, ...)
 * __COMPILER_CPU_FAMILY_INTEL_IA32	-> IA32 32-bit (Intel x86, 80386, 80486, Pentium, P4; AMD; Cytrix; ...)
 * __COMPILER_CPU_FAMILY_INTEL_IA64 -> IA64 64-bit (Intel Itanium Architecture)
 * __COMPILER_CPU_FAMILY_AMD_64     -> AMD64 64-bit (AMD x64; Intel EM64T; ...)
 * __COMPILER_CPU_FAMILY_MIPS_32    -> MIPS 32-bit
 * __COMPILER_CPU_FAMILY_MIPS_64    -> MIPS 64-bit
 * __COMPILER_CPU_FAMILY_ALPHA_32	-> Alpha 32-bit (DEC Alpha; ...)
 * __COMPILER_CPU_FAMILY_ALPHA_64	-> Alpha 64-bit (DEC Alpha 64; ...)
 * __COMPILER_CPU_FAMILY_PPC_32		-> PowerPC 32-bit (Motorola PowerPC; IBM PowerPC; ...)
 * __COMPILER_CPU_FAMILY_PPC_64		-> PowerPC 64-bit (Motorola PowerPC 64; IBM PowerPC 64; ...)
 * __COMPILER_CPU_FAMILY_SPARC_32	-> SPARC 32-bit (Sun SPARC; ...)
 * __COMPILER_CPU_FAMILY_SPARC_64	-> SPARC 64-bit (Sun SPARC 64; Oracle SPARC 64; ...)
 * __COMPILER_CPU_FAMILY_ARM_32		-> ARM 32-bit (...)
 * __COMPILER_CPU_FAMILY_ARM_64		-> ARM 64-bit (...)
 */
#define __COMPILER_CPU_FAMILY_UNKNOWN       0
#define __COMPILER_CPU_FAMILY_INTEL_IA16    116
#define __COMPILER_CPU_FAMILY_INTEL_IA32    132
#define __COMPILER_CPU_FAMILY_INTEL_IA64    164
#define __COMPILER_CPU_FAMILY_AMD_64        264
#define __COMPILER_CPU_FAMILY_MIPS_32       332
#define __COMPILER_CPU_FAMILY_MIPS_64       364
#define __COMPILER_CPU_FAMILY_ALPHA_32      432
#define __COMPILER_CPU_FAMILY_ALPHA_64      564
#define __COMPILER_CPU_FAMILY_PPC_32        632
#define __COMPILER_CPU_FAMILY_PPC_64        664
#define __COMPILER_CPU_FAMILY_SPARC_32      732
#define __COMPILER_CPU_FAMILY_SPARC_64      764
#define __COMPILER_CPU_FAMILY_ARM_32        832
#define __COMPILER_CPU_FAMILY_ARM_64        864
#define __COMPILER_CPU_FAMILY_STRING	(															\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_INTEL_IA16) ? _T("Intel x86 - 16-Bit") : (		\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_INTEL_IA32) ? _T("Intel x86 - IA-32") : ( 		\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_INTEL_IA64) ? _T("Intel Itanium - IA-64") : ( 	\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_AMD_64) ? _T("AMD x64/Intel EM64T") : (		\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_MIPS_32) ? _T("MIPS 32-bit") : (			    \
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_MIPS_64) ? _T("MIPS 64-bit") : (				\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_ALPHA_32) ? _T("DEC Alpha 32-bit") : ( 			\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_ALPHA_64) ? _T("DEC Alpha 64-bit") : (			\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_PPC_32) ? _T("IBM/Motorola PowerPC 32-bit") : ( \
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_PPC_64) ? _T("IBM/Motorola PowerPC 64-bit") : ( \
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_SPARC_32) ? _T("Oracle/Sun SPARC 32-bit") : (	\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_SPARC_64) ? _T("Oracle/Sun SPARC 64-bit") : (	\
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_ARM_32) ? _T("ARM 32-bit") : (				    \
	(__COMPILER_CPU_FAMILY == __COMPILER_CPU_FAMILY_ARM_64) ? _T("ARM 64-bit") : (				    \
	_T("Unknown")))))))))))))))																		\
)


/**
 *  These macros are for detect the machine CPU bits.
 *
 * __COMPILER_CPU_BITS is set as follows:
 *
 * __COMPILER_CPU_BITS_UNKNOWN	-> Unknown
 * __COMPILER_CPU_BITS_16		-> 16-bit
 * __COMPILER_CPU_BITS_32		-> 32-bit
 * __COMPILER_CPU_BITS_64       -> 64-bit
 */
#define __COMPILER_CPU_BITS_UNKNOWN 0
#define __COMPILER_CPU_BITS_16  16
#define __COMPILER_CPU_BITS_32  32
#define __COMPILER_CPU_BITS_64  64


/**
 *  These macros are for detect the machine CPU byte order endianness.
 *
 * __COMPILER_CPU_BYTE_ORDER is set as follows:
 *
 * __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN	-> Unknown
 * __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN	-> Little Endian (Intel x86, AMD x64)
 * __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN		-> Big Endian (SPARC, PowerPC)
 * __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN	-> Word-Swapped Little-Endian (PDP-11. Old format. Not supported by us)
 * __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN	-> Word-Swapped Big-Endian (Honeywell 316. Old format. Not supported by us)
 *
 *  Note: MIPS and ARM processors can be programmed for little or big endian.
 */
#define __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN    0
#define __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN     1234
#define __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN        4321
#define __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN       2143
#define __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN       3412
#define __COMPILER_CPU_BYTE_ORDER_STRING	(														 \
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN) ? _T("Little-Endian") : ( \
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN) ? _T("Big-Endian") : ( 		 \
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN) ? _T("WSLE-Endian") : ( 	 \
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN) ? _T("WSBE-Endian") : (	 \
	_T("Unknown")))))																				 \
)


/**
 * Detect the compiler language standard.
 */
#if defined(__cplusplus)
#	if (__cplusplus <= __COMPILER_LANGUAGE_STANDARD_CPP1998)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_CPP1998
#	elif (__cplusplus <= __COMPILER_LANGUAGE_STANDARD_CPP2011)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_CPP2011
#	elif (__cplusplus <= __COMPILER_LANGUAGE_STANDARD_CPP2014)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_CPP2014
#	elif (__cplusplus > __COMPILER_LANGUAGE_STANDARD_CPP2014)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_CPP2017
#	else
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_UNKNOWN
#   endif
#elif defined(__STDC_VERSION__)
#	if (__STDC_VERSION__ <= __COMPILER_LANGUAGE_STANDARD_C1995)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_C1995
#	elif (__STDC_VERSION__ <= __COMPILER_LANGUAGE_STANDARD_C1999)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_C1999
#	elif (__STDC_VERSION__ <= __COMPILER_LANGUAGE_STANDARD_C2011)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_C2011
#	else
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_UNKNOWN
#   endif
#elif defined(__STDC__)
#	if (__STDC__ <= __COMPILER_LANGUAGE_STANDARD_C1990)
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_C1990
#	else
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_UNKNOWN
#   endif
#else
#		define __COMPILER_LANGUAGE_STANDARD	__COMPILER_LANGUAGE_STANDARD_UNKNOWN
#endif


/**
 * Detect the OS platform.
 */
#if defined(_WIN16) || defined(_WINDOWS) || (defined(WINVER) && (WINVER <= 0x030A))
// Windows 16-bit
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16
#   define __COMPILER_CPU_BYTE_ORDER    __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   define __COMPILER_CPU_BITS          __COMPILER_CPU_BITS_16
#   define __COMPILER_CPU_FAMILY        __COMPILER_CPU_FAMILY_INTEL_IA16
#elif defined(_WIN32)
// Windows (x64, x86, CE, ...)
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#	if defined(__MINGW64__)
// Windows MinGW x64
#		define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MINGW_64
#	elif defined(__MINGW32__)
// Windows MinGW x86
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MINGW_32
#	elif defined(__CYGWIN__)
#		if defined(__LP64__) || defined(__LP64)
// Windows CygWin x64
#			define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_CYGWIN_64
#		else
// Windows CygWin x86
#		define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_CYGWIN_32
#		endif
#   elif defined(_WIN64)
// Windows x64
#       define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64
#   elif defined(_WIN32_WCE)
// Windows CE
#       if (_WIN32_WCE >= 0x400)
#           define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET
#       else
#           define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE
#       endif
#   else
// Windows x86
#       define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32
#   endif
#elif defined(__linux__) || defined(__linux) || defined(linux)
    // Linux
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_LINUX
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_LINUX_32
#elif defined(__FreeBSD__)
    // FreeBSD
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_BSD
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32
#elif defined(__NetBSD__)
    // NetBSD
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_BSD
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32
#elif defined(__OpenBSD__)
    // OpenBSD
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_BSD
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32
#elif defined(__MACOSX__) || (defined(__APPLE__) && defined(__MACH__))
    // Mac OS X
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_MACOS
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MACOS_X_32
#elif defined(__MACOS__) || defined(macintosh) || defined(Macintosh)
    // Mac OS 9 or earlier
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_MACOS
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MACOS_32
#elif defined(__posix__) || defined(_POSIX_VERSION) || defined(_POSIX2_VERSION) || defined(_POSIX2_C_VERSION)
// POSIX
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_POSIX
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_UNKNOWN
/*
	Name			Macro						Standard
	POSIX.1-1988	_POSIX_VERSION = 198808L
	POSIX.1-1990	_POSIX_VERSION = 199009L	ISO/IEC 9945-1:1990
	POSIX.2			_POSIX2_C_VERSION = 199209L	ISO/IEC 9945-2:1993
	POSIX.1b-1993	_POSIX_VERSION = 199309L	IEEE 1003.1b-1993
	POSIX.1-1996	_POSIX_VERSION = 199506L	IEEE 1003.1-1996
	POSIX.1-2001	_POSIX_VERSION = 200112L	IEEE 1003.1-2001
	POSIX.1-2008	_POSIX_VERSION = 200809L	IEEE 1003.1-2008
 */
#elif defined(__unix__) || defined(__unix) || defined(unix)
// UNIX
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_UNIX
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_UNKNOWN
#else
    // Unknown
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_UNKNOWN
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_UNKNOWN
#endif


/**
 * Detect the compiler used to generate the binary code.
 */
#if defined(_MSC_VER) && !defined(__clang__)
// Microsoft Visual C++ compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_MSVC
#   define __COMPILER_VERSION_MAJOR (_MSC_VER / 100)
#   define __COMPILER_VERSION_MINOR (_MSC_VER - (__COMPILER_VERSION_MAJOR * 100))
#   define __COMPILER_VERSION_BUILD (_MSC_BUILD)
#   define __COMPILER_VERSION_PATCH (_MSC_FULL_VER - (_MSC_VER * 100000))
#   define __COMPILER_VERSION       (_MSC_FULL_VER)
#elif defined(__clang__)
// CLang compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_CLANG
#   define __COMPILER_VERSION_MAJOR (__clang_major__)
#   define __COMPILER_VERSION_MINOR (__clang_minor__)
#   define __COMPILER_VERSION_BUILD (0)
#   define __COMPILER_VERSION_PATCH (__clang_patchlevel__)
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
#elif defined(__GNUC__)
// GCC compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_GCC
#ifndef __GNUC_PATCHLEVEL__
#   define __GNUC_PATCHLEVEL__	0
#endif
#   define __COMPILER_VERSION_MAJOR (__GNUC__)
#   define __COMPILER_VERSION_MINOR (__GNUC_MINOR__)
#   define __COMPILER_VERSION_BUILD (0)
#   define __COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
 // Borland C++ compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_BORLAND
#	if (__BORLANDC__ == 0x200)
#   	define __COMPILER_VERSION_MAJOR (2)
#   	define __COMPILER_VERSION_MINOR (0)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__BORLANDC__ == 0x400)
#   	define __COMPILER_VERSION_MAJOR (3)
#   	define __COMPILER_VERSION_MINOR (0)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__BORLANDC__ == 0x410)
#   	define __COMPILER_VERSION_MAJOR (3)
#   	define __COMPILER_VERSION_MINOR (1)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__BORLANDC__ == 0x452)
#   	define __COMPILER_VERSION_MAJOR (4)
#   	define __COMPILER_VERSION_MINOR (0)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__BORLANDC__ == 0x500)
#   	define __COMPILER_VERSION_MAJOR (5)
#   	define __COMPILER_VERSION_MINOR (0)
#   	define __COMPILER_VERSION_BUILD (0)
#	else
#   	define __COMPILER_VERSION_MAJOR (__BORLANDC__ / 100)
#   	define __COMPILER_VERSION_MINOR (__BORLANDC__ - (__COMPILER_VERSION_MAJOR * 100))
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	endif
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
#elif defined(__TURBOC__)
// Borland Turbo C compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_BORLAND
#	if (__TURBOC__ == 0x295)
#   	define __COMPILER_VERSION_MAJOR (1)
#   	define __COMPILER_VERSION_MINOR (0)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__TURBOC__ == 0x296)
#   	define __COMPILER_VERSION_MAJOR (1)
#   	define __COMPILER_VERSION_MINOR (1)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__TURBOC__ == 0x297)
#   	define __COMPILER_VERSION_MAJOR (2)
#   	define __COMPILER_VERSION_MINOR (0)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	elif (__TURBOC__ == 0x201)
#   	define __COMPILER_VERSION_MAJOR (2)
#   	define __COMPILER_VERSION_MINOR (1)
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	else
#   	define __COMPILER_VERSION_MAJOR (__TURBOC__ / 100)
#   	define __COMPILER_VERSION_MINOR (__TURBOC__ - (__COMPILER_VERSION_MAJOR * 100))
#   	define __COMPILER_VERSION_BUILD (0)
#   	define __COMPILER_VERSION_PATCH (0)
#	endif
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
#else
    // Unknown compiler
#   define __COMPILER_TYPE          __COMPILER_TYPE_UNKNOWN
#   define __COMPILER_VERSION_MAJOR (0)
#   define __COMPILER_VERSION_MINOR (0)
#   define __COMPILER_VERSION_BUILD (0)
#   define __COMPILER_VERSION_PATCH (0)
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
#endif

/**
 * Detect the compiler toolset used to generate the binary code.
 */
#if defined(_MSC_VER) && defined(_WIN32)
#	if defined(__clang__)
#		if defined(__llvm__)
#			define __COMPILER_TOOLSET	__COMPILER_TOOLSET_MSVC_CLANG_LLVM
#		elif defined(__c2__)
#			define __COMPILER_TOOLSET	__COMPILER_TOOLSET_MSVC_CLANG_C2
#		endif
#	else
#		define __COMPILER_TOOLSET	__COMPILER_TOOLSET_MSVC
#	endif
#elif defined(__BORLANDC__) || defined(__TURBOC__) || defined(__CODEGEARC__)
#	if defined(__BORLANDC__)
#		define __COMPILER_TOOLSET	__COMPILER_TOOLSET_BORLAND_CPP
#	else
#		define __COMPILER_TOOLSET	__COMPILER_TOOLSET_BORLAND_TC
#	endif
#elif defined(__GNUC__)
#	if defined(__MINGW32__) || defined(__MINGW64__)
#		define __COMPILER_TOOLSET	__COMPILER_TOOLSET_GNUC_MINGW
#	elif defined(__CYGWIN__)
#		define __COMPILER_TOOLSET	__COMPILER_TOOLSET_GNUC_CYGWIN
#	else
#		define __COMPILER_TOOLSET	__COMPILER_TOOLSET_GNUC
#	endif
#else
#	define __COMPILER_TOOLSET	__COMPILER_TOOLSET_UNKNOWN
#endif


/* Detect the CPU byte order */
#if defined(__BYTE_ORDER)
#    if (__BYTE_ORDER == __LITTLE_ENDIAN)
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#    elif (__BYTE_ORDER == __BIG_ENDIAN)
        // Machine is big endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN
#   elif (__BYTE_ORDER == __PDP_ENDIAN)
        // Machine is PDP endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN
#   else
        // Machine endian bit order is unknown
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN
#   endif
#elif defined(__GNUC__) && defined(__BYTE_ORDER__)
#   if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
        // Machine is big endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN
#   elif (__BYTE_ORDER__ == __ORDER_PDP_ENDIAN__)
        // Machine is PDP endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN
#   else
        // Machine endian bit order is unknown
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN
#   endif
#elif defined(_WIN32_WCE)
    // TODO: Windows CE processors
#   if defined(_M_IX86) || defined(_M_MRX000)
		// Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(_WIN64)
#   if defined(_M_X64) || defined(_M_AMD64) || defined(_AMD64_) || defined(__x86_64)
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(_WIN32)
#   if defined(_M_IX86) || defined(_X86_) || defined(_M_MRX000) || defined(_M_ALPHA) || defined(_M_PPC)
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(_WIN16) || defined(_DOS)
#   if defined(_M_I86)
		// Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(__APPLE__) || defined(__powerpc__) || defined(__ppc__)
#   if __LITTLE_ENDIAN__
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   elif __BIG_ENDIAN__
        // Machine is big endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN
#   endif
#elif   defined(__sparc) || defined(__sparc__) ||           \
        defined(_POWER) || defined(__hppa) ||               \
        defined(_MIPSEB) || defined(__ARMEB__) ||           \
        defined(__s390__) || defined(__AARCH64EB__) ||      \
        (defined(__sh__) && !defined(__LITTLE_ENDIAN__)) || \
        (defined(__ia64) && defined(__BIG_ENDIAN__))
    // Machine is big endian bit order
#   define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN
#elif   defined(__i386) || defined(__i386__) ||          \
        defined(__x86_64) || defined(__x86_64__) ||      \
        defined(_MIPSEL) || defined(__ARMEL__) ||        \
        defined(__alpha__) || defined(__AARCH64EL__) ||  \
        (defined(__sh__) && !defined(__BIG_ENDIAN__)) || \
        (defined(__ia64) && defined(__LITTLE_ENDIAN__))
    // Machine is little endian bit order
#   define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#else
#   define TMP_LITTLE_ENDIAN    0x41424344UL
#   define TMP_BIG_ENDIAN       0x44434241UL
#   define TMP_WSLE_ENDIAN      0x42414443UL
#   define TMP_WSBE_ENDIAN      0x43444142UL
#   define TMP_ENDIAN_ORDER ('ABCD')
#   if TMP_ENDIAN_ORDER == TMP_LITTLE_ENDIAN
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   elif TMP_ENDIAN_ORDER == TMP_BIG_ENDIAN
        // Machine is big endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN
#   elif TMP_ENDIAN_ORDER == TMP_WSLE_ENDIAN
        // Machine is PDP-11 endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN
#   elif TMP_ENDIAN_ORDER == TMP_WSBE_ENDIAN
        // Machine is Honeywell 316 endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN
#   else
        // Machine endian bit order is unknown
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN
#   endif
#   undef   TMP_LITTLE_ENDIAN
#   undef   TMP_BIG_ENDIAN
#   undef   TMP_WSLE_ENDIAN
#   undef   TMP_WSBE_ENDIAN
#   undef   TMP_ENDIAN_ORDER
#endif

#if defined(_AMD64_) || defined(__x86_64__) || defined(_M_AMD64) || defined(_M_X64)
    // AMD 64 / Intel EM64T / x86_64 64-bit
#   define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_AMD_64
#   define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_64
#   if !defined(__COMPILER_CPU_BYTE_ORDER) || (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN)
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(__i386__) || defined(i386) || defined(_X86_) || defined(_M_IX86)
    // Intel IA-32 / i386 / x86 32-bit
#   define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_INTEL_IA32
#   define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_32
#   if !defined(__COMPILER_CPU_BYTE_ORDER) || (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN)
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(__ia64__) || defined(_M_IA64)
    // Intel Itanium / IA-64
#   define __COMPILER_CPU_FAMILY __COMPILER_CPU_FAMILY_INTEL_IA64
#   if !defined(__COMPILER_CPU_BYTE_ORDER) || (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN)
#       if defined(__ia64__) && !defined(__LP64__)
            // 32-bit mode on Itanium
#           define __COMPILER_CPU_BITS __COMPILER_CPU_BITS_32
#       else
#           define __COMPILER_CPU_BITS __COMPILER_CPU_BITS_64
#       endif
#   endif
#elif defined(__alpha64__) || defined(_M_ALPHA64)
    // DEC Alpha 64-bit
#   define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_ALPHA_64
#   define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_64
#elif defined(__alpha__) || defined(_M_ALPHA)
    // DEC Alpha 32-bit
#   define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_ALPHA_32
#   define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_32
#elif (defined(__mips__) || defined(mips) || defined(__mips) || defined(_MIPSEL) || defined(_MIPSEB) || defined(_M_MRX000))
    // MIPS
#   if defined(_ABIO32) || defined(_M_MRX000)
#       define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_MIPS_32
#       define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_32
#   else
#       define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_MIPS_64
#       define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_64
#   endif
#elif defined(__ppc64__) || defined(__PPC64__)
    // PowerPC 64-bit
#   define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_PPC_64
#   define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_64
#elif   defined(__ppc__) || defined(__PPC__) || defined(__powerpc__) || defined(__powerpc) || \
        defined(__POWERPC__) || defined(__PPC) || defined(_M_PPC)
    // PowerPC 32-bit
#   define __COMPILER_CPU_FAMILY    __COMPILER_CPU_FAMILY_PPC_32
#   define __COMPILER_CPU_BITS      __COMPILER_CPU_BITS_32
#endif

/* Fix OS subtype */
#if __COMPILER_CPU_BITS == __COMPILER_CPU_BITS_64
#   if __COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_LINUX
        // Linux
#       undef __COMPILER_PLATFORM_SUBTYPE
#       define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_LINUX_64
#   elif __COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_BSD
#       if __COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32
            // FreeBSD
#           undef __COMPILER_PLATFORM_SUBTYPE
#           define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_64
#       elif __COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32
            // NetBSD
#           undef __COMPILER_PLATFORM_SUBTYPE
#           define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64
#       elif __COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32
            // OpenBSD
#           undef __COMPILER_PLATFORM_SUBTYPE
#           define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64
#       endif
#   elif __COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_MACOS
        // Mac OS X
#       undef __COMPILER_PLATFORM_SUBTYPE
#       define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MACOS_X_64
#   endif
#endif
/* Check if the CPU byte order is valid */
#if     (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN) || (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN) || \
        (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN) || (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN)
    // OK
#   if (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN) || (__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN)
        // Machine PDP endian bit order is not supported
#       error "Can't handle middle-endian or mixed-endian architectures"
#   endif
#else
    // Machine endian bit order is unknown
    #   define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_UNKNOWN_ENDIAN
#   error "Can't determine endianness"
#endif


#endif // _COMPILERINFO_H_
