/**
 * TargetVer.h
 *
 * ABSTRACT
 *  The following macros define the minimum required platform.  The minimum required platform
 *  is the earliest version of Windows, Internet Explorer etc. that has the necessary features to run
 *  your application.  The macros work by enabling all features available on platform versions up to and
 *  including the version specified.
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
 *	2016-02-20: Fixed typos and clarified use of some macros.
 */

#ifndef _TARGETVER_H_
#define _TARGETVER_H_

#pragma once


// Including WinSDKVer.h defines macros for the highest available Windows platform supported by the SDK/DDK.
#include <WinSDKVer.h>


// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.

// *  Minimum 16-bit Windows OS version needed to run this application
// +-------------------+--------+--------+
// |  Windows Version  | WinSDK | Value  |
// +-------------------+--------+--------+
// | Windows 1.*       |        | 0x0100 |
// | Windows 2.*       |        | 0x0200 |
// | Windows 3.0       |        | 0x0300 |
// | Windows 3.1, 3.11 |        | 0x030A |
// +-------------------+--------+--------+
#ifndef WINVER
// Change this to the appropriate value to target other versions of Windows 1.x/2.x/3.xx.
// This macro is also used/set by all other 32/64-bit versions of Windows SDK/DDK.
//#	define WINVER 0x030A
#endif

// *  Minimum pseudo 32-bit Windows 95, 98, ME OS version needed to run this application  
// +--------------------+-------------+--------+
// | Windows 9x Version | WinSDKVer.h | Value  |
// +--------------------+-------------+--------+
// | Windows 95         |             | 0x0400 |
// | Windows 98, 98SE   |             | 0x0410 |
// | Windows ME         |             | 0x0490 |
// +--------------------+-------------+--------+
#ifndef _WIN32_WINDOWS
// Change this to the appropriate value to target Windows 95, Windows 98 or Windows ME.
//#	define _WIN32_WINDOWS 0x0410
#endif

// *  Minimum 32-bit and 64-bit Windows OS version needed to run this application
// +---------------------+----------------------+--------+
// | Windows NT Version  |     WinSDKVer.h      | Value  |
// +---------------------+----------------------+--------+
// | Windows NT 3.1      |                      | 0x0310 |
// | Windows NT 3.5      |                      | 0x0350 |
// | Windows NT 3.51     |                      | 0x0351 |
// | Windows NT 4.0      | _WIN32_WINNT_NT4     | 0x0400 |
// | Windows 2000        | _WIN32_WINNT_WIN2K   | 0x0500 |
// | Windows XP          | _WIN32_WINNT_WINXP   | 0x0501 |
// | Windows Server 2003 | _WIN32_WINNT_WS03    | 0x0502 |
// | Windows Vista       | _WIN32_WINNT_VISTA   | 0x0600 |
// | Windows Server 2008 | _WIN32_WINNT_WS08    | 0x0600 |
// | Windows 7           | _WIN32_WINNT_WIN7    | 0x0601 |
// | Windows 8           | _WIN32_WINNT_WIN8    | 0x0602 |
// | Windows 8.1         | _WIN32_WINNT_WINBLUE | 0x0603 |
// | Windows 10          | _WIN32_WINNT_WIN10   | 0x0A00 |
// +---------------------+----------------------+--------+
#ifndef _WIN32_WINNT
#	define _WIN32_WINNT 0x0601
#endif

// *  Minimum Windows CE, Mobile, Phone OS version needed to run this application
// +------------------------+-------------+-------+
// |   Windows CE Version   | WinSDKVer.h | Value |
// +------------------------+-------------+-------+
// | Windows CE 1.00        |             |       |
// | Windows CE 2.00        |             |       |
// | Windows CE 3.00        |             |   300 |
// | Windows Pocket PC 2003 |             |   420 |
// | Windows CE 5.00        |             |   500 |
// | Windows CE 6.00        |             |   600 |
// +------------------------+-------------+-------+
#ifndef _WIN32_WCE
// Change this to the appropriate value to target other versions of Windows CE, Mobile, Phone.
//#	define _WIN32_WCE 600
#endif

// *  Minimum Internet Explorer browser version needed to run this application
// * This is needed for the "ComCtl32.dll", "Shell32.dll" and "ShLWAPI.dll" versions shipped only with IE until Windows XP
// +---------------+-------------------+--------+--------------+---------+-------------+---------+-------------+---------+-------------------------------------------------------------------+
// |  IE Version   |    WinSDKVer.h    | Value  |  Common DLL  | Version |  Shell DLL  | Version | ShLWAPI DLL | Version |                          Distribution Platform                    |
// +---------------+-------------------+--------+--------------+---------+-------------+---------+-------------+---------+-------------------------------------------------------------------+
// | Win32s 16-bit |                   |        | COMMCTRL.DLL |    3.50 | SHELL.DLL   |    1.30 |             |         | Windows 3.1x + Win32s                                             |
// | Win32s 16-bit |                   |        | COMMCTRL.DLL |    3.51 | SHELL.DLL   |    3.51 |             |         | Windows 3.1x + Win32s                                             |
// | IE 1.x Win32  |                   |        | ComCtl32.dll |    3.51 | Shell32.dll |    3.51 |             |         | Windows NT 3.51                                                   |
// | IE 2.0x       |                   | 0x0200 | ComCtl32.dll |    4.00 | Shell32.dll |    4.00 | ShLWAPI.dll |    4.70 | Windows 95, Windows NT 4.0                                        |
// | IE 3.0x       |                   | 0x0300 | ComCtl32.dll |    4.70 | Shell32.dll |    4.00 | ShLWAPI.dll |    4.71 | Windows 95 OSR2, Windows NT 4.0 SP2                               |
// | IE 4.0x       |                   | 0x0400 | ComCtl32.dll |    4.72 | Shell32.dll |    4.72 | ShLWAPI.dll |    4.72 | Windows 95 OSR2.5, Windows 98, Windows NT 4.0 SP4                 |
// | IE 5.0        | _WIN32_IE_IE50    | 0x0500 | ComCtl32.dll |    5.80 | Shell32.dll |    4.72 | ShLWAPI.dll |    5.00 | Windows 98 SE                                                     |
// | IE 5.01       | _WIN32_IE_IE501   | 0x0501 | ComCtl32.dll |    5.81 | Shell32.dll |    5.00 | ShLWAPI.dll |    5.00 | Windows 2000                                                      |
// | IE 5.5        | _WIN32_IE_IE55    | 0x0550 | ComCtl32.dll |    5.82 | Shell32.dll |    5.50 | ShLWAPI.dll |    5.50 | Windows ME                                                        |
// | IE 6.0        | _WIN32_IE_IE60    | 0x0600 | ComCtl32.dll |    6.00 | Shell32.dll |    6.00 | ShLWAPI.dll |    6.00 | Windows XP (SxS), Windows XP x64 (SxS), Windows Server 2003 (SxS) |
// | IE 7.0        | _WIN32_IE_IE70    | 0x0700 | ComCtl32.dll |    6.00 | Shell32.dll |    6.00 | ShLWAPI.dll |    6.00 | Windows Vista (SxS), Windows Server 2008 (SxS)                    |
// | IE 8.0        | _WIN32_IE_IE80    | 0x0800 | ComCtl32.dll |    6.10 | Shell32.dll |    6.10 | ShLWAPI.dll |    6.10 | Windows 7 (SxS), Windows Server 2008 R2(SxS)                      |
// | IE 9.0        | _WIN32_IE_IE90    | 0x0900 | ComCtl32.dll |    6.10 | Shell32.dll |    6.10 | ShLWAPI.dll |    6.10 |                                                                   |
// | IE 10.0       | _WIN32_IE_IE100   | 0x0A00 | ComCtl32.dll |    6.10 | Shell32.dll |    6.10 | ShLWAPI.dll |    6.10 | Windows 8 (SxS), Windows Server 2012 (SxS)                        |
// | IE 11.0       | _WIN32_IE_IE110   | 0x0A00 | ComCtl32.dll |    6.10 | Shell32.dll |    6.10 | ShLWAPI.dll |    6.10 | Windows 8.1 (SxS), Windows Server 2012 R2 (SxS)                   |
// +---------------+-------------------+--------+--------------+---------+-------------+---------+-------------+---------+-------------------------------------------------------------------+
#ifndef _WIN32_IE
// Change this to the appropriate value to target other versions of IE.
#	define _WIN32_IE 0x0A00
#endif

// *  Minimum DDK version needed to run this application					 			
// +-------------------------+-----------------+-------------+
// |   Windows OS Version    |   WinSDKVer.h   |    Value    |
// +-------------------------+-----------------+-------------+
// | Windows 2000            | NTDDI_WIN2K     | 0x05000000  |
// | Windows 2000 SP1        | NTDDI_WIN2KSP1  | 0x05000100  |
// | Windows 2000 SP2        | NTDDI_WIN2KSP2  | 0x05000200  |
// | Windows 2000 SP3        | NTDDI_WIN2KSP3  | 0x05000300  |
// | Windows 2000 SP4        | NTDDI_WIN2KSP4  | 0x05000400  |
// | Windows XP              | NTDDI_WINXP     | 0x05010000  |
// | Windows XP SP1          | NTDDI_WINXPSP1  | 0x05010100  |
// | Windows XP SP2          | NTDDI_WINXPSP2  | 0x05010200  |
// | Windows XP SP3          | NTDDI_WINXPSP3  | 0x05010300  |
// | Windows Server 2003     | NTDDI_WS03      | 0x05020100  |
// | Windows Server 2003 SP1 | NTDDI_WS03SP1   | NTDDI_WS03  |
// | Windows Server 2003 SP2 | NTDDI_WS03SP2   | 0x05020200  |
// | Windows Server 2003 SP3 | NTDDI_WS03SP3   | 0x05020300  |
// | Windows Vista           | NTDDI_VISTA     | 0x06000000  |
// | Windows Vista SP1       | NTDDI_VISTASP1  | 0x06000100  |
// | Windows Vista SP2       | NTDDI_VISTASP2  | 0x06000200  |
// | Windows Server 2008     | NTDDI_WS08      | 0x06000100  |
// | Windows Server 2008 SP1 | NTDDI_WS08SP1   | NTDDI_WS08  |
// | Windows Server 2008 SP2 | NTDDI_WS08SP2   | 0x06000200  |
// | Windows 7               | NTDDI_WIN7      | 0x06010000  |
// | Windows 7 SP1           | NTDDI_WIN7SP1   | 0x06010100  |
// | Windows 8               | NTDDI_WIN8      | 0x06020000  |
// | Windows 8.1             | NTDDI_WINBLUE   | 0x06030000  |
// | Windows 10              | NTDDI_WIN10     | 0x0A000000  |
// +-------------------------+-----------------+-------------+
#ifndef NTDDI_VERSION
// Change this to the appropriate value to target other versions of DDK.
//#	define NTDDI_VERSION	0x06010000
#endif


// Including "SDKDDKVer.h" defines macros for the minimum supported Windows platform and IE for the EXE to run, 
// based on the above macros.
#include <SDKDDKVer.h>


// *  Minimum Rich Edit control version needed to run this application
// +-------------------+-----------------------------------------+--------+--------------+----------------+----------------------------------------------------------------------------------------------------+
// | Rich Edit Version |          Distribution Platform          | Value  |   DLL Name   |  Window Class  |                                               Notes                                                |
// +-------------------+-----------------------------------------+--------+--------------+----------------+----------------------------------------------------------------------------------------------------+
// | 1.0 16-bit        | Exchange 4.0 for Windows 3.1, 3.11 WFW  | 0x0100 | RICHEDIT.DLL | RICHEDIT_CLASS |                                                                                                    |
// | 1.0               | Windows 95, 98, ME, NT 4.0              | 0x0100 | RichEd32.dll | RICHEDIT_CLASS |                                                                                                    |
// | 2.0               | Office 97, Windows NT4.0, 98            | 0x0200 | RichEd20.dll | RICHEDIT_CLASS | RichEd20.dll is compatible with Windows 95 and may be installed by an application that requires it |
// | 2.1               | BiDi Office 97                          | 0x0210 | RichEd20.dll | RICHEDIT_CLASS |                                                                                                    |
// | 2.5               | Windows CE, Pocket Word                 | 0x0250 | RichEd20.dll | RICHEDIT_CLASS |                                                                                                    |
// | 3.0               | Office 2000, Windows ME, 2000, XP       | 0x0300 | RichEd20.dll | RICHEDIT_CLASS |                                                                                                    |
// | 3.1               | Windows Server 2003, Vista              | 0x0310 | RichEd20.dll | RICHEDIT_CLASS |                                                                                                    |
// | 3.5               | Windows CE, eBooks                      | 0x0350 | ebRichEd.dll | RICHEDIT_CLASS |                                                                                                    |
// | 4.0               | Office XP                               | 0x0400 | RichEd20.dll | RICHEDIT_CLASS |                                                                                                    |
// | 4.1               | Windows XP SP1, Tablet, Vista           | 0x0410 | RichEd20.dll | RICHEDIT_CLASS |                                                                                                    |
// | 5.0               | Office 2003                             | 0x0500 | MsftEdit.dll | MSFTEDIT_CLASS |                                                                                                    |
// | 5.1               | Windows CE, Pocket Word                 | 0x0510 | MsftEdit.dll | MSFTEDIT_CLASS |                                                                                                    |
// | 6.0               | Office 2007, Encarta Math Calculator    | 0x0600 | MsftEdit.dll | MSFTEDIT_CLASS |                                                                                                    |
// | 7.0               |                                         | 0x0700 | MsftEdit.dll | MSFTEDIT_CLASS |                                                                                                    |
// | 8.0               |                                         | 0x0800 | MsftEdit.dll | MSFTEDIT_CLASS |                                                                                                    |
// +-------------------+-----------------------------------------+--------+--------------+----------------+----------------------------------------------------------------------------------------------------+
#ifndef _RICHEDIT_VER
// Change this to the appropriate value to target other versions of Rich Edit control.
//#	define _RICHEDIT_VER	0x0410
#endif


// Exclude rarely-used stuff from Windows headers.
// Comment this if you want to include APIs such as Cryptography, DDE, RPC, Shell, and Windows Sockets.
// Define one or more of the NOapi symbols to exclude the API. For example, NOCOMM excludes the serial communication API.
// For a list of support NOapi symbols, see Windows.h.
#define WIN32_LEAN_AND_MEAN

// Enable strict type checking for Windows headers.
// Comment this if you don't want to enable features that require more care in declaring and using types.
#define STRICT

// These defines enable secure template overloads and disable C/POSIX warnings of insecure deprecated APIs.
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES	      0	// If 1, replaces unsafe standard C/C++ functions (without a counter) by safer functions (Ex.: strcpy -> strcpy_s)
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES_COUNT 0	// If 1, replaces unsafe standard C/C++ functions (with a counter) by safer functions (Ex.: strncpy -> strncpy_s)
#define _CRT_SECURE_NO_WARNINGS                         // No warnings for unsafe Standard C functions
#define _CRT_SECURE_NO_DEPRECATE                        // No deprecation for unsafe Standard C functions
#define _CRT_NONSTDC_NO_WARNINGS                        // No warnings for unsafe POSIX functions
#define _CRT_NONSTDC_NO_DEPRECATE                       // No deprecation for unsafe POSIX functions
#define _SCL_SECURE_NO_WARNINGS							// No warnings for unsafe Standard C++ Library methods
#define _SCL_SECURE_NO_DEPRECATE                        // No deprecation for unsafe Standard C++ Library methods

#pragma warning(disable: 4995)							// The above macros doesn't work any more on VC++ 2010 and above


// Creates the "_WIN16" macro for 16-bit Windows support
#if !defined(_WIN32) && !defined(_WIN64) && !defined(_WIN32_WCE) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__MINGW64__)
#	if defined(_WINDOWS) || (defined(WINVER) && (WINVER <= 0x030A))
// 16-bit Windows detected
#		if !defined(_WIN16)
#			define	_WIN16	1
#		endif
#	endif
#endif

#endif /* _TARGETVER_H_ */
