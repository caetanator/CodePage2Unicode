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
 */
 
#ifndef _TARGETVER_H_
#define _TARGETVER_H_

#pragma once


// Including WinSDKVer.h defines macros for the highest available Windows platform supported by the SDK/DDK.
#include <WinSDKVer.h>


// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.

// *  Minimum OS version for 16-bit Windows
// Specifies that the minimum required platform is Windows 3.1.
//	OS							WinSDKVer.h			Version
//	Windows 1.*										0x0100
//	Windows 2.*										0x0200
//	Windows 3.0										0x0300		
//	Windows 3.1, 3.11								0x030A
#ifndef WINVER
// Change this to the appropriate value to target other versions of Windows 1.x/2.x/3.xx.
//#	define WINVER 0x030A
#endif

// *  Minimum OS version for pseudo 32-bit Windows
// Specifies that the minimum required platform is Windows ME.
//	OS							WinSDKVer.h			Version
//	Windows 95										0x0400
//	Windows 98, 98SE								0x0410		
//	Windows ME								 		0x0490
#ifndef _WIN32_WINDOWS
// Change this to the appropriate value to target Windows 95, Windows 98 or Windows ME.
//#	define _WIN32_WINDOWS 0x0410
#endif

// *  Minimum OS version for 32/64-bit Windows
// Specifies that the minimum required platform is Windows Vista/Server 2008.
//	OS							WinSDKVer.h				Version
//	Windows NT 3.1										0x0310
//	Windows NT 3.5										0x0350
//	Windows NT 3.51										0x0351
//	Windows NT 4.0				_WIN32_WINNT_NT4		0x0400
//	Windows 2000				_WIN32_WINNT_WIN2K		0x0500
//	Windows XP					_WIN32_WINNT_WINXP 		0x0501
//	Windows Server 2003			_WIN32_WINNT_WS03 		0x0502
//	Windows Vista				_WIN32_WINNT_VISTA 		0x0600
//	Windows Server 2008			_WIN32_WINNT_WS08 		0x0600
//	Windows 7					_WIN32_WINNT_WIN7 		0x0601
//	Windows 8					_WIN32_WINNT_WIN8 		0x0602
//	Windows 8.1					_WIN32_WINNT_WINBLUE	0x0603
//	Windows 10					_WIN32_WINNT_WIN10		0x0A00
#ifndef _WIN32_WINNT
#	define _WIN32_WINNT 0x0601
#endif

// *  Minimum OS version for Windows CE/Mobile/Phone
// Specifies that the minimum required platform is Windows CE/Mobile/Phone.
#ifndef _WIN32_WCE
// Change this to the appropriate value to target other versions of Windows CE.
//#	define _WIN32_WCE 0x0600
#endif

// *  Minimum IE version needed
// Specifies that the minimum required platform is Internet Explorer 7.0.
//	IE							WinSDKVer.h			Version
//	IE 2.0									 		0x0200
//	IE 3.0, 3.01, 3.02						 		0x0300
//	IE 4.0									 		0x0400
//	IE 4.1									 		0x0401
//	IE 5.0, 5.0a, 5.0b			_WIN32_IE_IE50 		0x0500
//	IE 5.01						_WIN32_IE_IE501 	0x0501
//	IE 5.5						_WIN32_IE_IE55 		0x0550
//	IE 6.0						_WIN32_IE_IE60 		0x0600
//	IE 6.0 SP1					_WIN32_IE_IE60SP1 	0x0601
//	IE 6.0 SP2					_WIN32_IE_IE60SP2 	0x0603
//	IE 7.0						_WIN32_IE_IE70 		0x0700
//	IE 8.0						_WIN32_IE_IE80 		0x0800
//	IE 9.0						_WIN32_IE_IE90 		0x0900
//	IE 10.0						_WIN32_IE_IE100		0x0A00
//	IE 11.0						_WIN32_IE_IE110		0x0A00
#ifndef _WIN32_IE
// Change this to the appropriate value to target other versions of IE.
#	define _WIN32_IE 0x0A00        
#endif

// *  Minimum DDK version needed
//	OS							WinSDKVer.h		Version
//	Windows 2000				NTDDI_WIN2K 	0x05000000
//	Windows 2000 SP1			NTDDI_WIN2KSP1 	0x05000100
//	Windows 2000 SP2			NTDDI_WIN2KSP2 	0x05000200
//	Windows 2000 SP3			NTDDI_WIN2KSP3 	0x05000300
//	Windows 2000 SP4			NTDDI_WIN2KSP4 	0x05000400
//	Windows XP					NTDDI_WINXP 	0x05010000
//	Windows XP SP1				NTDDI_WINXPSP1 	0x05010100
//	Windows XP SP2				NTDDI_WINXPSP2 	0x05010200
//	Windows XP SP3				NTDDI_WINXPSP3 	0x05010300
//	Windows Server 2003			NTDDI_WS03 		0x05020000
//	Windows Server 2003 SP1		NTDDI_WS03SP1 	0x05020100
//	Windows Server 2003 SP2		NTDDI_WS03SP2 	0x05020200
//	Windows Vista				NTDDI_VISTA 	0x06000000
//	Windows Vista SP1			NTDDI_VISTASP1 	0x06000100
//	Windows Server 2008			NTDDI_WS08 		0x06000100
//	Windows 7					NTDDI_WIN7 		0x06010000
//	Windows 8					NTDDI_WIN8 		0x06020000
//	Windows 8.1					NTDDI_WINBLUE	0x06030000
//	Windows 10					NTDDI_WINBLUE	0x0A000000
#ifndef NTDDI_VERSION
// Change this to the appropriate value to target other versions of DDK.
//#	define NTDDI_VERSION	0x06010000
#endif


// Including SDKDDKVer.h defines macros for the minimum supported Windows platform and IE for the EXE to run, based on the above macros.
#include <SDKDDKVer.h>


// *  Minimum Rich Edit control version needed
// Specifies that Rich Edit control version expected.
// 	Version 		Ships ('ed) With 						DLL Name		Window Class		Notes
// 	1.0 16 bits		Exchange 4.0 for Windows 3.1/WFW 		richedit.dll	RICHEDIT_CLASS
// 	1.0 			Windows 95/98/ME/NT 4.0					Riched32.dll	RICHEDIT_CLASS
// 	1.0 emulator 	Office 2000, Windows 2000/XP/Vista 		Riched32.dll	RICHEDIT_CLASS
// 	2.0 			Office 97, Windows NT4.0/98 			Riched20.dll	RICHEDIT_CLASS		Riched20.dll is compatible with Windows 95 and may be installed by an application that requires it
// 	2.1 			BiDi Office 97 							Riched20.dll	RICHEDIT_CLASS
// 	2.5 			Windows CE, Pocket Word 				Riched20.dll	RICHEDIT_CLASS
// 	3.0 			Office 2000, Windows ME/2000/XP 		Riched20.dll	RICHEDIT_CLASS
// 	3.1 			Windows Server 2003, Vista 				Riched20.dll	RICHEDIT_CLASS
// 	3.5 			Windows CE, eBooks 						ebriched.dll	RICHEDIT_CLASS
// 	4.0 			Office XP 								Riched20.dll	MSFTEDIT_CLASS
// 	4.1 			Windows XP SP1, Tablet, Vista 			Msftedit.dll	MSFTEDIT_CLASS
// 	5.0 			Office 2003 							Riched20.dll	MSFTEDIT_CLASS
// 	5.1 			Windows CE, Pocket Word 				Riched20.dll	MSFTEDIT_CLASS
// 	6.0 			Office 2007, Encarta Math Calculator 	Riched20.dll	MSFTEDIT_CLASS
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
#define _CRT_SECURE_NO_WARNINGS                         // No standard C functions deprecation warnings
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_WARNINGS                        // No POSIX C functions deprecation warnings
#define _CRT_NONSTDC_NO_DEPRECATE
#define _SCL_SECURE_NO_WARNINGS							// No standard C functions deprecation warnings
#define _SCL_SECURE_NO_DEPRECATE
 
#pragma warning(disable: 4995)							// The above macros doesn't work any more on VC++ 2010 and above


// Creates the "_WIN16" macro for 16-bit Windows support
#if !defined(_WIN32) && !defined(_WIN64) && !defined(_WIN32_WCE) && !defined(__MINGW32__) && !defined(__MINGW64__)
#	if defined(_WINDOWS) || (defined(WINVER) && (WINVER <= 0x030A))
// 16-bit Windows detected
#		if !defined(_WIN16)
#			define	_WIN16	1
#		endif
#	endif
#endif

#endif /* _TARGETVER_H_ */
