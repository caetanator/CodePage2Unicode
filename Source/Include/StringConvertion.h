
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
	// C++11 standart compilent
	enum class StringConvertionEncodingType : int 
#else
	// Not C++11 standart compilent
	enum StringConvertionEncodingType
#endif
	{ 
		SET_UNKNOWNN = 0,
		SET_CHAR, 
		SET_WCHAR, 
		SET_UTF8, 
		SET_UTF16,
		SET_UTF32 
	};

	/**
	 *
	 */
#if __cplusplus >= 201103L
	// C++11 standart compilent
	enum class StringConvertionCodePage : int 
#else
	// Not C++11 standart compilent
	enum StringConvertionCodePage 
#endif
	{ 
		SCP_UNKNOWNN = 0,	// Unknown
		SCP_UCS_2,		// Unicode UCS-2 (2-byte Universal Character Set), maps to UTF-16 BMP (Basic Multilingual Plane) code point
		SCP_UCS_4,		// Unicode UCS-4 (4-byte Universal Character Set), maps to UTF-32
		SCP_UTF_8,		// Unicode UTF-8 (8 bits, 1 to 6 bytes Unicode Transformation Format)
		SCP_UTF_16,		// Unicode UTF-16 (16 bits, 2 or 4 bytes Unicode Transformation Format)
		SCP_UTF_32,		// Unicode UTF-32(32 bits, 4-bytes Unicode Transformation Format)
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
		// Byte Order Marker for UTF-7
		static const uint8_t bomUTF7[];
		// Byte Order Marker for UTF-8 (not to be used): "ï»¿"
		static const uint8_t bomUTF8[];
		// Byte Order Marker for UTF-16LE: "þÿ"
		static const uint8_t bomUTF16LE[];
		// Byte Order Marker for UTF-16BE: "ÿþ"
		static const uint8_t bomUTF16BE[];
		// Byte Order Marker for UTF-32LE: "␀␀þÿ"
		static const uint8_t bomUTF32LE[];
		// Byte Order Marker for UTF-32BE: "ÿþ␀␀"
		static const uint8_t bomUTF32BE[];
		// The replacement character: "�"
		static const uint16_t replacementCharacter = 0xFFFD;

		typedef struct _MapCharSetStruct
		{
			StringConvertionCodePage codePage;
			const char * stringId;
		} MapCharSetStruct;
		static const  MapCharSetStruct m_mapCharSet[];
		
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
			this->m_encodingType = StringConvertionEncodingType::SET_UNKNOWNN;
			this->m_codePage = StringConvertionCodePage::SCP_UNKNOWNN;
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
		
		static StringConvertionCodePage getDefaultCodePage(void);

		static bool isUtf8(const uint8_t * str, size_t len, bool * unicodeFound = nullptr);

		static bool hasUtf8Bom(const string& str);

		static bool hasUtf16BeBom(const u16string& str);
		
		static bool hasUtf16LeBom(const u16string& str);

		inline static bool hasUtf16Bom(const u16string& str);

		static bool hasUtf32BeBom(const u32string& str);
		
		static bool hasUtf32LeBom(const u32string& str);

		inline static bool hasUtf32Bom(const u32string& str);

		bool hasUtfBom(void);

		void removeUtf8Bom(void);
		
		inline static int getNarrowCharByteSize(void)
		{
			return sizeof(char);
		};

		inline static int getWideCharByteSize(void)
		{
			return sizeof(wchar_t);
		};

		inline static int getTCharByteSize(void)
		{
			return sizeof(_TCHAR);
		};

		inline static bool isNarrowCharUtf8(void)
		{
			return (__CHAR_NARROW_TYPE == __CHAR_NARROW_TYPE_UTF8);
		};

		inline static bool isWideCharUtf16(void)
		{
			return (__CHAR_WIDE_TYPE == __CHAR_WIDE_TYPE_UTF16);
		};

		inline static bool isWideCharUtf32(void)
		{
			return (__CHAR_WIDE_TYPE == __CHAR_WIDE_TYPE_UTF32);
		};

		inline static bool isApplicationWideUnicode(void)
		{
			return (__CHAR_API_TYPE == __CHAR_API_TYPE_WIDE);
		};

		string getNarrow(void);

		wstring getWide(void);

		string getUtf8(void);

		u16string getUtf16(void);

		u32string getUtf32(void);

#ifdef _DEBUG
		static void resetOut(void);
		static void test1(const char * strNarrowFrom, const char * strNarrowTo, const StringConvertionCodePage fromCodePage, const char * strCodePageInfo);
		static void test2(const char * strNarrowFrom, const char * strNarrowTo, const StringConvertionCodePage toCodePage, const char * strCodePageInfo);
		static void test3(const char * strLocale, const char * strNarrow);
		static void test4(const char * strLocale, const wchar_t * strWide);
		static void doTests(void);
#endif
	};
} /* End CaetanoSoft namespace */

#endif /* _STRINGCONVERTION_H_ */
