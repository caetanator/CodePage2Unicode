/**
 * CodePage2Unicode.cpp
 *
 * ABSTRACT
 *  Implementation of the CodePage2Unicode API and objects that convert strings from ASCII to Unicode and vice versa.
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
 
#ifndef _STRINGCONVERTION_H_
#define _STRINGCONVERTION_H_

#pragma once


#include "StdAfx.h"

#include "CompilerEnvironment.h"


using namespace std;


namespace CaetanoSoft
{

	/**
	 *
	 */
#if __cplusplus >= 201103L
	// C++11 standard compliment
	enum class StringConvertionCodePage : int 
#else
	// Not C++11 standard compliment
	enum StringConvertionCodePage 
#endif
	{ 
		SCP_UNKNOWN = 0,	// Unknown
		SCP_UCS_2,		// Unicode UCS-2 (2-byte Universal Character Set), maps to UTF-16 BMP (Basic Multilingual Plane) code point
		SCP_UCS_4,		// Unicode UCS-4 (4-byte Universal Character Set), maps to UTF-32
		SCP_UTF_8,		// Unicode UTF-8 (8-bit, 1 to 6 bytes Unicode Transformation Format)
		SCP_UTF_16,		// Unicode UTF-16 (16-bit, 2 or 4 bytes Unicode Transformation Format)
		SCP_UTF_32,		// Unicode UTF-32(32-bit, 4-bytes Unicode Transformation Format)
		SCP_ISO8859_1,	// ISO-8859-1: ISO Latin 1; ANSI Western European
		SCP_ISO8859_15, // ISO-8859-15: ISO Latin 9; ANSI Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € insted of ¤)
		SCP_CP1252,		// Windows-1252: ANSI Latin 1 + €; Windows Western European (same as ISO-8859-1, but with more printing characters insted of control codes defined like the €)
		SCP_CP437,		// IBM437: OEM USA; DOS USA
		SCP_CP850,		// IBM850: OEM Multilingual Latin 1; DOS Western European
		SCP_CP858,		// IBM858: OEM Multilingual Latin 1  + €; DOS Western European + € (same as IBM850, but with € insted of ı)
		SCP_CP860,		// IBM860: OEM Portuguese; DOS Portuguese
		SCP_MacRoman	// MacRoman: Macintosh Latin 1; Mac Western European (in Mac OS 8.5 and above, the character ¤ was replaced by €)
	};

	/**
	 *
	 */
	class StringConvertion 
	{
	  private:
		StringConvertionEncodingType m_encodingType;

		StringConvertionCodePage m_codePage;

		union _m_string 
		{
			string    * narrowString;
			wstring   * wideString;
			string    * utf8String;
			u16string * utf16String;
			u32string * utf32String;
		} m_string;

		// Default constructor
		explicit StringConvertion(void)
		{
			this->m_encodingType = StringConvertionEncodingType::SET_UNKNOW;
			this->m_codePage = StringConvertionCodePage::SCP_UNKNOW;
			this->m_string.utf32String = nullptr;
		};

	  public:
		// Narrow ASCII and Unicode UTF-8 character constructor
		explicit StringConvertion(const char * str);

		// Narrow ASCII and Unicode UTF-8 string constructor
		explicit StringConvertion(const string& str);

		// Wide Unicode character constructor
		explicit StringConvertion(const wchar_t * str);

		// Wide Unicode string constructor
		explicit StringConvertion(const wstring& str);

		// Unicode UTF-16 character constructor
		explicit StringConvertion(const char16_t * str);

		// Unicode UTF-16 string constructor
		explicit StringConvertion(const u16string& str);

		// Unicode UTF-32 character constructor
		explicit StringConvertion(const char32_t * str);
		
		// Unicode UTF-32 string constructor
		explicit StringConvertion(const u32string& str);

		// Destructor
		~StringConvertion(void);

		// Convert to a native narrow ASCII string from a native wide Unicode  string
		static string wide2Narrow(const wstring &strWideNative);

		// Convert to a native wide Unicode string from a native narrow ASCII string
		static wstring narrow2Wide(const string &strNarrowNative);

		// Convert a native  narrow string from a given code page to the default code page
		static string convertFromCodePage(const string &strNarrowNative, const StringConvertionCodePage fromCodePage);

		// Convert a native  narrow string from the default code page to a given code page
		static string convertToCodePage(const string &strNarrowNative, const StringConvertionCodePage toCodePage);
	};
} /* End CaetanoSoft namespace */

#endif /* _STRINGCONVERTION_H_ */
