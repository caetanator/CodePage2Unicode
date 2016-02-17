/**
 * CompilerInfo.h
 *
 * ABSTRACT
 *  Include file for detecting compiler related information.
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

#ifndef _COMPILERINFO_H_
#define _COMPILERINFO_H_

#pragma once

// Machine compiler type
/*
 *  These macros are for detect the machine compiler type __COMPILER_TYPE is set as follows:
 * __COMPILER_TYPE_UNKNOWN  -> Unknown
 * __COMPILER_TYPE_MSVC     -> Microsoft Visual C++
 * __COMPILER_TYPE_MINGW    -> MinGW
 * __COMPILER_TYPE_GCC      -> GNU Compiler Collection
 * __COMPILER_TYPE_CLANG    -> CLang/LLVM
 * __COMPILER_VERSION_MAJOR	-> Compiler major version
 * __COMPILER_VERSION_MINOR	-> Compiler minor version
 * __COMPILER_VERSION_BUILD	-> Compiler build version
 * __COMPILER_VERSION_PATCH	-> Compiler patch level version
 * __COMPILER_VERSION		-> Compiler full version
 */
#define __COMPILER_TYPE_UNKNOWN     0
#define __COMPILER_TYPE_MSVC        1
#define __COMPILER_TYPE_MINGW       2
#define __COMPILER_TYPE_GCC         3
#define __COMPILER_TYPE_CLANG       4
#define __COMPILER_TYPE_STRING	(													\
	(__COMPILER_TYPE == __COMPILER_TYPE_MSVC) ? _T("Microsoft Visual C++") : ( 		\
	(__COMPILER_TYPE == __COMPILER_TYPE_MINGW) ? _T("MinGW") : ( 					\
	(__COMPILER_TYPE == __COMPILER_TYPE_GCC) ? _T("GNU Compiler Collection") : ( 	\
	(__COMPILER_TYPE == __COMPILER_TYPE_CLANG) ? _T("Clang/LLVM") : (				\
	_T("Unknown")))))																\
)

// Machine platform OS type
/*
 *  These macros are for detect the machine platform OS type __COMPILER_PLATFORM_TYPE is set as follows:
 * __COMPILER_PLATFORM_TYPE_UNKNOWN     -> Unknown
 * __COMPILER_PLATFORM_TYPE_WINDOWS     -> Windows
 * __COMPILER_PLATFORM_TYPE_LINUX       -> Linux
 * __COMPILER_PLATFORM_TYPE_MACOS       -> Mac OS
 * __COMPILER_PLATFORM_TYPE_UNIX        -> UNIX based OS
 * __COMPILER_PLATFORM_TYPE_POSIX       -> POSIX compatible OS
 * __COMPILER_PLATFORM_TYPE_BSD         -> BSD
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
#define __COMPILER_PLATFORM_TYPE_STRING	(														\
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_WINDOWS) ? _T("Microsoft Windows") : ( \
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_LINUX) ? _T("Linux") : ( 				\
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_MACOS) ? _T("Apple MacOS") : ( 		\
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_BSD) ? _T("BSD") : (					\
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_UNIX) ? _T("UNIX") : ( 				\
	(__COMPILER_PLATFORM_TYPE == __COMPILER_PLATFORM_TYPE_POSIX) ? _T("POSIX") : (				\
	_T("Unknown")))))))																			\
)

// Machine platform hardware
/*
 *  These macros are for detect the machine platform OS hardware __COMPILER_PLATFORM_SUBTYPE is set as follows:
 * __COMPILER_PLATFORM_SUBTYPE_UNKNOWN			-> Unknown
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE		-> Windows CE 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET	-> Windows CE.NET 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32       -> Windows 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64       -> Windows 64-bit
 * __COMPILER_PLATFORM_SUBTYPE_MINGW_32			-> MinGW Windows 32-bit
 * __COMPILER_PLATFORM_SUBTYPE_MINGW_64			-> MinGW Windows 64-bit
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
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16      11
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32      12
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64      13
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE      14
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET  15
#define __COMPILER_PLATFORM_SUBTYPE_MINGW_32        16
#define __COMPILER_PLATFORM_SUBTYPE_MINGW_64        17
#define __COMPILER_PLATFORM_SUBTYPE_CYGWIN			18
#define __COMPILER_PLATFORM_SUBTYPE_WINDOWS_RT      19
#define __COMPILER_PLATFORM_SUBTYPE_LINUX_32        21
#define __COMPILER_PLATFORM_SUBTYPE_LINUX_64        22
#define __COMPILER_PLATFORM_SUBTYPE_MACOS_32        31
#define __COMPILER_PLATFORM_SUBTYPE_MACOS_X_32      32
#define __COMPILER_PLATFORM_SUBTYPE_MACOS_X_64      33
#define __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32  61
#define __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_64  62
#define __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32   63
#define __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_64   64
#define __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32  65
#define __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64  66
#define __COMPILER_PLATFORM_SUBTYPE_STRING	(																	\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16) ? _T("Win16") : (					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_32) ? _T("Win32") : ( 					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_64) ? _T("Win64") : ( 					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE) ? _T("WinCE") : (					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_CE_NET) ? _T("WinCE .NET") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_WINDOWS_RT) ? _T("WinRT") : (					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MINGW_32) ? _T("MinGW32") : ( 					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MINGW_64) ? _T("MinGW64") : (					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_CYGWIN) ? _T("CygWin") : ( 						\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_LINUX_32) ? _T("Linux32") : ( 					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_LINUX_64) ? _T("Linux64") : (					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MACOS_32) ? _T("MacOS32") : (					\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MACOS_X_32) ? _T("MacOS_X32") : (				\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_MACOS_X_64) ? _T("MacOS_X64") : (				\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_32) ? _T("FreeBSD32") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_FREEBSD_64) ? _T("FreeBSD64") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_32) ? _T("NetBSD32") : (				\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_NETBSD_64) ? _T("NetBSD64") : (				\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_32) ? _T("OpenBSD32") : (			\
	(__COMPILER_PLATFORM_SUBTYPE == __COMPILER_PLATFORM_SUBTYPE_BSD_OPENBSD_64) ? _T("OpenBSD64") : (			\
	_T("Unknown")))))))))))))))))))))																			\
)

// Machine CPU family
/*
 *  These macros are for detect the machine CPU family __COMPILER_CPU_FAMILY is set as follows:
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

// Machine CPU bits
/*
 *  These macros are for detect the machine CPU bits __COMPILER_CPU_BITS is set as follows:
 * __COMPILER_CPU_BITS_UNKNOWN	-> Unknown
 * __COMPILER_CPU_BITS_16		-> 16-bit
 * __COMPILER_CPU_BITS_32		-> 32-bit
 * __COMPILER_CPU_BITS_64       -> 64-bit
 */
#define __COMPILER_CPU_BITS_UNKNOWN 0
#define __COMPILER_CPU_BITS_16  16
#define __COMPILER_CPU_BITS_32  32
#define __COMPILER_CPU_BITS_64  64

// Machine CPU byte order endianness
/*
 *  These macros are for detect the machine CPU endian type __COMPILER_CPU_BYTE_ORDER is set as follows:
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
#define __COMPILER_CPU_BYTE_ORDER_STRING	(														\
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN) ? _T("Little-Endian") : ( \
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN) ? _T("Big-Endian") : ( 		\
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSLE_ENDIAN) ? _T("WSLE-Endian") : ( 	\
	(__COMPILER_CPU_BYTE_ORDER == __COMPILER_CPU_BYTE_ORDER_WSBE_ENDIAN) ? _T("WSBE-Endian") : (	\
	_T("Unknown")))))																				\
)

/* Detect the OS platform */
#if defined(_WIN16) || defined(_WINDOWS) || (defined(WINVER) && (WINVER <= 0x030A))
    // Windows 16-bit
#error "ups"
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_WINDOWS_16
#   define __COMPILER_CPU_BYTE_ORDER    __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   define __COMPILER_CPU_BITS          __COMPILER_CPU_BITS_16
#   define __COMPILER_CPU_FAMILY        __COMPILER_CPU_FAMILY_INTEL_IA16
#elif defined(_WIN32)
// Windows (x64, x86, CE)
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#   if defined(_WIN64)
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
#elif defined(__MINGW64__)
    // Windows x64
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MINGW_64
#elif defined(__MINGW32__)
    // Windows x86
#       define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#       define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_MINGW_32
#elif defined(__CYGWIN__)
// Windows x86
#       define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_WINDOWS
#       define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_CYGWIN
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
#elif defined(__unix__) || defined(__unix) || defined(unix)
    // UNIX
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_UNIX
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_UNKNOWN
#elif defined(__posix__)
    // POSIX
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_POSIX
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_UNKNOWN
#else
    // Unknown
#   define __COMPILER_PLATFORM_TYPE     __COMPILER_PLATFORM_TYPE_UNKNOWN
#   define __COMPILER_PLATFORM_SUBTYPE  __COMPILER_PLATFORM_SUBTYPE_UNKNOWN
#endif

/* Detect the compiler used to generate the binary code */
#if defined(_MSC_VER) && !defined(__clang__)
    // Microsoft Visual C++ compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_MSVC
#   define __COMPILER_VERSION_MAJOR (_MSC_VER / 100)
#   define __COMPILER_VERSION_MINOR (_MSC_VER - (__COMPILER_VERSION_MAJOR * 100))
#   define __COMPILER_VERSION_BUILD (_MSC_BUILD)
#   define __COMPILER_VERSION_PATCH (_MSC_FULL_VER - (_MSC_VER * 100000))
#   define __COMPILER_VERSION       (_MSC_FULL_VER)
#elif defined(__MINGW64__)
    // MinGW 64-bit compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_MINGW
#   define __COMPILER_VERSION_MAJOR (__MINGW64_VERSION_MAJOR)
#   define __COMPILER_VERSION_MINOR (__MINGW64_VERSION_MINOR)
#   define __COMPILER_VERSION_BUILD (0)
#   define __COMPILER_VERSION_PATCH (__MINGW64_VERSION_PATCHLEVEL)
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
#elif defined(__MINGW32__)
    // MinGW 32-bit compiler detected
#   define __COMPILER_TYPE          __COMPILER_TYPE_MINGW
#   define __COMPILER_VERSION_MAJOR (__MINGW32_VERSION_MAJOR)
#   define __COMPILER_VERSION_MINOR (__MINGW32_VERSION_MINOR)
#   define __COMPILER_VERSION_BUILD (0)
#   define __COMPILER_VERSION_PATCH (__MINGW32_VERSION_PATCHLEVEL)
#   define __COMPILER_VERSION       ((__COMPILER_VERSION_MAJOR * 10000) + (__COMPILER_VERSION_MINOR * 100) + __COMPILER_VERSION_PATCH)
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
#   define __COMPILER_VERSION_MAJOR (__GNUC__)
#   define __COMPILER_VERSION_MINOR (__GNUC_MINOR__)
#   define __COMPILER_VERSION_BUILD (0)
#   define __COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
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
#elif defined(_WIN64)
#   if defined(_M_X64) || defined(_M_AMD64) || defined(_AMD64_)
        // Machine is little endian bit order
#       define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_LITTLE_ENDIAN
#   endif
#elif defined(_WIN32)
#   if defined(_M_IX86) || defined(_M_AMD64) || defined(_M_MRX000) || defined(_M_ALPHA) || defined(_M_PPC)
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
#elif   defined(__sparc) || defined(__sparc__) || \
        defined(_POWER) || defined(__hppa) || \
        defined(_MIPSEB) || defined(__ARMEB__) || \
        defined(__s390__) || defined(__AARCH64EB__) || \
        (defined(__sh__) && !defined(__LITTLE_ENDIAN__)) || \
        (defined(__ia64) && defined(__BIG_ENDIAN__))
    // Machine is big endian bit order
#   define __COMPILER_CPU_BYTE_ORDER __COMPILER_CPU_BYTE_ORDER_BIG_ENDIAN
#elif   defined(__i386) || defined(__i386__) || \
        defined(__x86_64) || defined(__x86_64__) || \
        defined(_MIPSEL) || defined(__ARMEL__) || \
        defined(__alpha__) || defined(__AARCH64EL__) || \
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
