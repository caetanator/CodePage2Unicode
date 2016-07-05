/**
 * CompilerConfig.h
 *
 * ABSTRACT:
 *  Include file for  fixing compiler related differences.
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

#ifndef __COMPILERCONFIG_H_
#define __COMPILERCONFIG_H_

#pragma once


/**
 * Macros like M_PI, M_E, etc. may not be defined in <math.h> and <cmath>,
 * because are not part of the C and C++ standards.
 */
// For use with 'double'
// Provide enough digits for the 64-bit IEEE 754 double precision
#if !defined(M_E) || !defined(M_PI)
# define M_E            2.7182818284590452354         /* e */
# define M_LOG2E        1.4426950408889634074         /* log_2 e */
# define M_LOG10E       0.43429448190325182765        /* log_10 e */
# define M_LN2          0.69314718055994530942        /* log_e 2 */
# define M_LN10         2.30258509299404568402        /* log_e 10 */
# define M_PI           3.14159265358979323846        /* pi */
# define M_PI_2         1.57079632679489661923        /* pi/2 */
# define M_PI_4         0.78539816339744830962        /* pi/4 */
# define M_1_PI         0.31830988618379067154        /* 1/pi */
# define M_2_PI         0.63661977236758134308        /* 2/pi */
# define M_2_SQRTPI     1.12837916709551257390        /* 2/sqrt(pi) */
# define M_SQRT2        1.41421356237309504880        /* sqrt(2) */
# define M_SQRT1_2      0.70710678118654752440        /* 1/sqrt(2) */
#endif
// For use with 'long double'
// Provide enough digits for the 80/96-bit IEEE 754 extended precision
// and 128-bit IEEE 754 quadruple precision.
#if !defined(M_El) || !defined(M_PIl)
# define M_El            2.7182818284590452353602874713526625l  /* e */
# define M_LOG2El        1.4426950408889634073599246810018921l  /* log_2 e */
# define M_LOG10El       0.4342944819032518276511289189166051l  /* log_10 e */
# define M_LN2l          0.6931471805599453094172321214581766l  /* log_e 2 */
# define M_LN10l         2.3025850929940456840179914546843642l  /* log_e 10 */
# define M_PIl           3.1415926535897932384626433832795029l  /* pi */
# define M_PI_2l         1.5707963267948966192313216916397514l  /* pi/2 */
# define M_PI_4l         0.7853981633974483096156608458198757l  /* pi/4 */
# define M_1_PIl         0.3183098861837906715377675267450287l  /* 1/pi */
# define M_2_PIl         0.6366197723675813430755350534900574l  /* 2/pi */
# define M_2_SQRTPIl     1.1283791670955125738961589031215452l  /* 2/sqrt(pi) */
# define M_SQRT2l        1.4142135623730950488016887242096981l  /* sqrt(2) */
# define M_SQRT1_2l      0.7071067811865475244008443621048490l  /* 1/sqrt(2) */
#endif

/**
 * The _TCHAR and _MBCS macros and some ASCII char/MBCS/Unicode isolation functions defined in
 * <tchar.h> and <mbstring.h>  may not be implented, because this headers are Windows specific.
 */
#ifndef _TCHAR
    #if defined _UNICODE
			// Standard C wide character/string functions (Unicode API)
            #define _TCHAR      wchar_t
			#if !defined _T
				#define _T(quote)   L##quote
			#endif
			#if !defined _tmain
				#define _tmain      wmain
			#endif
			#if !defined _tstoi
				#define _tstoi      wtoi
			#endif
			#if !defined _tcserror
				#define _tcserror   wcserror
			#endif
			#if !defined _tcslen
				#define _tcslen     wcslen
			#endif
			#if !defined _tcschr
				#define _tcschr     wcschr
			#endif
			#if !defined _tcscpy
				#define _tcscpy     wcscpy
			#endif
			#if !defined _tcscat
				#define _tcscat     wcscat
			#endif
            #if !defined _tcscmp
				#define _tcscmp     wcscmp
			#endif
			#if !defined _tcscspn
				#define _tcscspn    wcscspn
			#endif
			#if !defined _totlower
				#define _totlower   towlower
			#endif
			#if !defined _totupper
				#define _totupper   towupper
			#endif
			#if !defined _int_t
				#define _int_t      wint_t
			#endif
			#if !defined _tfopen
				#define _tfopen     wfopen
			#endif
			#if !defined _tgetenv
				#define _tgetenv    wgetenv
			#endif
	#elif defined(_MBCS)
		// Standard C Multi-Byte character/string functions (MBCS API)
        #define _TCHAR      char
		#if !defined _T
				#define _T(quote)   quote
			#endif
			#if !defined _tmain
				#define _tmain      main
			#endif
			#if !defined _tstoi
				#define _tstoi      atoi
			#endif
			#if !defined _tcserror
				#define _tcserror   strerror
			#endif
			#if !defined _tcslen
				#define _tcslen     strlen
			#endif
			#if !defined _tcschr
				#define _tcschr     _mbschr
			#endif
			#if !defined _tcscpy
				#define _tcscpy     _mbscpy
			#endif
			#if !defined _tcscat
				#define _tcscat     _mbscat
			#endif
            #if !defined _tcscmp
				#define _tcscmp     _mbscmp
			#endif
			#if !defined _tcscspn
				#define _tcscspn    _mbscspn
			#endif
			#if !defined _totlower
				#define _totlower   tolower
			#endif
			#if !defined _totupper
				#define _totupper   toupper
			#endif
			#if !defined _int_t
				#define _int_t      int
			#endif
			#if !defined _tfopen
				#define _tfopen     fopen
			#endif
			#if !defined _tgetenv
				#define _tgetenv    getenv
			#endif
    #else
			// Standard C narrow character/string functions (ASCII API)
			#define _TCHAR      char
			#if !defined _T
				#define _T(quote)   quote
			#endif
			#if !defined _tmain
				#define _tmain      main
			#endif
			#if !defined _tstoi
				#define _tstoi      atoi
			#endif
			#if !defined _tcserror
				#define _tcserror   strerror
			#endif
			#if !defined _tcslen
				#define _tcslen     strlen
			#endif
			#if !defined _tcschr
				#define _tcschr     strchr
			#endif
			#if !defined _tcscpy
				#define _tcscpy     strcpy
			#endif
			#if !defined _tcscat
				#define _tcscat     strcat
			#endif
            #if !defined _tcscmp
				#define _tcscmp     strcmp
			#endif
			#if !defined _tcscspn
				#define _tcscspn    strcspn
			#endif
			#if !defined _totlower
				#define _totlower   tolower
			#endif
			#if !defined _totupper
				#define _totupper   toupper
			#endif
			#if !defined _int_t
				#define _int_t      int
			#endif
			#if !defined _tfopen
				#define _tfopen     fopen
			#endif
			#if !defined _tgetenv
				#define _tgetenv    getenv
			#endif
    #endif
#endif

/**
 * These macros abstracts from the ASCII narrow/MBCS/Unicode wide character
 * and string C++ file streams and strings classes.
 */
#if defined _UNICODE
	// Standard C++ wide character streams
	#define _tistream	std::wistream
	#define _tostream	std::wostream
	#define _tifstream	std::wifstream
	#define _tofstream	std::wofstream
	#define _tistringstream	std::wistringstream
	#define _tostringstream	std::wostringstream
	// Standard C++ wide character console streams
	#define _tcin       std::wcin
	#define _tcout      std::wcout
	#define _tcerr      std::wcerr
	#define _tclog      std::wclog
	// Standard C++ wide character strings
	#define _tstring    std::wstring
#elif defined(_MBCS)
	// Standard C++ multi-byte character streams
	#define _tistream	std::istream
	#define _tostream	std::ostream
	#define _tifstream	std::ifstream
	#define _tofstream	std::ofstream
	#define _tistringstream	std::istringstream
	#define _tostringstream	std::ostringstream
	// Standard C++ Multi-Byte character console streams
	#define _tcin       std::cin
	#define _tcout      std::cout
	#define _tcerr      std::cerr
	#define _tclog      std::clog
	// Standard C++ multi-byte character strings
	#define _tstring    std::string
#else
	// Standard C++ narrow character streams
	#define _tistream	std::istream
	#define _tostream	std::ostream
	#define _tifstream	std::ifstream
    #define _tofstream	std::ofstream
	#define _tistringstream	std::istringstream
	#define _tostringstream	std::ostringstream
	// Standard C++ narrow character console streams
	#define _tcin       std::cin
	#define _tcout      std::cout
	#define _tcerr      std::cerr
	#define _tclog      std::clog
	// Standard C++ narrow character strings
	#define _tstring    std::string
#endif

#endif // __COMPILERCONFIG_H_
