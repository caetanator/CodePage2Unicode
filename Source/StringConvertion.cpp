
#include "StdAfx.h"

#include "StringConvertion.h"

using namespace std;
using namespace CaetanoSoft;


// UTF-7 BOM - (5 bytes, endianless)
const uint8_t StringConvertion::bomUTF7[]    = { 0x2B, 0x2F, 0x76, 0x38, 0x2D, '\0' };
// UTF-8 BOM - (3 bytes, endianless, should not be used)
const uint8_t StringConvertion::bomUTF8[]    = { 0xEF, 0xBB, 0xBF, '\0' };
// UTF-16 BOM - (2 bytes, little endian)
const uint8_t StringConvertion::bomUTF16LE[] = { 0xFE, 0xFF, '\0' };
// UTF-16 BOM - (2 bytes, big endian)
const uint8_t StringConvertion::bomUTF16BE[] = { 0xFF, 0xFE, '\0' };
// UTF-32 BOM - (4 bytes, little endian)
const uint8_t StringConvertion::bomUTF32LE[] = { 0x00, 0x00, 0xFE, 0xFF, '\0' };
// UTF-32 BOM - (4 bytes, big endian)
const uint8_t StringConvertion::bomUTF32BE[] = { 0xFF, 0xFE, 0x00, 0x00, '\0' };

// http://unicodebook.readthedocs.org/guess_encoding.html
void encode_utf16_pair(uint32_t character, uint16_t *units)
{
    unsigned int code;
    assert(0x10000 <= character && character <= 0x10FFF);
    code = (character - 0x10000);
    units[0] = 0xD800 | (code >> 10);
    units[1] = 0xDC00 | (code & 0x3FF);
}

uint32_t decode_utf16_pair(uint16_t *units)
{
    uint32_t code;
    assert(0xD800 <= units[0] && units[0] <= 0xDBFF);
    assert(0xDC00 <= units[1] && units[1] <= 0xDFFF);
    code = 0x10000;
    code += (units[0] & 0x03FF) << 10;
    code += (units[1] & 0x03FF);
    return code;
}

const  StringConvertion::MapCharSetStruct StringConvertion::m_mapCharSet[] = 
{
	{ StringConvertionCodePage::SCP_UNKNOW,		"" },
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
	// Unicode UCS-2 (2-byte Universal Character Set), maps to UTF-16 BMP (Basic Multilingual Plane) code point
	{ StringConvertionCodePage::SCP_UCS_2,		".1200@UCS" }, 
	// Unicode UCS-4 (4-byte Universal Character Set), maps to UTF-32
	{ StringConvertionCodePage::SCP_UCS_4,		".12000@UCS" }, 
	// Unicode UTF-8 (8 bits, 1 to 6 bytes Unicode Transformation Format)
	{ StringConvertionCodePage::SCP_UTF_8,		".65001" },	
	// Unicode UTF-16 (16 bits, 2 or 4 bytes Unicode Transformation Format)
	{ StringConvertionCodePage::SCP_UTF_16,		".1200" },	
	// Unicode UTF-32(32 bits, 4-bytes Unicode Transformation Format)
	{ StringConvertionCodePage::SCP_UTF_32,		".12000" },
	// ISO-8859-1: ISO Latin 1; ANSI Western European
	{ StringConvertionCodePage::SCP_ISO8859_1,	".28591" },
	// ISO-8859-15: ISO Latin 9; ANSI Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € insted of ¤)
	{ StringConvertionCodePage::SCP_ISO8859_15,	".28605@euro" },
	// Windows-1252: ANSI Latin 1 + €; Windows Western European (same as ISO-8859-1, but with more printing characters insted of control codes defined like the €)
	{ StringConvertionCodePage::SCP_CP1252,		".1252@euro" },
	// IBM437: OEM USA; DOS USA
	{ StringConvertionCodePage::SCP_CP437,		".437" },
	// IBM850: OEM Multilingual Latin 1; DOS Western European
	{ StringConvertionCodePage::SCP_CP850,		".850" },
	// IBM858: OEM Multilingual Latin 1  + €; DOS Western European + € (same as IBM850, but with € insted of ı)
	{ StringConvertionCodePage::SCP_CP858,		".858@euro" },
	// IBM860: OEM Portuguese; DOS Portuguese
	{ StringConvertionCodePage::SCP_CP860,		".860" },
	// MacRoman: Macintosh Latin 1; Mac Western European
	{ StringConvertionCodePage::SCP_MacRoman,	".10000@euro" }
#else
	// Unicode UCS-2 (2-byte Universal Character Set), maps to UTF-16 BMP (Basic Multilingual Plane) code point
	{ StringConvertionCodePage::SCP_UCS_2,		".UTF-16@UCS" }, 
	// Unicode UCS-4 (4-byte Universal Character Set), maps to UTF-32
	{ StringConvertionCodePage::SCP_UCS_4,		".UTF-32@UCS" }, 
	// Unicode UTF-8 (8 bits, 1 to 6 bytes Unicode Transformation Format)
	{ StringConvertionCodePage::SCP_UTF_8,		".UTF-8" }, 
	// Unicode UTF-16 (16 bits, 2 or 4 bytes Unicode Transformation Format)
	{ StringConvertionCodePage::SCP_UTF_16,		".UTF-16" },	
	// Unicode UTF-32(32 bits, 4-bytes Unicode Transformation Format)
	{ StringConvertionCodePage::SCP_UTF_32,		".UTF-32" },
	// ISO-8859-1: ISO Latin 1; ANSI Western European
	{ StringConvertionCodePage::SCP_ISO8859_1,	".ISO-8859-1" },
	// ISO-8859-15: ISO Latin 9; ANSI Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € insted of ¤)
	{ StringConvertionCodePage::SCP_ISO8859_15,	".ISO-8859-15" },
	// Windows-1252: ANSI Latin 1 + €; Windows Western European (same as ISO-8859-1, but with more printing characters insted of control codes defined like the €)
	{ StringConvertionCodePage::SCP_CP1252,		".CP1252" },
	// IBM437: OEM USA; DOS USA
	{ StringConvertionCodePage::SCP_CP437,		".CP437" },
	// IBM850: OEM Multilingual Latin 1; DOS Western European
	{ StringConvertionCodePage::SCP_CP850,		".CP850" },
	// IBM858: OEM Multilingual Latin 1  + €; DOS Western European + € (same as IBM850, but with € insted of ı)
	{ StringConvertionCodePage::SCP_CP858,		".CP858" },
	// IBM860: OEM Portuguese; DOS Portuguese
	{ StringConvertionCodePage::SCP_CP860,		".CP860" },
	// MacRoman: Macintosh Latin 1; Mac Western European (in Mac OS 8.5 and above, the character ¤ was replaced by €)
	{ StringConvertionCodePage::SCP_MacRoman,	".MACINTOSH" }
#endif
};

// Narrow, ASCII and UTF-8 character constructor
#if __cplusplus >= 201103L
	// C++11 standart compilent
	StringConvertion::StringConvertion(const char * str) : StringConvertion(string(str))
#else
	// Not C++11 standart compilent
	StringConvertion::StringConvertion(const char * str)
#endif
{
	// Do nothing
#if __cplusplus < 201103L
	// Not C++11 standart compilent
	*this = StringConvertion(string(str));
#endif
}

// Narrow, ASCII and UTF-8 string constructor
StringConvertion::StringConvertion(const string& str)
{
	// Validate parameters
	assert(&str != nullptr);

	// Check the type of string
	bool hasBOM = hasUtf8Bom(str);
	bool unicodeFound = hasBOM;
	if(hasBOM != true)
	{
		// Try to find the UTF-8 surgates markers
		size_t len = str.length();
		if(this->isUtf8((uint8_t *)str.c_str(), len, &unicodeFound) && unicodeFound)
		{
			// The string is UTF-8
			unicodeFound = true;
		}
	}
	
	if(unicodeFound)
	{
		// Found UTF-8 character
		this->m_encodingType = StringConvertionEncodingType::SET_UTF8;
		this->m_codePage = StringConvertionCodePage::SCP_UTF_8;
		this->m_string.utf8String = new string(str);
		
		if(hasBOM == true)
		{
			// Has UTF-8 BOM, so remove it, since it shouldn't be used as by the RFC 3629
			this->removeUtf8Bom();
		}
	}
	else
	{
		// String is ASCII
		this->m_encodingType = StringConvertionEncodingType::SET_CHAR;
		this->m_codePage = this->getDefaultCodePage();
		this->m_string.narrowString = new string(str);
	}
}

// Wide character constructor
StringConvertion::StringConvertion(const wchar_t * str)
{
	// Validate parameters
	assert(str != nullptr);

	this->m_encodingType = StringConvertionEncodingType::SET_WCHAR;
	if(this->getWideCharByteSize() == 2)
	{
		// Now days, all Windows OS use UTF-16 (Windows 9x/ME/NT and below use UCS-2, that is a subset of UTF-16)
		this->m_codePage = StringConvertionCodePage::SCP_UTF_16;
	}
	else
	{
		// Now days, all UNIX/Linux/BSD/POSIX OS use UTF-32 (older versions used UCS-4, that is a subset of UTF-32)
		this->m_codePage = StringConvertionCodePage::SCP_UTF_32;
	}
	this->m_string.wideString = new wstring(str);
}

// Wide string constructor
StringConvertion::StringConvertion(const wstring& str)
{
	// Validate parameters
	assert(&str != nullptr);

	this->m_encodingType = StringConvertionEncodingType::SET_WCHAR;
	if(this->getWideCharByteSize() == 2)
		this->m_codePage = StringConvertionCodePage::SCP_UTF_16;
	else
		this->m_codePage = StringConvertionCodePage::SCP_UTF_32;
	this->m_string.wideString = new wstring(str);
}

// UTF-16 character constructor
StringConvertion::StringConvertion(const char16_t * str)
{
	// Validate parameters
	assert(str != nullptr);

	this->m_encodingType = StringConvertionEncodingType::SET_UTF16;
	this->m_codePage = StringConvertionCodePage::SCP_UTF_16;
	this->m_string.utf16String = new u16string(str);
}

// UTF-16 string constructor
StringConvertion::StringConvertion(const u16string& str)
{
	// Validate parameters
	assert(&str != nullptr);

	this->m_encodingType = StringConvertionEncodingType::SET_UTF16;
	this->m_codePage = StringConvertionCodePage::SCP_UTF_16;
	this->m_string.utf16String = new u16string(str);
}

// UTF-32 character constructor
StringConvertion::StringConvertion(const char32_t * str)
{
	// Validate parameters
	assert(str != nullptr);

	if(str == nullptr)
		return;

	this->m_encodingType = StringConvertionEncodingType::SET_UTF32;
	this->m_codePage = StringConvertionCodePage::SCP_UTF_32;
	this->m_string.utf32String = new u32string(str);
}

// UTF-32 string constructor
StringConvertion::StringConvertion(const u32string& str)
{
	// Validate parameters
	assert(&str != nullptr);

	this->m_encodingType = StringConvertionEncodingType::SET_UTF32;
	this->m_codePage = StringConvertionCodePage::SCP_UTF_32;
	this->m_string.utf32String = new u32string(str);
}

// Destructor
StringConvertion::~StringConvertion(void)
{
	if(this->m_string.utf32String != nullptr)
	{
		delete this->m_string.utf32String;
		this->m_string.utf32String = nullptr;
		this->m_encodingType = StringConvertionEncodingType::SET_UNKNOW;
		this->m_codePage = StringConvertionCodePage::SCP_UNKNOW;
	}
}

// Convert to a native narrow ASCII string from a native wide Unicode  string
string StringConvertion::wide2Narrow(const wstring &strWideNative)
{
	// Validate parameters
	assert(&strWideNative != nullptr);

	locale nativeLocale; 
 
	// The character length will never be longer than the input string 
	vector<char> vChar(strWideNative.length() + 1); 
 
	// Convert 
	use_facet<ctype<wchar_t>>(nativeLocale).narrow(strWideNative.c_str(), strWideNative.c_str() + strWideNative.length() + 1, '?', &vChar[0]);
 
	return string(vChar.begin(), vChar.end()); 
}

// Convert to a native wide Unicode  string from a native narrow ASCII string
wstring StringConvertion::narrow2Wide(const string  &strNarrowNative)
{
	// Validate parameters
	assert(&strNarrowNative != nullptr);

	locale nativeLocale; 
 
	// The UTF-16 length will never be longer than the input string 
	vector<wchar_t> vUtf16(strNarrowNative.length() + 1); 
 
	// Convert 
	use_facet<ctype<wchar_t>>(nativeLocale).widen(strNarrowNative.c_str(), strNarrowNative.c_str() + strNarrowNative.length(), &vUtf16[0]);
 
	return wstring(vUtf16.begin(), vUtf16.end());
}

// Convert a native string from a given code page to the default code page
string StringConvertion::convertFromCodePage(const string &strNarrowNative, const StringConvertionCodePage fromCodePage)
{
	// Validate parameters
	assert(&strNarrowNative != nullptr);

	const char * strCharSet = StringConvertion::m_mapCharSet[(int)fromCodePage].stringId;

	size_t length = strNarrowNative.length();

	string strOut(strNarrowNative.size(), '\0');
	wstring wstrTemp(strNarrowNative.size() * sizeof(wchar_t), '\0');

	try
	{
		locale objNewLocaleFrom = locale(strCharSet);
		locale objNewLocaleTo = locale("");

		codecvt<wchar_t, char, mbstate_t>::result objResult;
		const codecvt<wchar_t, char, mbstate_t>& objFacetFrom = use_facet<codecvt<wchar_t, char, mbstate_t>>(objNewLocaleFrom);
		const codecvt<wchar_t, char, mbstate_t>& objFacetTo = use_facet<codecvt<wchar_t, char, mbstate_t>>(objNewLocaleTo);
		
		// Translate characters to Unicode :
		mbstate_t state = mbstate_t();
		const char * pInNext = nullptr;
		wchar_t * pwOutNext = nullptr;
		objResult = objFacetFrom.in(state, strNarrowNative.c_str(), strNarrowNative.c_str() + length, pInNext, const_cast<wchar_t *>(wstrTemp.c_str()), const_cast<wchar_t *>(wstrTemp.c_str() + length), pwOutNext);
		if(objResult == codecvt<wchar_t, char, mbstate_t>::ok)
		{
			// Translate Unicode to characters:
			const wchar_t * pwInNext = nullptr;
			char * pOutNext = nullptr;
			objResult = objFacetTo.out(state, wstrTemp.c_str(), wstrTemp.c_str() + length, pwInNext, const_cast<char *>(strOut.c_str()), const_cast<char *>(strOut.c_str() + length), pOutNext);
			if(objResult != codecvt<wchar_t, char, mbstate_t>::error)
			{
				// FIXME: Is this OK?
				// Do nothing
			}
		}
	}
	catch(runtime_error& e)
	{
		throw;
	}
	catch(...)
	{
		throw;
	}

	return strOut;
}

// Convert a native  narrow string from the default code page to a given code page
string StringConvertion::convertToCodePage(const string &strNarrowNative, const StringConvertionCodePage toCodePage)
{
	// Validate parameters
	assert(&strNarrowNative != nullptr);

	const char * strCharSet = StringConvertion::m_mapCharSet[(int)toCodePage].stringId;

	size_t length = strNarrowNative.length();

	string strOut(strNarrowNative.size(), '\0');
	wstring wstrTemp(strNarrowNative.size() * sizeof(wchar_t), '\0');

	try
	{
		locale objNewLocaleTo = locale(strCharSet);
		locale objNewLocaleFrom = locale("");

		codecvt<wchar_t, char, mbstate_t>::result objResult;
		const codecvt<wchar_t, char, mbstate_t>& objFacetTo = use_facet<codecvt<wchar_t, char, mbstate_t>>(objNewLocaleTo);
		const codecvt<wchar_t, char, mbstate_t>& objFacetFrom = use_facet<codecvt<wchar_t, char, mbstate_t>>(objNewLocaleFrom);
		
		// Translate characters to Unicode :
		mbstate_t state = mbstate_t();
		const char * pInNext = nullptr;
		wchar_t * pwOutNext = nullptr;
		objResult = objFacetFrom.in(state, strNarrowNative.c_str(), strNarrowNative.c_str() + length, pInNext, const_cast<wchar_t *>(wstrTemp.c_str()), const_cast<wchar_t *>(wstrTemp.c_str() + length), pwOutNext);
		if(objResult == codecvt<wchar_t, char, mbstate_t>::ok)
		{
			// Translate Unicode to characters:
			const wchar_t * pwInNext = nullptr;
			char * pOutNext = nullptr;
			objResult = objFacetTo.out(state, wstrTemp.c_str(), wstrTemp.c_str() + length, pwInNext, const_cast<char *>(strOut.c_str()), const_cast<char *>(strOut.c_str() + length), pOutNext);
			if(objResult != codecvt<wchar_t, char, mbstate_t>::error)
			{
				// FIXME: Is this OK?
				// Do nothing
			}
		}
	}
	catch(runtime_error& e)
	{
		throw;
	}
	catch(...)
	{
		throw;
	}

	return strOut;
}

StringConvertionCodePage StringConvertion::getDefaultCodePage(void)
{
	StringConvertionCodePage retCP = StringConvertionCodePage::SCP_UNKNOW;
	string strLocale(locale().name());
	if(strLocale.compare("") != 0)
	{
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
		// Windows-1252
		retCP = StringConvertionCodePage::SCP_CP1252;
#else
		// UTF-8
		retCP = StringConvertionCodePage::SCP_UTF_8;
#endif
	}
	else if(strLocale.compare("C") != 0)
	{
		// IBM437
		retCP = StringConvertionCodePage::SCP_CP437;
	}
	else if(strLocale.compare("POSIX") != 0)
	{
		// IBM437
		retCP = StringConvertionCodePage::SCP_CP437;
	}
	else if((strLocale.find(".CP1252") != string::npos) || (strLocale.find(".1252") != string::npos))
	{
		// Windows-1252: ANSI Latin 1 + €; Windows Western European (same as ISO-8859-1, but with more printing characters insted of control codes defined like the €)
		retCP = StringConvertionCodePage::SCP_CP1252;
	}
	else if((strLocale.find(".ISO-8859-15") != string::npos) || (strLocale.find(".28605") != string::npos))
	{
		// ISO-8859-15: ISO Latin 9; ANSI Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € insted of ¤)
		retCP = StringConvertionCodePage::SCP_ISO8859_15;
	}
	else if((strLocale.find(".ISO-8859-1") != string::npos) || (strLocale.find(".28591") != string::npos))
	{
		// ISO-8859-1: ISO Latin 1; ANSI Western European
		retCP = StringConvertionCodePage::SCP_ISO8859_1;
	}
	else if((strLocale.find(".CP437") != string::npos) || (strLocale.find(".437") != string::npos))
	{
		// IBM437: OEM USA; DOS USA
		retCP = StringConvertionCodePage::SCP_CP437;
	}
	else if((strLocale.find(".CP850") != string::npos) || (strLocale.find(".850") != string::npos))
	{
		// IBM850: OEM Multilingual Latin 1; DOS Western European
		retCP = StringConvertionCodePage::SCP_CP850;
	}
	else if((strLocale.find(".CP858") != string::npos) || (strLocale.find(".858") != string::npos))
	{
		// IBM858: OEM Multilingual Latin 1  + €; DOS Western European + € (same as IBM850, but with € insted of ı)
		retCP = StringConvertionCodePage::SCP_CP858;
	}
	else if((strLocale.find(".CP860") != string::npos) || (strLocale.find(".860") != string::npos))
	{
		// IBM860: OEM Portuguese; DOS Portuguese
		retCP = StringConvertionCodePage::SCP_CP860;
	}
	else if((strLocale.find(".UTF-8") != string::npos) || (strLocale.find(".utf8") != string::npos) || (strLocale.find(".65001") != string::npos))
	{
		// UTF-8
		retCP = StringConvertionCodePage::SCP_UTF_8;
	}
	else if((strLocale.find(".MacRoman") != string::npos) || (strLocale.find(".Macintosh") != string::npos) || (strLocale.find(".10000") != string::npos))
	{
		// MacRoman: Macintosh Latin 1; Mac Western European
		retCP = StringConvertionCodePage::SCP_MacRoman;
	}
	
	return retCP;
}

/*
	Check if the given string is a valid UTF-8 sequence.

	Return value:
		true: if is valid;
		false: otherwise.

	Valid UTF-8 sequences look like this (RFC 3629):
		0xxxxxxx
		110xxxxx 10xxxxxx
		1110xxxx 10xxxxxx 10xxxxxx
		11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
*/
bool StringConvertion::isUtf8(const uint8_t * str, size_t len, bool * unicodeFound)
{
	size_t i = 0;
	size_t sequenceBytes = 0;

	if(unicodeFound != nullptr)
		*unicodeFound = false;

	while(i < len)
	{
		if(str[i] <= 0x7F)
			sequenceBytes = 0;	// 7 bit ASCII
		else if((str[i] >= 0xC0) && (str[i] <= 0xDF))
		{
			sequenceBytes = 1;	// Sequence 11000000 to 11011111
			if(unicodeFound != nullptr)
				*unicodeFound = true;
		}
		else if((str[i] >= 0xE0) && (str[i] <= 0xEF))
		{
			sequenceBytes = 2;	// Sequence 11100000 to 11101111
			if(unicodeFound != nullptr)
				*unicodeFound = true;
		}
		else if((str[i] >= 0xF0) && (str[i] <= 0xF7))
		{
			sequenceBytes = 3;	// Sequence 11110000 to 11110111
			if(unicodeFound != nullptr)
				*unicodeFound = true;
		}
                else if((str[i] >= 0xF8) && (str[i] <= 0xFB))
		{
			sequenceBytes = 4;	// Sequence 11111000 to 11111011
			if(unicodeFound != nullptr)
				*unicodeFound = true;
		}
                else if((str[i] >= 0xFC) && (str[i] <= 0xFD))
		{
			sequenceBytes = 5;	// Sequence 11111100 to 11111101
			if(unicodeFound != nullptr)
				*unicodeFound = true;
		}
		else
			return false;		// Invalid sequence

		i += 1;
		while((i < len) && (sequenceBytes > 0) && (str[i] >= 0x80) && (str[i] <= 0xBF))
		{
			i += 1;
			sequenceBytes -= 1;
		}
		if(sequenceBytes != 0)
			return false;
	}

	return true;
}

bool StringConvertion::hasUtf8Bom(const string& str)
{
	// Validate parameters
	assert(&str != nullptr);

	bool bRet = false;

	if(str.length() >= 3)
	{
		bRet = (str[0] == bomUTF8[0]) && (str[1] == bomUTF8[1]) && (str[2] == bomUTF8[2]);
	}

	return bRet;
}

bool StringConvertion::hasUtf16BeBom(const u16string& str)
{
	// Validate parameters
	assert(&str != nullptr);

	bool bRet = false;

	if(str.length() >= 2)
	{
		bRet = (str[0] == bomUTF16BE[0]) && (str[1] == bomUTF16BE[1]);
	}

	return bRet;
}
		
bool StringConvertion::hasUtf16LeBom(const u16string& str)
{
	// Validate parameters
	assert(&str != nullptr);

	bool bRet = false;

	if(str.length() >= 2)
	{
		bRet = (str[0] == bomUTF16LE[0]) && (str[1] == bomUTF16LE[1]);
	}

	return bRet;
}

bool StringConvertion::hasUtf16Bom(const u16string& str)
{
	bool bRet = hasUtf16LeBom(str) || hasUtf16BeBom(str);

	return bRet;
}

bool StringConvertion::hasUtf32BeBom(const u32string& str)
{
	assert(&str != nullptr);

	bool bRet = false;

	if(str.length() >= 4)
	{
		bRet = (str[0] == bomUTF32BE[0]) && (str[1] == bomUTF32BE[1]) && (str[2] == bomUTF32BE[2]) && (str[3] == bomUTF32BE[3]);
	}

	return bRet;
}
		
bool StringConvertion::hasUtf32LeBom(const u32string& str)
{
	assert(&str != nullptr);

	bool bRet = false;

	if(str.length() >= 4)
	{
		bRet = (str[0] == bomUTF32LE[0]) && (str[1] == bomUTF32LE[1]) && (str[2] == bomUTF32LE[2]) && (str[3] == bomUTF32LE[3]);
	}

	return bRet;
}

bool StringConvertion::hasUtf32Bom(const u32string& str)
{
	bool bRet = hasUtf32LeBom(str) || hasUtf32BeBom(str);

	return bRet;
}

bool StringConvertion::hasUtfBom(void)
{
	bool bRet = false;
	
	switch(this->m_encodingType)
	{
		case StringConvertionEncodingType::SET_CHAR:
		case StringConvertionEncodingType::SET_UTF8:
			bRet = hasUtf8Bom(*this->m_string.utf8String);
			break;

		case StringConvertionEncodingType::SET_UTF16:
			bRet = hasUtf16Bom(*this->m_string.utf16String);
			break;

		case StringConvertionEncodingType::SET_UTF32:
			bRet = hasUtf32Bom(*this->m_string.utf32String);
			break;

		case StringConvertionEncodingType::SET_WCHAR:
			if(this->m_codePage == StringConvertionCodePage::SCP_UTF_16)
				bRet = hasUtf16Bom(u16string(((char16_t *)(this->m_string.wideString->c_str()))));
			else
				bRet = hasUtf32Bom(u32string(((char32_t *)(this->m_string.wideString->c_str()))));
			break;

		default:
			bRet = false;
	}

	return bRet;
}

void StringConvertion::removeUtf8Bom(void)
{
	if((this->m_encodingType == StringConvertionEncodingType::SET_CHAR) || (this->m_encodingType == StringConvertionEncodingType::SET_UTF8))
	{
		if(hasUtf8Bom(*this->m_string.utf8String))
		{
			// TODO: 
		}
	}
}

string StringConvertion::getNarrow(void)
{
	char* cstrASCII = nullptr;
	size_t requiredSize = 0;
	size_t nRet = 0;
			
	switch(this->m_encodingType)
	{
		case StringConvertionEncodingType::SET_UNKNOW:
			// FIXME: Ignor or throw exception?
			break;

		case StringConvertionEncodingType::SET_CHAR:
			return string(*this->m_string.narrowString); 
			break;

		case StringConvertionEncodingType::SET_WCHAR:
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
			// Microsoft Windows
			requiredSize = ::WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK | WC_SEPCHARS | WC_NO_BEST_FIT_CHARS, (this->m_string.wideString)->c_str(), -1, nullptr, 0, nullptr, nullptr);
#else
			// ANSI C/C++
			requiredSize = ::wcstombs(nullptr, (this->m_string.wideString)->c_str(), 0);
#endif

			if(requiredSize > 0) 
			{ 
				cstrASCII = (char*)malloc((requiredSize + 1) * sizeof(char));
				if(cstrASCII != nullptr)
				{
					cstrASCII[requiredSize] = '\0';
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
					// Microsoft Windows
					nRet = ::WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK | WC_SEPCHARS | WC_NO_BEST_FIT_CHARS, (this->m_string.wideString)->c_str(), -1, cstrASCII, requiredSize, nullptr, nullptr);
#else
					// ANSI C/C++
					nRet = ::wcstombs(cstrASCII, (this->m_string.wideString)->c_str(), requiredSize);
#endif

					if((nRet == 0) || (nRet == static_cast<size_t>(-1)) || (nRet > requiredSize))
					{
						// Error converting string
						free((void*)cstrASCII);
						cstrASCII = nullptr;
					}
				}
				else
				{
					// Error allocating memory
					cstrASCII = nullptr;
				}
			} 
			else
			{
				// Error, can't convert
				cstrASCII = nullptr;
			}

			if(cstrASCII == nullptr)
			{
				throw *new runtime_error("Can't convert wide string to narrow string");
			}
			else
			{
				string str(cstrASCII);
				free(cstrASCII);
				return str;
			}
			break;

		case StringConvertionEncodingType::SET_UTF8:
			
			break;

		case StringConvertionEncodingType::SET_UTF16:
			{
			typedef codecvt_utf8_utf16<char16_t> convert_typeX;
			wstring_convert<convert_typeX, char16_t> converterX;
			//return converterX.from_bytes(*this->m_string.utf8String);
			}
			break;

		case StringConvertionEncodingType::SET_UTF32:
			{
			typedef codecvt_utf8_utf16<char32_t> convert_typeX;
			wstring_convert<convert_typeX, char32_t> converterX;
			//return converterX.from_bytes(*this->m_string.utf8String);
			}
			break;

		default:
			throw *new runtime_error("Invalid StringConvertion type");
	}

	return string(*this->m_string.narrowString);
}

wstring StringConvertion::getWide(void)
{
	switch(this->m_encodingType)
	{
		case StringConvertionEncodingType::SET_UNKNOW:
			// FIXME: Ignor or throw exception?
			break;

		case StringConvertionEncodingType::SET_CHAR:
			{
			locale nativeLocale; 
 
			// The UTF-16 will never be longer than the input string 
			vector<wchar_t> vUtf16((this->m_string.narrowString)->length() + 1); 
 
			// Convert CHAR to UTF-16
			use_facet< ctype<wchar_t> >(nativeLocale).widen((this->m_string.narrowString)->c_str(), (this->m_string.narrowString)->c_str() + (this->m_string.narrowString)->length(), &vUtf16[0]);
 
			return wstring(vUtf16.begin(), vUtf16.end());
			}
			break;

		case StringConvertionEncodingType::SET_WCHAR:
			return wstring(*this->m_string.wideString);
			break;

		case StringConvertionEncodingType::SET_UTF8:
			
			break;

		case StringConvertionEncodingType::SET_UTF16:
			
			break;

		case StringConvertionEncodingType::SET_UTF32:
			
			break;

		default:
			throw *new runtime_error("Invalid StringConvertion type");
	}

	return *new wstring(*this->m_string.wideString);
}

string StringConvertion::getUtf8(void)
{
	switch(this->m_encodingType)
	{
		case StringConvertionEncodingType::SET_UNKNOW:
			// FIXME: Ignor or throw exception?
			break;

		case StringConvertionEncodingType::SET_CHAR:
			
			break;

		case StringConvertionEncodingType::SET_WCHAR:
			
			break;

		case StringConvertionEncodingType::SET_UTF8:
			return *new string(*this->m_string.utf8String);
			break;

		case StringConvertionEncodingType::SET_UTF16:
			
			break;

		case StringConvertionEncodingType::SET_UTF32:
			
			break;

		default:
			throw *new runtime_error("Invalid StringConvertion type");
	}

	return *new string(*this->m_string.utf8String);
}

u16string StringConvertion::getUtf16(void)
{
	switch(this->m_encodingType)
	{
		case StringConvertionEncodingType::SET_UNKNOW:
			// FIXME: Ignor or throw exception?
			break;

		case StringConvertionEncodingType::SET_CHAR:
			
			break;

		case StringConvertionEncodingType::SET_WCHAR:
			
			break;

		case StringConvertionEncodingType::SET_UTF8:
			
			break;

		case StringConvertionEncodingType::SET_UTF16:
			return *new u16string(*this->m_string.utf16String);
			break;

		case StringConvertionEncodingType::SET_UTF32:
			
			break;

		default:
			throw *new runtime_error("Invalid StringConvertion type");
	}

	return *new u16string(*this->m_string.utf16String);
}

u32string StringConvertion::getUtf32(void)
{
	switch(this->m_encodingType)
	{
		case StringConvertionEncodingType::SET_UNKNOW:
			// FIXME: Ignor or throw exception?
			break;

		case StringConvertionEncodingType::SET_CHAR:
			
			break;

		case StringConvertionEncodingType::SET_WCHAR:
			
			break;

		case StringConvertionEncodingType::SET_UTF8:
			
			break;

		case StringConvertionEncodingType::SET_UTF16:
			
			break;

		case StringConvertionEncodingType::SET_UTF32:
			return *new u32string(*this->m_string.utf32String);
			break;

		default:
			throw *new runtime_error("Invalid StringConvertion type");
	}

	return *new u32string(*this->m_string.utf32String);
}

#ifdef _DEBUG
void StringConvertion::doTests(void)
{
	// IBM437; OEM USA; USA (DOS)
	//                 "äöáéíóúàèìòùâêîôûç ÄÖAÉIOUAEIOUAEIOUÇ ?";
	static const unsigned char aStr437[]   =      { 0x84, 0x94, 0xA0, 0x82, 0xA1, 0xA2, 0xA3, 0x85, 0x8A, 0x8D, 0x95, 0x97, 0x83, 0x88, 0x8C, 0x93, 0x96, 0x87, 0x20, 0x8E, 0x99, 0x41, 0x90, 0x49, 0x4F, 0x55, 0x41, 0x45, 0x49, 0x4F, 0x55, 0x41, 0x45, 0x49, 0x4F, 0x55, 0x80, 0x20, 0x3F, 0x00 };
	// IBM850; OEM Multilingual Latin 1; Western European (DOS)
	//                 "ãõáéíóúàèìòùâêîôûç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ ¤";
	static const unsigned char aStr850[]   =      { 0xC6, 0xE4, 0xA0, 0x82, 0xA1, 0xA2, 0xA3, 0x85, 0x8A, 0x8D, 0x95, 0x97, 0x83, 0x88, 0x8C, 0x93, 0x96, 0x87, 0x20, 0xC7, 0xE5, 0xB5, 0x90, 0xD6, 0xE0, 0xE9, 0xB7, 0xD4, 0xDE, 0xE3, 0xEB, 0xB6, 0xD2, 0xD7, 0xE2, 0xEA, 0x80, 0x20, 0xCF, 0x00 };
	// IBM858; OEM Multilingual Latin 1 + € symbol; Western European + € symbol (DOS)
	//                 "ãõáéíóúàèìòùâêîôûç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ €";
	static const unsigned char aStr858[]   =      { 0xC6, 0xE4, 0xA0, 0x82, 0xA1, 0xA2, 0xA3, 0x85, 0x8A, 0x8D, 0x95, 0x97, 0x83, 0x88, 0x8C, 0x93, 0x96, 0x87, 0x20, 0xC7, 0xE5, 0xB5, 0x90, 0xD6, 0xE0, 0xE9, 0xB7, 0xD4, 0xDE, 0xE3, 0xEB, 0xB6, 0xD2, 0xD7, 0xE2, 0xEA, 0x80, 0x20, 0xD5, 0x00 };
	// IBM860; OEM Portuguese; Portuguese (DOS)
	//                 "ãõáéíóúàèìòùâêiôuç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÍÔUÇ ?";
	static const unsigned char aStr860[]   =      { 0x84, 0x94, 0xA0, 0x82, 0xA1, 0xA2, 0xA3, 0x85, 0x8A, 0x8D, 0x95, 0x97, 0x83, 0x88, 0x69, 0x93, 0x75, 0x87, 0x20, 0x8E, 0x99, 0x86, 0x90, 0x8B, 0x9F, 0x96, 0x91, 0x92, 0x98, 0xA9, 0x9D, 0x8F, 0x89, 0x49, 0x8C, 0x55, 0x80, 0x20, 0x3F, 0x00 };
	// MacRoman; Mac OS Roman; Mac Latin 1; Western European (Mac)
	//                 "ãõáéíóúàèìòùâêîôûç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ €";
	static const unsigned char aStrMacRoman[] =   { 0x8B, 0x9B, 0x87, 0x8E, 0x92, 0x97, 0x9C, 0x88, 0x8F, 0x93, 0x98, 0x9D, 0x89, 0x90, 0x94, 0x99, 0x9E, 0x8D, 0x20, 0xCC, 0xCD, 0xE7, 0x83, 0xEA, 0xEE, 0xF2, 0xCB, 0xE9, 0xED, 0xF1, 0xF4, 0xE5, 0xE6, 0xEB, 0xEF, 0xF3, 0x82, 0x20, 0xDB, 0x00 };
	// Windows-1252; ANSI Latin 1; Western European (Windows); Like ISO-8859-1
	//                 "ãõáéíóúàèìòùâêîôûç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ €";
	static const unsigned char aStr1252[] =       { 0xE3, 0xF5, 0xE1, 0xE9, 0xED, 0xF3, 0xFA, 0xE0, 0xE8, 0xEC, 0xF2, 0xF9, 0xE2, 0xEA, 0xEE, 0xF4, 0xFB, 0xE7, 0x20, 0xC3, 0xD5, 0xC1, 0xC9, 0xCD, 0xD3, 0xDA, 0xC0, 0xC8, 0xCC, 0xD2, 0xD9, 0xC2, 0xCA, 0xCE, 0xD4, 0xDB, 0xC7, 0x20, 0x80, 0x00 };
	// ISO-8859-1: ISO Latin 1; ANSI Western European
	//                 "ãõáéíóúàèìòùâêîôûç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ ¤";
	static const unsigned char aStrISO_8859_1[] = { 0xE3, 0xF5, 0xE1, 0xE9, 0xED, 0xF3, 0xFA, 0xE0, 0xE8, 0xEC, 0xF2, 0xF9, 0xE2, 0xEA, 0xEE, 0xF4, 0xFB, 0xE7, 0x20, 0xC3, 0xD5, 0xC1, 0xC9, 0xCD, 0xD3, 0xDA, 0xC0, 0xC8, 0xCC, 0xD2, 0xD9, 0xC2, 0xCA, 0xCE, 0xD4, 0xDB, 0xC7, 0x20, 0xA4, 0x00 };
	// ISO-8859-15: ISO Latin 9; ANSI Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € insted of ¤)
	//                 "ãõáéíóúàèìòùâêîôûç ÃÕÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ €";
	static const unsigned char aStrISO_8859_15[]= { 0xE3, 0xF5, 0xE1, 0xE9, 0xED, 0xF3, 0xFA, 0xE0, 0xE8, 0xEC, 0xF2, 0xF9, 0xE2, 0xEA, 0xEE, 0xF4, 0xFB, 0xE7, 0x20, 0xC3, 0xD5, 0xC1, 0xC9, 0xCD, 0xD3, 0xDA, 0xC0, 0xC8, 0xCC, 0xD2, 0xD9, 0xC2, 0xCA, 0xCE, 0xD4, 0xDB, 0xC7, 0x20, 0xA4, 0x00 };
	// Unicode  encoded in UTF-8
	//                 "Ã£ÃµÃ¡Ã©Ã­Ã³ÃºÃ Ã¨Ã¬Ã²Ã¹Ã¢ÃªÃ®Ã´Ã»Ã§ ÃƒÃ•ÃÃ‰ÃÃ“ÃšÃ€ÃˆÃŒÃ’Ã™Ã‚ÃŠÃŽÃ”Ã›Ã‡ â‚¬";
	static const unsigned char aStrUTF_8[] = { 0xC3, 0xA3, 0xC3, 0xB5, 0xC3, 0xA1, 0xC3, 0xA9, 0xC3, 0xAD, 0xC3, 0xB3, 0xC3, 0xBA, 0xC3, 0xA0, 0xC3, 0xA8, 0xC3, 0xAC, 0xC3, 0xB2, 0xC3, 0xB9, 0xC3, 0xA2, 0xC3, 0xAA, 0xC3, 0xAE, 0xC3, 0xB4, 0xC3, 0xBB, 0xC3, 0xA7, 0x20, 0xC3, 0x83, 0xC3, 0x95, 0xC3, 0x81, 0xC3, 0x89, 0xC3, 0x8D, 0xC3, 0x93, 0xC3, 0x9A, 0xC3, 0x80, 0xC3, 0x88, 0xC3, 0x8C, 0xC3, 0x92, 0xC3, 0x99, 0xC3, 0x82, 0xC3, 0x8A, 0xC3, 0x8E, 0xC3, 0x94, 0xC3, 0x9B, 0xC3, 0x87, 0x20, 0xE2, 0x82, 0xAC, 0x00 };
	// Unicode  encoded in UTF-16
	static const wchar_t wStrUTF16[] = { 0x00E3, 0x00F5, 0x00E1, 0x00E9, 0x00ED, 0x00F3, 0x00FA, 0x00E0, 0x00E8, 0x00EC, 0x00F2, 0x00F9, 0x00E2, 0x00EA, 0x00EE, 0x00F4, 0x00FB, 0x00E7, 0x0020, 0x00C3, 0x00D5, 0x00C1, 0x00C9, 0x00CD, 0x00D3, 0x00DA, 0x00C0, 0x00C8, 0x00CC, 0x00D2, 0x00D9, 0x00C2, 0x00CA, 0x00CE, 0x00D4, 0x00DB, 0x00C7, 0x0020, 0x20AC, 0x0000 };

	locale namelessLocale(std::locale(), new std::ctype<char>);

	cout << boolalpha;	// Show bool as True/False, not 1/0
	cout << "Platform Locale and Character Information:" << endl;
	cout << "  The default locale is:  " << locale().name() << endl;
	cout << "  The classic locale is:  " << locale::classic().name() << endl;
	cout << "  The user's locale is:   " << locale("").name() << endl;
	cout << "  The nameless locale is: " << namelessLocale.name() << endl;
	cout << "  The 'cout' locale is:   " << cout.getloc().name() << endl;
	cout << "  The 'wcout' locale is:  " << wcout.getloc().name() << endl;
	cout << "  The 'char' size is:     " << getNarrowCharByteSize() << endl;
	cout << "  The 'wchar_t' size is:  " << getWideCharByteSize() << endl;
	cout << "  The '_TCHAR' size is:   " << getTCharByteSize() << endl;
	cout << "  Is 'char' UTF-8:        " << isNarrowCharUtf8() << endl;
	cout << "  Is 'wchar_t' UTF-16:    " << isWideCharUtf16() << endl;
	cout << "  Is 'wchar_t' UTF-32:    " << isWideCharUtf32() << endl;
	cout << "  Is exe wide Unicode:    " << isApplicationWideUnicode() << endl;
	cout << endl;

	resetOut();

	cout << "Code Page Conversions (to native narrow code page):" << endl;
	// CP437
	test1((char *)aStr437, (char *)aStr1252, StringConvertionCodePage::SCP_CP437, "CP437 - DOS Latin US");
	cout << "------------------------------------------------------------------------" << endl;
	// CP850
	test1((char *)aStr850, (char *)aStr1252, StringConvertionCodePage::SCP_CP850, "CP850 - DOS Latin 1");
	cout << "------------------------------------------------------------------------" << endl;
	// CP858
	test1((char *)aStr858, (char *)aStr1252, StringConvertionCodePage::SCP_CP858, "CP858 - DOS Latin 1 + Euro");
	cout << "------------------------------------------------------------------------" << endl;
	// CP860
	test1((char *)aStr860, (char *)aStr1252, StringConvertionCodePage::SCP_CP860, "CP860 - DOS Portuguese");
	cout << "------------------------------------------------------------------------" << endl;
	// ISO-8859-1
	test1((char *)aStrISO_8859_1, (char *)aStr1252, StringConvertionCodePage::SCP_ISO8859_1, "ISO-8859-1 - ISO/ANSI Latin 1");
	cout << "------------------------------------------------------------------------" << endl;
	// ISO-8859-15
	test1((char *)aStrISO_8859_15, (char *)aStr1252, StringConvertionCodePage::SCP_ISO8859_15, "ISO-8859-15 - ISO/ANSI Latin 9 + Euro");
	cout << "------------------------------------------------------------------------" << endl;
	// Windows-1252
	test1((char *)aStr1252, (char *)aStr1252, StringConvertionCodePage::SCP_CP1252, "Windows-1252 - Windows Latin 1 + Euro");
	cout << "------------------------------------------------------------------------" << endl;
	// MacRoman
	test1((char *)aStrMacRoman, (char *)aStr1252, StringConvertionCodePage::SCP_MacRoman, "MacRoman - Macintosh Latin 1");
	cout << "------------------------------------------------------------------------" << endl;
	// UTF-8
	test1((char *)aStrUTF_8, (char *)aStr1252, StringConvertionCodePage::SCP_UTF_8, "UTF-8 - UTF-8 Unicode");
	cout << endl;

	resetOut();

	cout << "Code Page Conversions (from native narrow code page):" << endl;
	// CP437
	test2((char *)aStr1252, (char *)aStr437, StringConvertionCodePage::SCP_CP437, "CP437 - DOS Latin US");
	cout << "------------------------------------------------------------------------" << endl;
	// CP850
	test2((char *)aStr1252, (char *)aStr850, StringConvertionCodePage::SCP_CP850, "CP850 - DOS Latin 1");
	cout << "------------------------------------------------------------------------" << endl;
	// CP858
	test2((char *)aStr1252, (char *)aStr858, StringConvertionCodePage::SCP_CP858, "CP858 - DOS Latin 1 + Euro");
	cout << "------------------------------------------------------------------------" << endl;
	// CP860
	test2((char *)aStr1252, (char *)aStr860, StringConvertionCodePage::SCP_CP860, "CP860 - DOS Portuguese");
	cout << "------------------------------------------------------------------------" << endl;
	// ISO-8859-1
	test2((char *)aStr1252, (char *)aStrISO_8859_1, StringConvertionCodePage::SCP_ISO8859_1, "ISO-8859-1 - ISO/ANSI Latin 1");
	cout << "------------------------------------------------------------------------" << endl;
	// ISO-8859-15
	test2((char *)aStr1252, (char *)aStrISO_8859_15, StringConvertionCodePage::SCP_ISO8859_15, "ISO-8859-15 - ISO/ANSI Latin 9 + Euro");
	cout << "------------------------------------------------------------------------" << endl;
	// Windows-1252
	test2((char *)aStr1252, (char *)aStr1252, StringConvertionCodePage::SCP_CP1252, "Windows-1252 - Windows Latin 1 + Euro");
	cout << "------------------------------------------------------------------------" << endl;
	// MacRoman
	test2((char *)aStr1252, (char *)aStrMacRoman, StringConvertionCodePage::SCP_MacRoman, "MacRoman - Macintosh Latin 1");
	cout << "------------------------------------------------------------------------" << endl;
	// UTF-8
	test2((char *)aStr1252, (char *)aStrUTF_8, StringConvertionCodePage::SCP_UTF_8, "UTF-8 - UTF-8 Unicode");
	cout << endl;

	resetOut();

	// Narow char
	cout << "Narow Char Locales: " << endl;
	test3("", (char *)aStr1252);				// Default (CP1252)
	test3("C", (char *)aStr437);				// ANSI C (CP437)
	test3("POSIX", (char *)aStr437);			// POSIX (CP437)
	
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_CP437].stringId, (char *)aStr437);		// CP437
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_CP850].stringId, (char *)aStr850);		// CP850 
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_CP858].stringId, (char *)aStr858);		// CP858
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_CP860].stringId, (char *)aStr860);		// CP860
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_CP1252].stringId, (char *)aStr1252);            // CP1252 + €
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_ISO8859_1].stringId, (char *)aStrISO_8859_1);	// ISO-8859-1
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_ISO8859_15].stringId, (char *)aStrISO_8859_15);	// ISO-8859-15 + €
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_MacRoman].stringId, (char *)aStrMacRoman);	// Mac Roman + €
	test3(StringConvertion::m_mapCharSet[(int)StringConvertionCodePage::SCP_UTF_8].stringId, (char *)aStrUTF_8);		// UTF-8
	cout << endl;

	resetOut();

	// Wide char
	wcout << "Wide Char Locales: " << endl;
	test4("", wStrUTF16);								// Default (CP1252)
	test4("C", wStrUTF16);								// ANSI C (CP437)
	test4("POSIX", wStrUTF16);							// POSIX (CP437)
	test4("Portuguese_Portugal.1252@euro", wStrUTF16);	// CP1252 + €
        test4("pt_PT.WINDOWS-1252@euro", wStrUTF16);	// CP1252 + €
        test4("pt_PT.WINDOWS-1252", wStrUTF16);	// CP1252 + €
        test4("pt_PT.WINDOWS1252", wStrUTF16);	// CP1252 + €
        test4("pt_PT.CP1252@euro", wStrUTF16);	// CP1252 + €
        test4("pt_PT.CP1252", wStrUTF16);	// CP1252 + €
        test4(".CP1252", wStrUTF16);	// CP1252 + €
        test4("CP1252", wStrUTF16);	// CP1252 + €
        test4("ISO-8859-1", wStrUTF16);
        test4(".ISO-8859-1", wStrUTF16);
	test4("pt_PT.ISO-8859-1", wStrUTF16);
        test4("pt_PT.ISO-8859-15@euro", wStrUTF16);
        test4("pt_PT.ISO-8859-15", wStrUTF16);
	test4("Portuguese_Portugal.850", wStrUTF16);			// CP850 
        test4("pt_PT.CP850", wStrUTF16);			// CP850 
        test4(".858@euro", wStrUTF16);	// CP858
	test4("pt_PT.858@euro", wStrUTF16);	// CP858
        test4("pt_PT.858", wStrUTF16);	// CP858
	test4("Portuguese_Portugal.860", wStrUTF16);			// CP860 
        test4("pt_PT.CP860", wStrUTF16);			// CP860 
        test4("pt_PT.IBM-860", wStrUTF16);			// CP850 
        test4("pt_PT.IBM-850", wStrUTF16);			// CP850 
        test4("pt_PT.IBM-858", wStrUTF16);			// CP850 
        test4("pt_PT.MACINTOSH", wStrUTF16);			// MACINTOSH 
        test4("pt_PT.MAC", wStrUTF16);			// MACINTOSH 
        test4("pt_PT.MACROMAN", wStrUTF16);			// MACINTOSH 
        test4("pt_PT.MacRoman", wStrUTF16);			// MACINTOSH 
	test4("Portuguese_Portugal.65001", wStrUTF16);		// UTF-8 --- Windows
	test4("Portuguese_Portugal.1200", wStrUTF16);		// UTF-16 --- Windows
	test4(".ISO-8859-15", wStrUTF16); // ISO-8859-15 --- Linux
	test4(".28605@euro", wStrUTF16);	// ISO-8859-15 --- Windows
	test4(".UTF-16", wStrUTF16);		// UTF-16 --- Linux
	test4(".1200", wStrUTF16);		// UTF-16 --- Windows
	wcout << endl;

	resetOut();

	wcout << L"Native Narrow to Wide: " << endl;
	string sU((char *)aStr1252);
	wstring wU = narrow2Wide(sU);
	wcout << L"narrow2Wide: " << wU << endl;
	wcout << endl;

	cout << "Native Wide to Narrow: " << endl;
	wstring sC(wStrUTF16);
	string nC = wide2Narrow(sC);
	cout << "wide2Narrow: " << nC << endl;
	cout << endl;
	
	wcout << "UTF-8 to UTF-16: " << endl;
	//wchar_t* pwStr = Utf8_2_Utf16(aStrUTF_8);
	//wcout << L"Utf8_2_Utf16: " << pwStr << endl;
	//wcout << L"  Valid: " << (::wcscmp(pwStr, wStrUTF16) == 0) << endl;
	//delete [] pwStr;
	string nC2 = string((char *)aStrUTF_8);
	//wstring w = Utf8ToUtf16(nC2);
	//wcout << "Utf8ToUtf16: " << w << endl;
	//wcout << "  Valid: " << (::wcscmp(w.c_str(), wStrUTF16) == 0) << endl;
	wcout << endl;

	cout << "UTF-16 to UTF-8: " << endl;
	//char* pnStr = Utf16_2_Utf8(wStrUTF16);
	//cout << "Utf16_2_Utf8: " << pnStr << endl;
	//cout << "  Valid: " << (::strcmp(pnStr, aStrUTF_8) == 0) << endl;
	//delete [] pnStr;
	wstring wU2 = wstring(wStrUTF16);
	//string s = Utf16ToUtf8(wU2);
	//cout << "Utf16ToUtf8: " << s << endl;
	//cout << "  Valid: " << (::strcmp(s.c_str(), aStrUTF_8) == 0) << endl;
	cout << endl;
}

void StringConvertion::resetOut(void)
{
	// Set locale to default
	//locale objNewLocale; // initialized to locale::classic()
	locale objNewLocale = locale("");
	locale oldLoc = locale::global(objNewLocale);
	cout.imbue(objNewLocale);
	wcout.imbue(objNewLocale);

	// Show bool as True/False, not 1/0
	cout << boolalpha;
	wcout << boolalpha;
}

void StringConvertion::test1(const char * strNarrowFrom, const char * strNarrowTo, const StringConvertionCodePage fromCodePage, const char * strCodePageInfo)
{
	locale oldLocale;
	locale newLocale;
	string strNarrowConverted;
	string strLocale = StringConvertion::m_mapCharSet[(int)fromCodePage].stringId;

	try
	{
		strNarrowConverted = convertFromCodePage(strNarrowFrom, fromCodePage);
		newLocale = locale(strLocale);
		oldLocale = locale::global(newLocale);
		cout.imbue(newLocale);
		cout << "  Convert:        " << strNarrowFrom << endl;
		locale::global(oldLocale);
		cout.imbue(oldLocale);
		cout << "  From code page: " << strLocale << "  (" << strCodePageInfo << ")" << endl;
		cout << "  Result:         " << strNarrowConverted << endl;
		cout << "  My Convertion:  " << strNarrowTo << endl;
	}
	catch (runtime_error& e)
	{
		cout << "ERROR: '" << strLocale << "' (" << strCodePageInfo << "): " << e.what() << endl << endl;
		resetOut();
	}
	catch(...)
	{
		resetOut();
	}
}

void StringConvertion::test2(const char * strNarrowFrom, const char * strNarrowTo, const StringConvertionCodePage toCodePage, const char * strCodePageInfo)
{
	locale oldLocale;
	locale newLocale;
	string strNarrowConverted;
	string strLocale = StringConvertion::m_mapCharSet[(int)toCodePage].stringId;

	try
	{
		strNarrowConverted = convertToCodePage(strNarrowFrom, toCodePage);
		cout.imbue(locale(""));
		cout << "  Convert:        " << strNarrowFrom << endl;
		newLocale = locale(strLocale);
		oldLocale = locale::global(newLocale);
		cout.imbue(newLocale);
		cout << "  To code page: " << strLocale << "  (" << strCodePageInfo << ")" << endl;
		cout << "  Result:         " << strNarrowConverted << endl;
		cout << "  My Convertion:  " << strNarrowTo << endl;
		cout.imbue(oldLocale);
		locale::global(oldLocale);
	}
	catch (runtime_error& e)
	{
		cout << "ERROR: '" << strLocale << "' (" << strCodePageInfo << "): " << e.what() << endl << endl;
		resetOut();
	}
	catch(...)
	{
		resetOut();
	}
}

void StringConvertion::test3(const char * aStrLocale, const char * aStr)
{
	locale objNewLocale; // initialized to locale::classic()
        locale objOldLocale;

	try
	{
		//locale objNewLocale(locale("C"), new Cvt(aStrLocale));
		objNewLocale = locale(aStrLocale);
		//typedef codecvt_byname<char, char, mbstate_t> Cvt;
		// not used, must be zero-initialized and supplied to facet
		//mbstate_t state = mbstate_t();		
		objOldLocale = locale::global(objNewLocale);
		cout.imbue(objNewLocale);
		cout << "Set locale to \"" << aStrLocale << "\" (" << objNewLocale.name() << ") works!" << endl;
		cout << "String: " << aStr << endl;
		locale::global(objOldLocale);
		cout.imbue(objOldLocale);
		cout << endl;
	}
	catch (runtime_error& e)
	{
		objNewLocale = locale(objNewLocale, "", locale::ctype);
		cout << aStrLocale << " : " << e.what() << endl << endl;
                locale::global(objOldLocale);
		cout.imbue(objOldLocale);
	}
}

void StringConvertion::test4(const char * aStrLocale, const wchar_t * wStr)
{
	locale objNewLocale; // initialized to locale::classic()

	try
	{
		objNewLocale = locale(aStrLocale);
		// not used, must be zero-initialized and supplied to facet
		mbstate_t state = mbstate_t();
		const codecvt<wchar_t, char, mbstate_t>& objFacet = use_facet<codecvt<wchar_t, char, mbstate_t>>(objNewLocale);
		codecvt<wchar_t, char, mbstate_t>::result result;
		
		size_t length = ::wcslen(wStr);
		char * pStr = new char[length + 1];
		::memset(pStr, 0, length + 1);
		const wchar_t * pWChar;
		char * pChar;

		// translate characters:
		result = objFacet.out(state, wStr, wStr + length, pWChar, pStr, pStr + length, pChar);
		if(result != codecvt<wchar_t, char, mbstate_t>::error) {
			locale::global(objNewLocale);
			locale oldLoc = wcout.imbue(objNewLocale);
			wcout << L"Set locale to \"" << aStrLocale << L"\" (" << objNewLocale.name().c_str() << L") works!" << endl;
			wcout << L"WString: " << pStr << endl;
			locale::global(oldLoc);
			wcout.imbue(oldLoc);
			wcout << endl;
		}
		else {
			wcout << L"Set locale to \"" << aStrLocale << L"\" fails!" << endl << endl;
		}
	}
	catch (runtime_error& e)
	{
		objNewLocale = locale(objNewLocale, "", locale::ctype);
		wcout << aStrLocale << L" : " << e.what() << endl << endl;
	}
}
#endif
