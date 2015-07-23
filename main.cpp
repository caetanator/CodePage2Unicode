/**
 * main.h
 *
 * ABSTRACT
 *  Test program of the CodePage2Unicode API and objects that convert strings from ASCII to Unicode and vice versa.
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
 
// http://www.tutorialspoint.com/compile_cpp11_online.php
// http://www.tutorialspoint.com/compile_cpp11_online.php
// http://kanjidict.stc.cx/recode.php
// http://www.webutils.pl/index.php?idx=conv
// http://codepage-encoding.online-domain-tools.com/

#include "StdAfx.h"

#include "CodePage2Unicode.h"


using namespace std;

// US_ASCII; IBM367
//                 "aonaoaeiouaeiouaeiouc AONAOAEIOUAEIOUAEIOUC $??? ?"
static const char aStrCP367[]       = "aonaoaeiouaeiouaeiouc AONAOAEIOUAEIOUAEIOUC $??? ?";
// IBM437; OEM USA; USA (MS-DOS)
//                 "aoñäöáéíóúàèìòùâêîôûç AOÑÄÖAÉIOUAEIOUAEIOUÇ $£?? π"
static const char aStrCP437[]       = { '\x61', '\x6F', '\xA4', '\x84', '\x94', '\xA0', '\x82', '\xA1', '\xA2', '\xA3', '\x85', '\x8A', '\x8D', '\x95', '\x97', '\x83', '\x88', '\x8C', '\x93', '\x96', '\x87', '\x20', '\x41', '\x4F', '\xA5', '\x8E', '\x99', '\x41', '\x90', '\x49', '\x4F', '\x55', '\x41', '\x45', '\x49', '\x4F', '\x55', '\x41', '\x45', '\x49', '\x4F', '\x55', '\x80', '\x20', '\x24', '\x9C', '\x3F', '\x3F', '\x20', '\xE3', '\0' };
// IBM850; OEM Multilingual Latin 1; Western European (DOS)
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£?¤ ?"
static const char aStrCP850[]       = { '\xC6', '\xE4', '\xA4', '\x84', '\x94', '\xA0', '\x82', '\xA1', '\xA2', '\xA3', '\x85', '\x8A', '\x8D', '\x95', '\x97', '\x83', '\x88', '\x8C', '\x93', '\x96', '\x87', '\x20', '\xC7', '\xE5', '\xA5', '\x8E', '\x99', '\xB5', '\x90', '\xD6', '\xE0', '\xE9', '\xB7', '\xD4', '\xDE', '\xE3', '\xEB', '\xB6', '\xD2', '\xD7', '\xE2', '\xEA', '\x80', '\x20', '\x24', '\x9C', '\x3F', '\xCF', '\x20', '\x3F', '\0' };
// IBM858; OEM Multilingual Latin 1 + € symbol; Western European + € symbol (MS-DOS)
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ ?"
static const char aStrCP858[]       = { '\xC6', '\xE4', '\xA4', '\x84', '\x94', '\xA0', '\x82', '\xA1', '\xA2', '\xA3', '\x85', '\x8A', '\x8D', '\x95', '\x97', '\x83', '\x88', '\x8C', '\x93', '\x96', '\x87', '\x20', '\xC7', '\xE5', '\xA5', '\x8E', '\x99', '\xB5', '\x90', '\xD6', '\xE0', '\xE9', '\xB7', '\xD4', '\xDE', '\xE3', '\xEB', '\xB6', '\xD2', '\xD7', '\xE2', '\xEA', '\x80', '\x20', '\x24', '\x9C', '\xD5', '\xCF', '\x20', '\x3F', '\0' };
// IBM859; OEM Multilingual Latin 9 + € symbol; Western European + € symbol (MS-DOS)
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ ?"
static const char aStrCP859[]       = { '\xC6', '\xE4', '\xA4', '\x84', '\x94', '\xA0', '\x82', '\xA1', '\xA2', '\xA3', '\x85', '\x8A', '\x8D', '\x95', '\x97', '\x83', '\x88', '\x8C', '\x93', '\x96', '\x87', '\x20', '\xC7', '\xE5', '\xA5', '\x8E', '\x99', '\xB5', '\x90', '\xD6', '\xE0', '\xE9', '\xB7', '\xD4', '\xDE', '\xE3', '\xEB', '\xB6', '\xD2', '\xD7', '\xE2', '\xEA', '\x80', '\x20', '\x24', '\x9C', '\xD5', '\xCF', '\x20', '\x3F', '\0' };
// IBM860; OEM Portuguese; Portuguese (MS-DOS)
//                 "ãõñaoáéíóúàèìòùâêîôuç ÃÕÑAOÁÉÍÓÚÀÈÌÒÙÂÊÎÔUÇ $£?? π"
static const char aStrCP860[]       = { '\x84', '\x94', '\xA4', '\x61', '\x6F', '\xA0', '\x82', '\xA1', '\xA2', '\xA3', '\x85', '\x8A', '\x8D', '\x95', '\x97', '\x83', '\x88', '\x69', '\x93', '\x75', '\x87', '\x20', '\x8E', '\x99', '\xA5', '\x41', '\x4F', '\x86', '\x90', '\x8B', '\x9F', '\x96', '\x91', '\x92', '\x98', '\xA9', '\x9D', '\x8F', '\x89', '\x49', '\x8C', '\x55', '\x80', '\x20', '\x24', '\x9C', '\x3F', '\x3F', '\x20', '\xE3', '\0' };

// macintosh; MacRoman; Mac OS Roman; Mac Latin 1; Western European (Mac OS)
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€? π"
static const char aStrMacRoman[]    = { '\x8B', '\x9B', '\x96', '\x8A', '\x9A', '\x87', '\x8E', '\x92', '\x97', '\x9C', '\x88', '\x8F', '\x93', '\x98', '\x9D', '\x89', '\x90', '\x94', '\x99', '\x9E', '\x8D', '\x20', '\xCC', '\xCD', '\x84', '\x80', '\x85', '\xE7', '\x83', '\xEA', '\xEE', '\xF2', '\xCB', '\xE9', '\xED', '\xF1', '\xF4', '\xE5', '\xE6', '\xEB', '\xEF', '\xF3', '\x82', '\x20', '\x24', '\xA3', '\xDB', '\x3F', '\x20', '\xB9', '\0' };

// Windows-1252; Windows Latin 1; Western European (Windows); Like ISO-8859-1
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ ?"
static const char aStrWin1252[]     = { '\xE3', '\xF5', '\xF1', '\xE4', '\xF6', '\xE1', '\xE9', '\xED', '\xF3', '\xFA', '\xE0', '\xE8', '\xEC', '\xF2', '\xF9', '\xE2', '\xEA', '\xEE', '\xF4', '\xFB', '\xE7', '\x20', '\xC3', '\xD1', '\xD5', '\xC4', '\xD6', '\xC1', '\xC9', '\xCD', '\xD3', '\xDA', '\xC0', '\xC8', '\xCC', '\xD2', '\xD9', '\xC2', '\xCA', '\xCE', '\xD4', '\xDB', '\xC7', '\x20', '\x24', '\xA3', '\x80', '\xA4', '\x20', '\x3F', '\0' };

// ISO-8859-1: ISO Latin 1; ISO/ANSI Western European
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£?¤ ?"
static const char aStrISO_8859_1[]  = { '\xE3', '\xF5', '\xF1', '\xE4', '\xF6', '\xE1', '\xE9', '\xED', '\xF3', '\xFA', '\xE0', '\xE8', '\xEC', '\xF2', '\xF9', '\xE2', '\xEA', '\xEE', '\xF4', '\xFB', '\xE7', '\x20', '\xC3', '\xD5', '\xD1', '\xC4', '\xD6', '\xC1', '\xC9', '\xCD', '\xD3', '\xDA', '\xC0', '\xC8', '\xCC', '\xD2', '\xD9', '\xC2', '\xCA', '\xCE', '\xD4', '\xDB', '\xC7', '\x20', '\x24', '\xA3', '\x3F', '\xA4', '\x20', '\x3F', '\0' };
// ISO-8859-15: ISO Latin 9; ISO/ANSI Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € instead of ¤)
//                 "ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€? ?"
static const char aStrISO_8859_15[] = { '\xE3', '\xF5', '\xF1', '\xE4', '\xF6', '\xE1', '\xE9', '\xED', '\xF3', '\xFA', '\xE0', '\xE8', '\xEC', '\xF2', '\xF9', '\xE2', '\xEA', '\xEE', '\xF4', '\xFB', '\xE7', '\x20', '\xC3', '\xD5', '\xD1', '\xC4', '\xD6', '\xC1', '\xC9', '\xCD', '\xD3', '\xDA', '\xC0', '\xC8', '\xCC', '\xD2', '\xD9', '\xC2', '\xCA', '\xCE', '\xD4', '\xDB', '\xC7', '\x20', '\x24', '\xA3', '\xA4', '\x3F', '\x20', '\x3F', '\0' };

// Non ASCII standard controls
//                 "◄↕‼¶" <- MS-DOS Controls
//                 "⌘⇧⌥⎈" <- Mac OS Controls
static const char aControls0[] = { 0x11U, 0x12U, 0x13U, 0x14U, 0x00 };

// ASCII Greek
// IBM737; OEM Greek; Greek (MS-DOS)
//                 "Ελλάδα (Greece) έκδοση Κωνσταντίνος Πολυχρόνης £?"
static const char aStrCP737[]  =      { '\x84', '\xA2', '\xA2', '\xE1', '\x9B', '\x98', '\x20', '\x28', '\x47', '\x72', '\x65', '\x65', '\x63', '\x65', '\x29', '\x20', '\xE2', '\xA1', '\x9B', '\xA6', '\xA9', '\x9E', '\x20', '\x89', '\xE0', '\xA4', '\xA9', '\xAB', '\x98', '\xA4', '\xAB', '\xE5', '\xA4', '\xA6', '\xAA', '\x20', '\x8F', '\xA6', '\xA2', '\xAC', '\xAE', '\xA8', '\xE6', '\xA4', '\x9E', '\xAA', '\x20', '\x3F', '\x3F', '\0' };

// x-mac-greek: Mac OS Greek; Greek (Mac)
//                 "Ελλάδα (Greece) έκδοση Κωνσταντίνος Πολυχρόνης £?"
static const char aStrMacGreek[]  =   { '\xB6', '\xEC', '\xEC', '\xC0', '\xE4', '\xE1', '\x20', '\x28', '\x47', '\x72', '\x65', '\x65', '\x63', '\x65', '\x29', '\x20', '\xDB', '\xEB', '\xE4', '\xEF', '\xF3', '\xE8', '\x20', '\xBA', '\xF6', '\xEE', '\xF3', '\xF4', '\xE1', '\xEE', '\xF4', '\xDD', '\xEE', '\xEF', '\xF7', '\x20', '\xA6', '\xEF', '\xEC', '\xF9', '\xF8', '\xF2', '\xDE', '\xEE', '\xE8', '\xF7', '\x20', '\x92', '\x3F', '\0' };

// Windows-1253: Windows Greek; Greek (Windows) + €
//                 "Ελλάδα (Greece) έκδοση Κωνσταντίνος Πολυχρόνης £€"
static const char aStrWin1253[]  =    { '\xC5', '\xEB', '\xEB', '\xDC', '\xE4', '\xE1', '\x20', '\x28', '\x47', '\x72', '\x65', '\x65', '\x63', '\x65', '\x29', '\x20', '\xDD', '\xEA', '\xE4', '\xEF', '\xF3', '\xE7', '\x20', '\xCA', '\xF9', '\xED', '\xF3', '\xF4', '\xE1', '\xED', '\xF4', '\xDF', '\xED', '\xEF', '\xF2', '\x20', '\xD0', '\xEF', '\xEB', '\xF5', '\xF7', '\xF1', '\xFC', '\xED', '\xE7', '\xF2', '\x20', '\xA3', '\x80', '\0' };

// ISO-8859-7: ISO Greek; ISO/ANSI Greek + €
//                 "Ελλάδα (Greece) έκδοση Κωνσταντίνος Πολυχρόνης £€"
static const char aStrISO_8859_7[]  = { '\xC5', '\xEB', '\xEB', '\xDC', '\xE4', '\xE1', '\x20', '\x28', '\x47', '\x72', '\x65', '\x65', '\x63', '\x65', '\x29', '\x20', '\xDD', '\xEA', '\xE4', '\xEF', '\xF3', '\xE7', '\x20', '\xCA', '\xF9', '\xED', '\xF3', '\xF4', '\xE1', '\xED', '\xF4', '\xDF', '\xED', '\xEF', '\xF2', '\x20', '\xD0', '\xEF', '\xEB', '\xF5', '\xF7', '\xF1', '\xFC', '\xED', '\xE7', '\xF2', '\x20', '\xA3', '\xA4', '\0' };

// Unicode encoded in UTF-8
#if !defined(_WIN32)
static const char utf8StrUTF_8[] = u8"ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ π";
#else
static const char utf8StrUTF_8[]  = { '\xC3', '\xA3', '\xC3', '\xB5', '\xC3', '\xB1', '\xC3', '\xA4', '\xC3', '\xB6', '\xC3', '\xA1', '\xC3', '\xA9', '\xC3', '\xAD', '\xC3', '\xB3', '\xC3', '\xBA', '\xC3', '\xA0', 
									  '\xC3', '\xA8', '\xC3', '\xAC', '\xC3', '\xB2', '\xC3', '\xB9', '\xC3', '\xA2', '\xC3', '\xAA', '\xC3', '\xAE', '\xC3', '\xB4', '\xC3', '\xBB', '\xC3', '\xA7', '\x20', '\xC3', 
									  '\x83', '\xC3', '\x95', '\xC3', '\x91', '\xC3', '\x84', '\xC3', '\x96', '\xC3', '\x81', '\xC3', '\x89', '\xC3', '\x8D', '\xC3', '\x93', '\xC3', '\x9A', '\xC3', '\x80', '\xC3', 
									  '\x88', '\xC3', '\x8C', '\xC3', '\x92', '\xC3', '\x99', '\xC3', '\x82', '\xC3', '\x8A', '\xC3', '\x8E', '\xC3', '\x94', '\xC3', '\x9B', '\xC3', '\x87', '\x20', '\x24', '\xC2', 
									  '\xA3', '\xE2', '\x82', '\xAC', '\xC2', '\xA4', '\x20', '\xCF', '\x80', '\0' };
#endif
// Unicode encoded in UTF-8 + BOM
#if !defined(_WIN32)
static const char utf8StrBomUTF_8[] = u8"\xEF\xBB\xBFãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ π";
#else
static const char utf8StrBomUTF_8[]  = {  '\xEF', '\xBB', '\xBF', 
									  '\xC3', '\xA3', '\xC3', '\xB5', '\xC3', '\xB1', '\xC3', '\xA4', '\xC3', '\xB6', '\xC3', '\xA1', '\xC3', '\xA9', '\xC3', '\xAD', '\xC3', '\xB3', '\xC3', '\xBA', '\xC3', '\xA0', 
									  '\xC3', '\xA8', '\xC3', '\xAC', '\xC3', '\xB2', '\xC3', '\xB9', '\xC3', '\xA2', '\xC3', '\xAA', '\xC3', '\xAE', '\xC3', '\xB4', '\xC3', '\xBB', '\xC3', '\xA7', '\x20', '\xC3', 
									  '\x83', '\xC3', '\x95', '\xC3', '\x91', '\xC3', '\x84', '\xC3', '\x96', '\xC3', '\x81', '\xC3', '\x89', '\xC3', '\x8D', '\xC3', '\x93', '\xC3', '\x9A', '\xC3', '\x80', '\xC3', 
									  '\x88', '\xC3', '\x8C', '\xC3', '\x92', '\xC3', '\x99', '\xC3', '\x82', '\xC3', '\x8A', '\xC3', '\x8E', '\xC3', '\x94', '\xC3', '\x9B', '\xC3', '\x87', '\x20', '\x24', '\xC2', 
									  '\xA3', '\xE2', '\x82', '\xAC', '\xC2', '\xA4', '\x20', '\xCF', '\x80', '\0' };
#endif
// Unicode encoded in UTF-16LE
#if !defined(_WIN32)
static const char16_t utf16StrUTF16LE[] = u"ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ π";
#else
static const char16_t utf16StrUTF16LE[] = { 0x00E3U, 0x00F5U, 0x00F1U, 0x00E4U, 0x00F6U, 0x00E1U, 0x00E9U, 0x00EDU, 0x00F3U, 0x00FAU, 0x00E0U, 0x00E8U, 0x00ECU, 0x00F2U, 
											0x00F9U, 0x00E2U, 0x00EAU, 0x00EEU, 0x00F4U, 0x00FBU, 0x00E7U, 0x0020U, 0x00C3U, 0x00D5U, 0x00D1U, 0x00C4U, 0x00D6U, 0x00C1U, 
											0x00C9U, 0x00CDU, 0x00D3U, 0x00DAU, 0x00C0U, 0x00C8U, 0x00CCU, 0x00D2U, 0x00D9U, 0x00C2U, 0x00CAU, 0x00CEU, 0x00D4U, 0x00DBU, 
											0x00C7U, 0x0020U, 0x0024U, 0x00A3U, 0x20ACU, 0x00A4U, 0x0020U, 0x03C0U, 0x0000 };
#endif
// Unicode encoded in UTF-32LE
#if !defined(_WIN32)
static const char32_t utf32StrUTF32LE[] = U"ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ π";
#else
static const char32_t utf32StrUTF32LE[] = { 0x000000E3UL, 0x000000F5UL, 0x000000F1UL, 0x000000E4UL, 0x000000F6UL, 0x000000E1UL, 0x000000E9UL, 0x000000EDUL, 0x000000F3UL, 
											0x000000FAUL, 0x000000E0UL, 0x000000E8UL, 0x000000ECUL, 0x000000F2UL, 0x000000F9UL, 0x000000E2UL, 0x000000EAUL, 0x000000EEUL, 
											0x000000F4UL, 0x000000FBUL, 0x000000E7UL, 0x00000020UL, 0x000000C3UL, 0x000000D5UL, 0x000000D1UL, 0x000000C4UL, 0x000000D6UL, 
											0x000000C1UL, 0x000000C9UL, 0x000000CDUL, 0x000000D3UL, 0x000000DAUL, 0x000000C0UL, 0x000000C8UL, 0x000000CCUL, 0x000000D2UL, 
											0x000000D9UL, 0x000000C2UL, 0x000000CAUL, 0x000000CEUL, 0x000000D4UL, 0x000000DBUL, 0x000000C7UL, 0x00000020UL, 0x00000024UL, 
											0x000000A3UL, 0x000020ACUL, 0x000000A4UL, 0x00000020UL, 0x000003C0UL, 0x00000000 };
#endif
// UTF-32 emojis
// "👎😃🐁𐀀𐀟𐀏ᇿ😜👍"
#if !defined(_WIN32)
static const char32_t utf32StrEmojis[] = U"\U0001F44E\U0001F603\U0001F401\U00010000\U0001001F\U0001000F\U000011FF\U0001F61C\U0001F44D";
#else
static const char32_t utf32StrEmojis[] = { 0x0001F44EUL, 0x0001F603UL, 0x0001F401UL, 0x00010000UL, 0x0001001FUL, 0x0001000FUL, 0x000011FFUL, 0x0001F61CUL, 0x0001F44DUL, 0x00000000 };
#endif

int main(void)
{
    // Set the locale of the console to the user default
#if defined(_WIN32)
	::setlocale(LC_CTYPE, "");
	locale objNewLocale(locale(""));
#else
	::setlocale(LC_CTYPE, "en_US.UTF-8");
	locale objNewLocale(locale("en_US.UTF-8"), locale("C"), locale::numeric);
#endif
    locale oldLoc = locale::global(objNewLocale);
    cout.imbue(locale(objNewLocale, new numpunct_byname<char>("C")));
    wcout.imbue(locale(objNewLocale, new numpunct_byname<wchar_t>("C")));

    string narrowString;
	wstring wideString;
	string utf8Str;
	u16string utf16Str;
	u32string utf32Str;
	CodePage2Unicode * objString = new CodePage2Unicode();

	wcout << endl;
	wcout << L"Compilation Environment: " << endl;
	wcout << L"\tCompiler Type:     " << __COMPILER_TYPE << endl;
	wcout << L"\tCompiler Version:  " << __COMPILER_VERSION_MAJOR << L'.' << __COMPILER_VERSION_MINOR << L'.' << __COMPILER_VERSION_BUILD << L'.' << __COMPILER_VERSION_PATCH << endl;
	wcout << L"\tCPU Family:        " << __COMPILER_CPU_FAMILY << endl;
	wcout << L"\tCPU bits:          " << __COMPILER_CPU_BITS << L"-bit" << endl;
	wcout << L"\tCPU Byte Order:    " << __COMPILER_CPU_BYTE_ORDER << L"-Endian" << endl;
	wcout << L"\tPlatform Type:     " << __COMPILER_PLATFORM_TYPE << endl;
	wcout << L"\tPlatform Sub-Type: " << __COMPILER_PLATFORM_SUBTYPE << endl;
	wcout << endl;

	wcout << endl;
	wcout << L"Platform Locale and Character Information: " << endl;
	wcout << L"\tApplication Default Locale: " << oldLoc.name().c_str() << endl;
	wcout << L"\tApplication Current Locale: " << locale().name().c_str() << endl;
	wcout << L"\tClassic Locale:             " << locale::classic().name().c_str() << endl;
	wcout << L"\tUser Locale:                " << locale("").name().c_str() << endl;
	locale namelessLocale(std::locale(), new std::ctype<char>);
	wcout << L"\tNameless Locale:            " << namelessLocale.name().c_str() << endl;
	wcout << L"\tCurrent 'cout' Locale:      " << cout.getloc().name().c_str() << endl;
	wcout << L"\tCurrent 'wcout' Locale:     " << wcout.getloc().name().c_str() << endl;
	wcout << L"\tNarrow 'char' Size:         " << objString->getNarrowCharByteSize() << endl;
	wcout << L"\tWide 'wchar_t' Size:        " << objString->getWideCharByteSize() << endl;
	wcout << L"\t'_TCHAR' Character Size:    " << objString->getTCharByteSize() << endl;
	wcout << boolalpha;
	wcout << L"\tIs Wide Char UCS-4/UTF-32:  " << objString->isWideCharUtf32() << endl;
	wcout << L"\tIs Wide Char UCS-2/UTF-16:  " << objString->isWideCharUtf16() << endl;
	wcout << L"\tIs Application API UCS/UTF: " << objString->isApplicationApiWideUnicode() << endl;
	wcout << L"\tIs Application API UTF-8:   " << objString->isApplicationApiNarrowUtf8() << endl;
	wcout << L"\tIs Application API ASCII:   " << objString->isApplicationApiNarrowAscii() << endl;
	wcout << L"\tIs Application API MBCS:    " << objString->isApplicationApiMbcs() << endl;
	wcout << L"\tNarrow 'char' Code Page:    " << (uint32_t)objString->getDefaultNarrowCodePage() << endl;
	wcout << noboolalpha;

	wcout << endl;
	wcout << L"8-bit ASCII Narrow Char to UTF-32 Conversions: " << endl;
	wstring strOriginal(L"ãõñäöáéíóúàèìòùâêîôûç ÃÕÑÄÖÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÇ $£€¤ π");
	wcout << L"\tOriginal:     " << strOriginal << endl;
	string strCP367(aStrCP367);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP367, CodePage::US_ASCII);
	wcout << L"\tDOS CP367:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strCP437(aStrCP437);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP437, CodePage::DOS_CP437);
	wcout << L"\tDOS CP437:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strCP850(aStrCP850);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP850, CodePage::DOS_CP850);
	wcout << L"\tDOS CP850:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strCP858(aStrCP858);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP858, CodePage::DOS_CP858);
	wcout << L"\tDOS CP858:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strCP859(aStrCP859);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP859, CodePage::DOS_CP859);
	wcout << L"\tDOS CP859:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strCP860(aStrCP860);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP860, CodePage::DOS_CP860);
	wcout << L"\tDOS CP860:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strMacRoman(aStrMacRoman);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strMacRoman, CodePage::MAC_ROMAN);
	wcout << L"\tMacOS Roman:  " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strWin1252(aStrWin1252);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strWin1252, CodePage::WINDOWS_1252);
	wcout << L"\tWindows 1252: " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strISO_8859_1(aStrISO_8859_1);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strISO_8859_1, CodePage::ISO_8859_1);
	wcout << L"\tISO 8859-1:   " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strISO_8859_15(aStrISO_8859_15);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strISO_8859_15, CodePage::ISO_8859_15);
	wcout << L"\tISO 8859-15:  " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;

#if !defined(_WIN32)
	wcout << endl;
	wcout << L"7-bit ASCII Controls Narrow to UTF-32 Conversions: " << endl;
	string strControls0((char *)aControls0);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strControls0, CodePage::DOS_CP850, true);
	wcout << L"\tMS-DOS Controls: " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	utf32Str = objString->convertStringAscii_to_StringUtf32(strControls0, CodePage::MAC_ROMAN, true);
	wcout << L"\tMacOS Controls:  " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;

	wcout << endl;
	wcout << L"Greek ASCII Narrow Char to UTF-32 Conversions: " << endl;
	wcout << L"\tOriginal:     " << L"Ελλάδα (Greece) έκδοση Κωνσταντίνος Πολυχρόνης £€" << endl;
	string strCP737(aStrCP737);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strCP737, CodePage::DOS_CP737);
	wcout << L"\tDOS CP737:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strMacGreek(aStrMacGreek);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strMacGreek, CodePage::MAC_GREEK);
	wcout << L"\tMacOS Greek:  " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strWin1253(aStrWin1253);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strWin1253, CodePage::WINDOWS_1253);
	wcout << L"\tWindows 1253: " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	string strISO_8859_7(aStrISO_8859_7);
	utf32Str = objString->convertStringAscii_to_StringUtf32(strISO_8859_7, CodePage::ISO_8859_7);
	wcout << L"\tISO 8859-7:   " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
#endif

	wcout << endl;
	wcout << L"Unicode Wide Char to UTF Conversions: " << endl;
	wcout << L"\tWide Char Original:  " << strOriginal << endl;
	utf8Str = string(utf8StrUTF_8);
	wcout << L"\tUTF-8 to Wide Char:  " << objString->convertStringUtf8_to_StringWide(utf8Str) << endl;
	utf16Str = u16string(utf16StrUTF16LE);
	wcout << L"\tUTF-16 to Wide Char: " << objString->convertStringUtf16_to_StringWide(utf16Str) << endl;
    utf32Str = u32string(utf32StrUTF32LE);
	wcout << L"\tUTF-32 to Wide Char: " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	wideString = strOriginal;
	utf8Str = objString->convertStringWide_to_StringUtf8(wideString);
	wcout << L"\tWide Char to UTF-8:  " << objString->convertStringUtf8_to_StringWide(utf8Str) << endl;
	utf16Str = objString->convertStringWide_to_StringUtf16(wideString);
	wcout << L"\tWide Char to UTF-16: " << objString->convertStringUtf16_to_StringWide(utf16Str) << endl;
	utf32Str = objString->convertStringWide_to_StringUtf32(wideString);
	wcout << L"\tWide Char to UTF-32: " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	narrowString = objString->convertStringWide_to_StringNarrow(strOriginal);
	wcout << L"\tWide Char to Narrow: " << narrowString.c_str() << endl;
#if defined(_WIN32)
	wideString = objString->convertStringNarrow_to_StringWide(strWin1252);
#else
    narrowString = string((char *)utf8StrUTF_8);
    wideString = objString->convertStringNarrow_to_StringWide(narrowString);
#endif
	wcout << L"\tNarrow Char to Wide: " << wideString << endl;
	
#if !defined(_WIN32)
	wcout << endl;
	wcout << L"UTF-32 Emojis to Unicode Wide Char Conversions: " << endl;
	utf32Str = u32string(utf32StrEmojis);
	wcout << L"\tUTF-32 Emojis to Wide Char: " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	utf16Str = objString->convertStringUtf32_to_StringUtf16(utf32Str);
	wcout << L"\tUTF-32 Emojis to UTF-16:    " << objString->convertStringUtf16_to_StringWide(utf16Str) << endl;
#endif

	wcout << endl;
	wcout << L"UTF-8 to Wide Char Conversions: " << endl;
	wcout << boolalpha;
    bool bIsUtf8 = false;
    wcout << L"\tIs Valid UTF-8 String:        " << objString->isUtf8(utf8StrUTF_8, sizeof(utf8StrUTF_8), &bIsUtf8) << endl;
    wcout << L"\tIs UTF-8 String + Surrogates: " << bIsUtf8 << endl;
	wcout << L"\tUTF-8 Has BOM:                " << objString->hasUtf8Bom(utf8Str) << endl;
    wcout << L"\tOriginal:           " << strOriginal << endl;
	utf8Str = string(utf8StrUTF_8);
	utf16Str = objString->convertStringUtf8_to_StringUtf16(utf8Str);
    wcout << L"\tUTF-8 to UTF-16:    " << objString->convertStringUtf16_to_StringWide(utf16Str) << endl;
    utf32Str = objString->convertStringUtf8_to_StringUtf32(utf8Str);
    wcout << L"\tUTF-8 to UTF-32:    " << objString->convertStringUtf32_to_StringWide(utf32Str) << endl;
	wideString = objString->convertStringUtf8_to_StringWide(utf8Str);
	wcout << L"\tUTF-8 to Wide Char: " << wideString << endl;
    utf32Str = objString->convertStringWide_to_StringUtf32(strOriginal);
	utf8Str = objString->convertStringUtf32_to_StringUtf8(utf32Str);
	wideString = objString->convertStringUtf8_to_StringWide(utf8Str);
	wcout << L"\tUTF-32 to UTF-8:    " << wideString << endl;
	utf8Str = string(utf8StrBomUTF_8);
	wcout << L"\tIs Valid UTF-8 String:        " << objString->isUtf8(utf8StrUTF_8, sizeof(utf8StrUTF_8), &bIsUtf8) << endl;
    wcout << L"\tIs UTF-8 String + Surrogates: " << bIsUtf8 << endl;
	wcout << L"\tUTF-8 Has BOM:                " << objString->hasUtf8Bom(utf8Str) << endl;
	utf8Str = objString->removeUtf8Bom(utf8Str);
	wideString = objString->convertStringUtf8_to_StringWide(utf8Str);
	wcout << L"\tUTF-8 + BOM Marker: " << wideString << endl;
    wcout << noboolalpha;

	/*
	narrowString = string("Êùíóôáíôßíïò Ðïëõ÷ñüíçò");
for(unsigned i = 0; i < narrowString.length(); i++)
	    wcout << L"'\\x" << hex << uppercase << (unsigned char)narrowString.at(i) << nouppercase << dec << L"', ";
	wcout << endl;*/
	/*wcout << endl;
	for(unsigned i = 1; i <= 255; i++)
	{
	    char32_t c = objString->convertCharAscii_to_CharUtf32(i, CodePage::ISO_8859_15);
	    wcout << L"Char #" << i << L" = ";
	    if(c != 0)
	    {
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
	        wcout << ((char)c);
#else
	        wcout << ((wchar_t)c);
#endif
	    }
	    else
	    {
	        wcout << L"";
	    }
	    wcout << endl;
	}*/

	return 0;
}
