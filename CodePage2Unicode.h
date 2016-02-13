/**
 * CodePage2Unicode.h
 *
 * ABSTRACT
 *  Defenition of the CodePage2Unicode API and objects that convert strings from ASCII to Unicode and vice versa.
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

#ifndef _CODEPAGE2UNICODE_H_
#define _CODEPAGE2UNICODE_H_

#pragma once

#include "StdAfx.h"

using namespace std;


/**
 * Enumeration width the 8-bit code pages that can be used for conversion
 * to Unicode UTF-32.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @since	1.0
 */
#ifdef __cpp_strong_enums
    // C++11 standard compliment
    enum class CodePage : unsigned int
#else
    // Not C++11 standard compliment
    enum CodePage
#endif
{
	/**
	 *  Unknown code page
	 */
    UNKNOWN = 0, 
	/**
	 *  CP367: US-ASCII
	 */
	US_ASCII = 20127, 
	/**
	 *  CP437: IBM/OEM/MS-DOS USA English
	 */
    DOS_CP437 = 437, 
	/**
	 *  CP737: IBM/OEM/MS-DOS Greek
	 */
    DOS_CP737 = 737, 
	/**
	 *  CP850: IBM/OEM/MS-DOS Multilingual/Latin 1/Western European
	 */
    DOS_CP850 = 850, 
	/**
	 *  CP851: IBM/OEM/MS-DOS Greek 1
	 */
	DOS_CP851 = 851, 
	/**
	 *  CP858: IBM/OEM/MS-DOS Multilingual/Latin 1/Western European + €
	 */
    DOS_CP858 = 858, 
	/**
	 *  CP858: IBM/OEM/MS-DOS Latin 9/Western European + Finnish + French + €
	 */
    DOS_CP859 = 859, 
	/**
	 *  CP860: IBM/OEM/MS-DOS Portuguese
	 */
    DOS_CP860 = 860, 
	/**
	 *  CP869: IBM/OEM/MS-DOS Greek 2
	 */
	DOS_CP869 = 869, 
	/**
	 *  MacRoman: Macintosh Latin 1/Western European + €
	 */
    MAC_ROMAN = 10000, 
	/**
	 *  MacGreek: Macintosh Greek + €
	 */
    MAC_GREEK = 10006, 
	/**
	 *  Windows-1252: Windows ANSI Latin 1/Western European + €
	 */
    WINDOWS_1252 = 1252, 
	/**
	 *  Windows-1253: Windows ANSI Greek + €
	 */
    WINDOWS_1253 = 1253, 
	/**
	 *  ISO-8859-1: ISO/IEC Latin 1/Western European
	 */
    ISO_8859_1 = 28591, 
	/**
	 *  ISO-8859-7: ISO/IEC Greek + €
	 */
    ISO_8859_7 = 28597, 
	/**
	 *  ISO-8859-15: ISO/IEC Latin 9/Western European + Finnish + French + €
	 */
    ISO_8859_15 = 28605, 
	/**
	 *  UCS-2: Unicode (2 bytes Universal Character Set), maps to UTF-16 BMP (Basic Multilingual Plane)
	 */
	UCS_2 = 1201, 
	/**
	 *  UCS-4: Unicode (4 bytes Universal Character Set), maps to UTF-32
	 */
	UCS_4 = 12001, 
	/**
	 *  UTF-7: Unicode (7-bit, 1 to 6 bytes Unicode Transformation Format)
	 */
	UTF_7 = 65000, 
	/**
	 *  UTF-8: Unicode (8-bit, 1 to 6 bytes Unicode Transformation Format)
	 */
	UTF_8 = 65001, 
	/**
	 *  UTF-16: Unicode (16-bit, 2 or 4 bytes Unicode Transformation Format)
	 */
	UTF_16 = 1200, 
	/**
	 *  UTF-32: Unicode (32-bit, 4 bytes Unicode Transformation Format)
	 */
	UTF_32 = 12000
};

/**
 * Implements the necessary functionality to convert strings from/to ASCII, UTF-8, UTF-16,
 * UTF-32.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @since	1.0
 */
class CodePage2Unicode
{
private:
    /* Unicode UTF BOMs (Byte Order Markers) */

    /**
     * UTF-7 BOM - (5 bytes, endianless).
     */
    static const char BOM_UTF7[5];

    /**
     * UTF-8 BOM - (3 bytes, endianless, should not be used).
     */
    static const char BOM_UTF8[3];

    /**
     * UTF-16 BOM - (2 bytes, little endian).
     */
    static const char16_t BOM_UTF16LE[1];

    /**
     * UTF-16 BOM - (2 bytes, big endian).
     */
    static const char16_t BOM_UTF16BE[1];

    /**
     * UTF-32 BOM - (4 bytes, little endian).
     */
    static const char32_t BOM_UTF32LE[1];

    /**
     * UTF-32 BOM - (4 bytes, big endian).
     */
    static const char32_t BOM_UTF32BE[1];

    /* Special Characters */

    /**
     * The ASCII replacement character: "?".
     */
    static const char ASCII_REPLACEMENT_CHARACTER = (char)'?';

    /**
     * The Unicode replacement character: "�".
     */
    static const char16_t UNICODE_REPLACEMENT_CHARACTER = (char16_t)0xFFFD;

    /* Conversion Constants */

    /**
     * UTF-8 half shifting by 6-bit. Used for conversion to/from UTF-32.
     */
    static const unsigned int UTF8_HALF_SHIFT = 6;

    /**
     *  UTF-8 2 bytes surrogate high. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES2 = (char)0xC0U; // 110xxxxx
    /**
     *  UTF-8 2 bytes surrogate high mask. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES2_MASK = (char)0x1FU; // 00011111
    /**
     *  UTF-8 3 bytes surrogate high. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES3 = (char)0xE0U; // 1110xxxx
    /**
     *  UTF-8 3 bytes surrogate high mask. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES3_MASK = (char)0x0FU; // 00001111
    /**
     *  UTF-8 4 bytes surrogate high. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES4 = (char)0xF0U; // 11110xxx
    /**
     *  UTF-8 4 bytes surrogate high mask. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES4_MASK = (char)0x07U; // 00000111
    /**
     *  UTF-8 5 bytes surrogate high. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES5 = (char)0xF8U; // 111110xx
    /**
     *  UTF-8 5 bytes surrogate high mask. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES5_MASK = (char)0x03U; // 00000011
    /**
     *  UTF-8 6 bytes surrogate high. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES6 = (char)0xFCU; // 1111110x
    /**
     *  UTF-8 6 bytes surrogate high mask. Used for conversion to/from UTF-32.
     */
    static const char UTF8_LEAD_BYTES6_MASK = (char)0x01U; // 00000001
    /**
     *  UTF-8 N bytes surrogate low. Used for conversion to/from UTF-32.
     */
    static const char UTF8_NEXT = (char)0x80U; // 10xxxxxx
    /**
     *  UTF-8 N bytes surrogate low mask. Used for conversion to/from UTF-32.
     */
    static const char UTF8_NEXT_MASK = (char)0x3FU; // 00111111

    /**
     * UTF-16 half shifting by 10-bit. Used for conversion to/from UTF-32.
     */
    static const unsigned int UTF16_HALF_SHIFT = 10;
    /**
     * UTF-16 half mask. Used for conversion to/from UTF-32.
     */
    static const char32_t UTF16_HALF_MASK = (char32_t)0x03FFUL;     // 00000000000000000000001111111111
    /**
     * UTF-16 half base. Used for conversion to/from UTF-32.
     */
    static const char32_t UTF16_HALF_BASE = (char32_t)0x0010000UL;  // 00000000000000010000000000000000

    /**
     * UTF-16 high surrogate start. Used for conversion to/from UTF-32.
     */
    static const char16_t UNICODE_HIGH_SURROGATE_START = (char16_t)0xD800;
    /**
     * UTF-16 high surrogate end. Used for conversion to/from UTF-32.
     */
    static const char16_t UNICODE_HIGH_SURROGATE_END = (char16_t)0xDBFF;

    /**
     * UTF-16 low surrogate start. Used for conversion to/from UTF-32.
     */
    static const char16_t UNICODE_LOW_SURROGATE_START = (char16_t)0xDC00;
    /**
     * UTF-16 low surrogate end. Used for conversion to/from UTF-32.
     */
    static const char16_t UNICODE_LOW_SURROGATE_END = (char16_t)0xDFFF;

    /**
     * Minimum Unicode code point.
     */
    static const char32_t UNICODE_MINIMUM = (char32_t)0x000000;
    /**
     * Maximum Unicode code point (as Unicode 6.3).
     */
    static const char32_t UNICODE_MAXIMUM = (char32_t)0x10FFFF;

    /**
     * Maximum Unicode BMP code point (as Unicode 2.0).
     */
    static const char32_t UNICODE_MAXIMUM_BMP = (char32_t)0xFFFF;


    /* Standard ASCII Code Page Maps to Unicode */

    /**
     * Standard ISO/ANSI ASCII (7-bit).
     */
    // static const char32_t m_arrASCII[128];

    /**
     * Standard ISO/ANSI ASCII  (7-bit) MS-DOS extensions.
     */
    static const char32_t m_arrDOS_ASCII[128];

    /**
     * Standard ISO/ANSI ASCII  (7-bit) Mac OS extensions.
     */
    // static const char32_t m_arrMac_ASCII[128];


    /* Extended ASCII Code Page Maps to Unicode */

	/**
     * Extended ASCII code page IBM 367/OEM 367: MS-DOS US-ASII.<br />
     * Suitable for writing in: English US.<br />
     * Script:	Latin<br />
     * IANA/MIME: US-ASCII, IBM367, cp367, OEM-367<br />
     * C/C++ locale options: <br />
     * Win32 CP: 367
     */
    // static const char32_t m_arrDOS_CP367[128];

    /**
     * Extended ASCII code page IBM 437/OEM 437: MS-DOS Latin US.<br />
     * Suitable for writing in: English, Western Europe, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: IBM437, cp437, OEM-437<br />
     * C/C++ locale options: <br />
     * Win32 CP: 437
     */
    static const char32_t m_arrDOS_CP437[128];

    /**
     * Extended ASCII code page IBM 737/OEM 737: MS-DOS Greek.<br />
     * Suitable for writing in: Greek, English, etc. .<br />
     * Script:	Greek<br />
     * IANA/MIME: IBM737, cp737, OEM-737<br />
     * C/C++ locale options: <br />
     * Win32 CP: 737
     */
    static const char32_t m_arrDOS_CP737[128];

    /**
     * Extended ASCII code page IBM 850/OEM 850: MS-DOS Latin-1/Multilingual.<br />
     * Suitable for writing in: Latin-1, Western Europe, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: IBM850, cp850, OEM-850<br />
     * C/C++ locale options: <br />
     * Win32 CP: 850
     */
    static const char32_t m_arrDOS_CP850[128];

    /**
     * Extended ASCII code page IBM 858/OEM 858: MS-DOS Latin-1/Multilingual with €.<br />
     * Suitable for writing in: Latin-1, Western Europe, €, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: IBM858, cp858, OEM-858<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 858
     */
    // static const char32_t m_arrDOS_CP858[128];

    /**
     * Extended ASCII code page IBM 859/OEM 859: MS-DOS Latin-9.<br />
     * Suitable for writing in: Latin-9, Latin-1, Western Europe, €, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: IBM859, cp859, OEM-859<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 859
     */
    static const char32_t m_arrDOS_CP859[128];

    /**
     * Extended ASCII code page IBM 860/OEM 860: MS-DOS Portuguese.<br />
     * Suitable for writing in: Portuguese, Western Europe, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: IBM860, cp860, OEM-860<br />
     * C/C++ locale options: <br />
     * Win32 CP: 860
     */
    static const char32_t m_arrDOS_CP860[128];

    /**
     * Extended ASCII code page Apple Macintosh/Mac OS Roman: Mac OS Latin-1/Roman.<br />
     * Suitable for writing in: Latin-1, Western Europe, €, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: macintosh, mac, MacRoman<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 10000
     */
    static const char32_t m_arrMac_Roman[128];

    /**
     * Extended ASCII code page Apple Macintosh/Mac OS Greek: Mac OS Greek.<br />
     * Suitable for writing in: Greek, English, etc. .<br />
     * Script:	Greek<br />
     * IANA/MIME: x-mac-greek, MacGreek<br />
     * C/C++ locale options: <br />
     * Win32 CP: 10006
     */
    static const char32_t m_arrMac_Greek[128];

    /**
     * Extended ASCII code page Microsoft Windows 1252: Windows Latin-1/Western Europe.<br />
     * Suitable for writing in: Latin-1, Western Europe, €, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: windows-1252, cp1252<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 1252
     */
    static const char32_t m_arrWindows_1252[128];

    /**
     * Extended ASCII code page Microsoft Windows 1253: Windows Greek.<br />
     * Suitable for writing in: Greek, English, €, etc. .<br />
     * Script:	Greek<br />
     * IANA/MIME: windows-1253, cp1253<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 1253
     */
    static const char32_t m_arrWindows_1253[128];

    /**
     * Extended ASCII code page ISO/IEC 8859-1: ISO/IEC Latin-1.<br />
     * Suitable for writing in: Latin-1, Western Europe, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: ISO-8859-1, iso8859-1<br />
     * C/C++ locale options: <br />
     * Win32 CP: 28591
     */
    // static const char32_t m_arrISO_8859_1[128];

    /**
     * Extended ASCII code page ISO/IEC 8859-7: ISO/IEC Greek.<br />
     * Suitable for writing in: Greek, English, €, etc. .<br />
     * Script:	Greek<br />
     * IANA/MIME: ISO-8859-7, iso8859-7<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 28597
     */
    static const char32_t m_arrISO_8859_7[128];

    /**
     * Extended ASCII code page ISO/IEC 8859-15: ISO/IEC Latin-9.<br />
     * Suitable for writing in: Latin-9, Latin-1, Western Europe, €, etc. .<br />
     * Script:	Latin<br />
     * IANA/MIME: ISO-8859-15, iso8859-15<br />
     * C/C++ locale options: @euro<br />
     * Win32 CP: 28605
     */
    // static const char32_t m_arrISO_8859_15[128];

    /**
     * Converts a 7-bit ISO/ANSI ASCII character to the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [0; 127] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertASCII_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 0) && (code <= 127));
#endif

        return code;
    }

    /**
     * Converts a 7-bit MS-DOS/Windows ASCII (width extensions) character to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [0; 127] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_ASCII_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 0) && (code <= 127));
#endif

        if(((code >= 0) && (code <= 31)) || (code == 127))
        {
            // 7-bit MS-DOS/Windows ASCII (width extensions)
            return m_arrDOS_ASCII[code];
        }
        // else
        return code;
    }

    /**
     * Converts a 7-bit Apple Macintosh ASCII (width extensions) character to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [0; 127] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertMac_ASCII_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 0) && (code <= 127));
#endif

        if((code >= 17) && (code <= 20))
        {
            // 7-bit Apple Macintosh ASCII (width extensions)
            switch(code)
            {
                case 17:
                    // "⌘" - Command key
                    return (char32_t)0x2318;
                    break;

                case 18:
                    // "⇧" - Shift key
                    return (char32_t)0x21E7;
                    break;

                case 19:
                    // "⌥"  - Option key
                    return (char32_t)0x2325;
                    break;

                case 20:
                    // "⎈" - Control key
                    return (char32_t)0x2388;
                    break;
            }
            // return (m_arrMac_ASCII[code]);
        }
        // else
        return code;
    }

	/**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 367 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP367_To_Unicode(const char narrowChar)
    {
#if defined(_DEBUG)
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));
        // Validate parameters
        assert((code >= 128) && (code <= 255));
#endif

        return (char32_t)UNICODE_REPLACEMENT_CHARACTER;
    }

    /**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 437 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP437_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrDOS_CP437[code - 128];
    }

    /**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 737 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP737_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrDOS_CP737[code - 128];
    }

    /**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 850 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP850_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrDOS_CP850[code - 128];
    }

    /**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 858 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP858_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        // Same as CP850 except for character 213, "ı" changed to "€"
        if(code == 213)
        {
            // "ı" changed to "€"
            return (char32_t)0x20AC;
        }
        // else
        return m_arrDOS_CP850[code - 128];
    }

    /**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 859 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP859_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrDOS_CP859[code - 128];
    }

    /**
     * Converts a 8-bit IBM/OEM/MS-DOS extended ASCII character from code page 860 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertDOS_CP860_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrDOS_CP860[code - 128];
    }

    /**
     * Converts a 8-bit Apple Macintosh extended ASCII character from code page MacRoman to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertMac_Roman_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrMac_Roman[code - 128];
    }

    /**
     * Converts a 8-bit Apple Macintosh extended ASCII character from code page MacGreek to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertMac_Greek_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrMac_Greek[code - 128];
    }

    /**
     * Converts a 8-bit Microsoft Windows extended ASCII character from code page 1252 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertWindows_1252_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrWindows_1252[code - 128];
    }

    /**
     * Converts a 8-bit Microsoft Windows extended ASCII character from code page 1253 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertWindows_1253_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrWindows_1253[code - 128];
    }

    /**
     * Converts a 8-bit ISO/IEC extended ASCII character from code page 8859-1 to
     * the equivalent UTF-32 code.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertISO_8859_1_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return code;
    }

    /**
     * Converts a 8-bit ISO/IEC extended ASCII character from code page 8859-7 to
     * the equivalent UTF-32 code.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertISO_8859_7_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        return m_arrISO_8859_7[code - 128];
    }

    /**
     * Converts a 8-bit ISO/IEC extended ASCII character from code page 8859-15 to
     * the equivalent UTF-32 code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar	the ASCII character [128; 255] to be converted
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    inline static char32_t convertISO_8859_15_To_Unicode(const char narrowChar)
    {
        char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

        // Validate parameters
#if defined(_DEBUG)
        assert((code >= 128) && (code <= 255));
#endif

        switch(code)
        {
            case 164:
                // "¤" changed to "€"
                return (char32_t)0x20AC;

                break;

            case 166:
                // "¦" changed to "Š"
                return (char32_t)0x0160;

                break;

            case 168:
                // "¨" changed to "š"
                return (char32_t)0x0161;

                break;

            case 180:
                // "´" changed to "Ž"
                return (char32_t)0x017D;

                break;

            case 184:
                // "¸" changed to "ž"
                return (char32_t)0x017E;

                break;

            case 188:
                // "¼" changed to "Œ"
                return (char32_t)0x0152;

                break;

            case 189:
                // "½" changed to "œ"
                return (char32_t)0x0153;

                break;

            case 190:
                // "¾" changed to "Ÿ"
                return (char32_t)0x0178;

                break;
        }

        return code;
    }

    /**
     * Converts an UTF-16 encoded string to the equivalent 2 bytes system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf16String			the UTF-16 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent 2 bytes system wide character encoded string
     * @since	1.0
     */
    static wstring convertStringUtf16_to_StringWide2(const u16string& utf16String, const bool strictConversion = false);

    /**
     * Converts a 2 bytes system wide character encoded string to the equivalent UTF-16 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString			the 2 bytes system wide character encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                          invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-16 encoded string
     * @since	1.0
     */
    static u16string convertStringWide2_to_StringUtf16(const wstring& wideString, const bool strictConversion = false);

    /**
     * Converts an UTF-16 encoded string to the equivalent 4 bytes system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf16String			the UTF-16 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent 4 bytes system wide character encoded string
     * @since	1.0
     */
    static wstring convertStringUtf16_to_StringWide4(const u16string& utf16String, const bool strictConversion = false);

    /**
     * Converts a 4 bytes system wide character encoded string to the equivalent UTF-16 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString			the 4 bytes system wide character encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                          invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-16 encoded string
     * @since	1.0
     */
    static u16string convertStringWide4_to_StringUtf16(const wstring& wideString, const bool strictConversion = false);

    /**
     * Converts an UTF-32 encoded string to the equivalent 2 bytes system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf32String			the UTF-32 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent 2 bytes system wide character encoded string
     * @since	1.0
     */
    static wstring convertStringUtf32_to_StringWide2(const u32string& utf32String, const bool strictConversion = false);

    /**
     * Converts an 2 bytes system wide character encoded string to the equivalent UTF-32 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString			the 2 bytes system wide character encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-32 string
     * @since	1.0
     */
    static u32string convertStringWide2_to_StringUtf32(const wstring& wideString, const bool strictConversion = false);

    /**
     * Converts an UTF-32 encoded string to the equivalent 4 bytes system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf32String			the UTF-32 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent 4 bytes system wide character encoded string
     * @since	1.0
     */
    static wstring convertStringUtf32_to_StringWide4(const u32string& utf32String, const bool strictConversion = false);

    /**
     * Converts an 4 bytes system wide character encoded string to the equivalent UTF-32 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString			the 4 bytes system wide character encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-32 string
     * @since	1.0
     */
    static u32string convertStringWide4_to_StringUtf32(const wstring& wideString, const bool strictConversion = false);

    /**
     * Get the number of code units in bytes to decode a given UTF-8 encoded character to an Unicode code point.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf8	the UTF-8 lead character/byte
     * @return	the number of code units in bytes needed to decode an UTF-8 sequence
     * @since	1.0
     */
    static inline size_t getCodeUnitsForUtf8Leads(char charUtf8)
    {
        size_t sequenceBytes = 0;

        if(!(charUtf8 & UTF8_NEXT))
        {
            sequenceBytes = 1;
        }
        else if((char)(charUtf8 & (~UTF8_LEAD_BYTES2_MASK)) == UTF8_LEAD_BYTES2)
        {
            sequenceBytes = 2;
        }
        else if((char)(charUtf8 & (~UTF8_LEAD_BYTES3_MASK)) == UTF8_LEAD_BYTES3)
        {
            sequenceBytes = 3;
        }
        else if((char)(charUtf8 & (~UTF8_LEAD_BYTES4_MASK)) == UTF8_LEAD_BYTES4)
        {
            sequenceBytes = 4;
        }
        else if((char)(charUtf8 & (~UTF8_LEAD_BYTES5_MASK)) == UTF8_LEAD_BYTES5)
        {
            sequenceBytes = 5;
        }
        else if((char)(charUtf8 & (~UTF8_LEAD_BYTES6_MASK)) == UTF8_LEAD_BYTES6)
        {
            sequenceBytes = 6;
        }

        if((sequenceBytes <= 0) || (sequenceBytes > 4))
        {
            throw logic_error("Invalid UTF-8 sequence header value");
        }

        return sequenceBytes;
    }

    /**
     * Get the number of code units in bytes need to encode a Unicode code point to UTF-8 sequence.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-8 lead character/byte
     * @return	the number of code units in bytes needed to encode the character in UTF-8
     * @since	1.0
     */
    static inline size_t getCodeUnitsForUtf8Char(char32_t charUtf32)
    {
        size_t sequenceBytes = 0;

        if(!(charUtf32 & (~0x0000007FUL)))
        {
            sequenceBytes = 1;
        }
        else if(!(charUtf32 & (~0x000007FFUL)))
        {
            sequenceBytes = 2;
        }
        else if(!(charUtf32 & (~0x0000FFFFUL)))
        {
            sequenceBytes = 3;
        }
        else if(!(charUtf32 & (~0x001FFFFFUL)))
        {
            sequenceBytes = 4;
        }
        else if(!(charUtf32 & (~0x03FFFFFFUL)))
        {
            sequenceBytes = 5;
        }
        else if(!(charUtf32 & (~0x7FFFFFFFUL)))
        {
            sequenceBytes = 6;
        }

        if((sequenceBytes < 1) || (sequenceBytes > 4))
        {
            throw logic_error("Invalid UTF-32 code point value");
        }

        return sequenceBytes;
    }

public:
    /**
     * Default class 'CodePage2Unicode' constructor.
     * Creates a mew object instance.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @since	1.0
     */
    explicit CodePage2Unicode()
    {
	
	}

    /**
     * Default class 'CodePage2Unicode' destructor.
     * Destroys this object instance.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @since	1.0
     */
    ~CodePage2Unicode()
    {
	
	}

    /**
     * Gets the narrow character size in bytes.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	the size in bytes of a 'char'
     * @since	1.0
     */
    inline static size_t getNarrowCharByteSize(void)
    {
        return sizeof(char);
    }

    /**
     * Gets the wide character size in bytes.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	the size in bytes of a 'wchar_t'
     * @since	1.0
     */
    inline static size_t getWideCharByteSize(void)
    {
        return sizeof(wchar_t);
    }

    /**
     * Gets the narrow/wide character size in bytes, according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	the size in bytes of a '_TCHAR'
     * @since	1.0
     */
    inline static size_t getTCharByteSize(void)
    {
        return sizeof(_TCHAR);
    }

	static CodePage getDefaultNarrowCodePage(void);

    /**
     * Checks if the narrow character set code page is UTF-8, according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the default narrow character set code page is UTF-8, 'false' otherwise
     * @since	1.0
     */
    // inline static bool isNarrowCharUtf8(void)
    // {
    // return (__CHAR_NARROW_TYPE == __CHAR_NARROW_TYPE_UTF8);
    // };

    /**
     * Checks if the narrow character set code page is UCS-2/UTF-16,
     * according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the default narrow character set code page is UTF-16, 'false' otherwise
     * @since	1.0
     */
    inline static bool isWideCharUtf16(void)
    {
        // return (__CHAR_WIDE_TYPE == __CHAR_WIDE_TYPE_UTF16);
        return sizeof(wchar_t) == 2;
    }

    /**
     * Checks if the narrow character set code page is UCS-4/UTF-32, according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the default narrow character set code page is UTF-32, 'false' otherwise
     * @since	1.0
     */
    inline static bool isWideCharUtf32(void)
    {
        // return (__CHAR_WIDE_TYPE == __CHAR_WIDE_TYPE_UTF32);
        return sizeof(wchar_t) == 4;
    }

    /**
     * Checks if the application preferable wide character set is Unicode UCS-2/UCS-4/UTF-16/UTF-32,
     * according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the preferable character set is Unicode UTF-16/UTF-32,
     *          'false' if is ASCII, UTF-8, MBCS or otherwise
     * @since	1.0
     */
    inline static bool isApplicationApiWideUnicode(void)
    {
        // return (__CHAR_API_TYPE == __CHAR_API_TYPE_WIDE);
#if defined(_UNICODE)
        return true;
#else
        return false;
#endif
    }

    /**
     * Checks if the application preferable character set API is MBCS,
     * according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the preferable character set is MBCS,
     *          'false' if is Unicode, ASCII or otherwise
     * @since	1.0
     */
    inline static bool isApplicationApiMbcs(void)
    {
        // return (__CHAR_API_TYPE == __CHAR_API_TYPE_WIDE);
#if defined(_MBCS) && !defined(_UNICODE)
            return true;
#else
            return false;
#endif
    }

    /**
     * Checks if the application preferable narrow character set API is ASCII,
     * according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the preferable character set is ASCII,
     *          'false' if is Unicode, MBCS or otherwise
     * @since	1.0
     */
    inline static bool isApplicationApiNarrowAscii(void)
    {
        // return (__CHAR_API_TYPE == __CHAR_API_TYPE_WIDE);
#if !defined(_MBCS) && !defined(_UNICODE)
#   if defined(_WIN32)
        // Windows narrow character is ASCII, and the console doesn't support UTF-8 for compatibility with DOS
        return true;
#   else
        // Mac OS X, Linux and other UNIX and POSIX based OS are UTF-8 nowadays
        return false;
#   endif
#else
        return false;
#endif
    }

    /**
     * Checks if the application preferable narrow character set API is UTF-8,
     * according the compile time definition.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @return	'true' if the preferable character set is UTF-8,
     *          'false' if is UTF-16, UTF-32, ASCII, MBCS or otherwise
     * @since	1.0
     */
    inline static bool isApplicationApiNarrowUtf8(void)
    {
        // return (__CHAR_API_TYPE == __CHAR_API_TYPE_WIDE);
#if !defined(_MBCS) && !defined(_UNICODE)
#   if !defined(_WIN32)
        // Mac OS X, Linux and other UNIX and POSIX based OS are UTF-8 nowadays
        return true;
#   else
        // Windows narrow character is ASCII, and the console doesn't support UTF-8 for compatibility with DOS
        return false;
#   endif
#else
        return false;
#endif
    }

    /**
     * Checks if the supplied UTF-32 character is a scalar,
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a scalar,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeScalar(const char32_t charUtf32)
    {
        bool bRet = (((charUtf32 >= UNICODE_MINIMUM) && (charUtf32 < UNICODE_HIGH_SURROGATE_START)) ||
                     ((charUtf32 > UNICODE_LOW_SURROGATE_END) && (charUtf32 <= UNICODE_MAXIMUM)));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character is a sentinel (a end of string, list, etc.),
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a sentinel,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeSentinel(const char32_t charUtf32)
    {
        bool bRet = ((charUtf32 == UNICODE_MINIMUM) || (charUtf32 == 0xFFFFUL) ||
                     (charUtf32 == UNICODE_MAXIMUM));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character is a non-character (used internal for the application),
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a non-character,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeNonCharacter(const char32_t charUtf32)
    {
        // BMP U+FDD0 to U+FDEF, 0xFFFE and 0xFFFF are non-characters,
        // the last two code points of each of the 16 supplementary planes: U+1FFFE, U+1FFFF, U+2FFFE, U+2FFFF, ... U+10FFFE, U+10FFFF
        bool bRet = (((charUtf32 >= 0xFDD0UL) && (charUtf32 <= 0xFDEFUL)) ||
                     ((charUtf32 & 0xFFFEUL) == 0xFFFEUL) ||
                     ((charUtf32 & 0xFFFFUL) == 0xFFFFUL));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character from the Private Use Area (PUA), normally used by IME input systems,
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a PUA,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodePrivateUseCharacter(const char32_t charUtf32)
    {
        // BMP U+E000 to U+F8FF, U+F0000 to U+FFFFD and U+100000 to U+10FFFD are Private Use Area (PUA)
        bool bRet = (((charUtf32 >= 0xE000UL) && (charUtf32 <= 0xF8FFUL)) ||
                     ((charUtf32 >= 0xF0000UL) && (charUtf32 <= 0xFFFFDUL)) ||
                     ((charUtf32 >= 0x100000UL) && (charUtf32 <= 0x10FFFDUL)));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character is C0 control code,
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a C0 control code,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeC0ControlCharacter(const char32_t charUtf32)
    {
        bool bRet = (((charUtf32 >= UNICODE_MINIMUM) && (charUtf32 <= 0x001FUL)) ||
                     (charUtf32 >= 0x007FUL));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character is C1 control code,
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a C1 control code,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeC1ControlCharacter(const char32_t charUtf32)
    {
        bool bRet = ((charUtf32 >= 0x0080UL) && (charUtf32 <= 0x009FUL));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character is a C0 or C1 control code,
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a control code,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeControlCharacter(const char32_t charUtf32)
    {
        bool bRet = (isUnicodeC0ControlCharacter(charUtf32) || isUnicodeC1ControlCharacter(charUtf32));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 character is a interchangeable code point,
     * according to the Unicode 6.3 .
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 character to be tested
     * @return	'true' if the character is a interchangeable code point,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUnicodeInterchangeCharacter(const char32_t charUtf32)
    {
        // FIXME: Is OK to consider Unicode surrogates interchangeable?
        bool bRet = ((charUtf32 <= UNICODE_MAXIMUM) && !isUnicodeNonCharacter(charUtf32));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-8 code unit is a first in sequence surrogate.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf8	the UTF-8 code unit to be tested
     * @return	'true' if the UTF-8 code unit is a first in sequence surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf8FirstSurrogate(const char charUtf8)
    {
        unsigned char _charUtf8 = static_cast<unsigned char>(charUtf8);
        bool bRet = false;

        if((_charUtf8 >= UTF8_LEAD_BYTES2) && (_charUtf8 < UTF8_LEAD_BYTES3))
        {
            bRet = true;
        }
        else if((_charUtf8 >= UTF8_LEAD_BYTES3) && (_charUtf8 < UTF8_LEAD_BYTES4))
        {
            bRet = true;
        }
        else if((_charUtf8 >= UTF8_LEAD_BYTES4) && (_charUtf8 < UTF8_LEAD_BYTES5))
        {
            bRet = true;
        }
        else if((_charUtf8 >= UTF8_LEAD_BYTES5) && (_charUtf8 < UTF8_LEAD_BYTES6))
        {
            bRet = true;
        }
        else if((_charUtf8 == UTF8_LEAD_BYTES6))
        {
            bRet = true;
        }

        return bRet;
    }

    /**
     * Checks if the supplied UTF-8 code unit is a next in sequence surrogate.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf8	the UTF-8 code unit to be tested
     * @return	'true' if the UTF-8 code unit is a next in sequence surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf8NextSurrogate(const char charUtf8)
    {
        bool bRet = ((charUtf8 >= (char)UTF8_NEXT) && (charUtf8 <= (char)0xBFU));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-8 code unit is a surrogate.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf8	the UTF-8 code unit to be tested
     * @return	'true' if the UTF-8 code unit is a surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf8Surrogate(const char charUtf8)
    {
        unsigned char _charUtf8 = static_cast<unsigned char>(charUtf8);
        bool bRet = ((_charUtf8 & 0x80U) != 0);

        return bRet;
    }

    /**
     * Checks if the supplied UTF-16 code unit is a high surrogate.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf16	the UTF-16 code unit to be tested
     * @return	'true' if the UTF-16 code unit is a high surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf16HighSurrogate(const char16_t charUtf16)
    {
        bool bRet = ((charUtf16 >= UNICODE_HIGH_SURROGATE_START) && (charUtf16 <= UNICODE_HIGH_SURROGATE_END));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-16 code unit is a low surrogate.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf16	the UTF-16 code unit to be tested
     * @return	'true' if the UTF-16 code unit is a low surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf16LowSurrogate(const char16_t charUtf16)
    {
        bool bRet = ((charUtf16 >= UNICODE_LOW_SURROGATE_START) && (charUtf16 <= UNICODE_LOW_SURROGATE_END));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-16 code unit is a surrogate.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf16	the UTF-16 code unit to be tested
     * @return	'true' if the UTF-16 code unit is a surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf16Surrogate(const char16_t charUtf16)
    {
        bool bRet = (isUtf16HighSurrogate(charUtf16) || isUtf16LowSurrogate(charUtf16));

        return bRet;
    }

    /**
     * Checks if the supplied UTF-32 code unit is a surrogate.<br />
     * As Unicode 6.3, there aren't UTF-32 surrogates because the higher code point in use is 21-bit.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	charUtf32	the UTF-32 code unit to be tested
     * @return	'true' if the UTF-32 code unit is a surrogate,
     *          'false' if isn't
     * @since	1.0
     */
    inline static bool isUtf32Surrogate(const char32_t charUtf32)
    {
        bool bRet = false;
        // As Unicode 7.0, no UTF-32 surrogates exist
        return bRet;
    }

    /**
     * Check if the given string is a valid UTF-8 sequence.
     *
     * Valid UTF-8 code point units sequences look like this (RFC 3629):
     *      0xxxxxxx<br />
     *      110xxxxx 10xxxxxx<br />
     *      1110xxxx 10xxxxxx 10xxxxxx<br />
     *      11110xxx 10xxxxxx 10xxxxxx 10xxxxxx<br />
     * The patterns below are not part of UTF-8, but were part of the first specification:<br />
     *      111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx<br />
     *      1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx<br />
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf8String      the UTF-8 encoded character string to be tested
     * @param	utf8Lenght      the length in bytes of the UTF-8 encoded character string
     * @param	unicodeFound	optional out parameter (defaults to NULL) that if not NULL,
     *                          the value 'true' means that at least one UTF-8 surrogate has found,
     *                          and 'false' that the string only contains ANSI ASCII values
     * @return	'true' if it's a valid UTF-8 string, 'false' otherwise
     * @since	1.0
     */
    static bool isUtf8(const char* utf8String, const size_t utf8Lenght, bool* unicodeFound = nullptr);

    inline static bool isUtf8(const string& utf8String, bool* unicodeFound = nullptr)
    {
        return isUtf8((char*)utf8String.c_str(), utf8String.length(), unicodeFound);
    }

    static bool hasUtf7Bom(const string& str);

    static bool hasUtf8Bom(const string& str);

    static bool hasUtf16BeBom(const u16string& str);

    static bool hasUtf16LeBom(const u16string& str);

    inline static bool hasUtf16Bom(const u16string& str)
    {
        return hasUtf16LeBom(str) || hasUtf16BeBom(str);
    }

    static bool hasUtf32BeBom(const u32string& str);

    static bool hasUtf32LeBom(const u32string& str);

    inline static bool hasUtf32Bom(const u32string& str)
    {
        return hasUtf32LeBom(str) || hasUtf32BeBom(str);
    }

    string removeUtf8Bom(const string& str);

    /**
     * Converts an 8-bit extended ASCII character from a given code page to the equivalent UTF-32 code point,
     * based on it's' code page and if control codes less or equal to 127 are to be converted.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowChar			the ASCII character [0; 255] to be converted
     * @param	codePage			the code page from CodePage enumeration that the narrow character belongs to
     * @param	convertAsciiControl	optional parameter (defaults to 'false') that if 'true',
     *                              also converts ASCII control codes [0; 31, 127] to Unicode
     * @return	the equivalent UTF-32 code point
     * @since	1.0
     */
    static char32_t convertCharAscii_to_CharUtf32(const char narrowChar, const CodePage codePage, const bool convertAsciiControl = false);

    /**
     * Converts an 8-bit extended ASCII encoded string from a given code page to the equivalent UTF-32 encoded string,
     * based on it's code page and if control codes less or equal to 127 are to be converted.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowString		the ASCII encoded string to be converted
     * @param	codePage			the code page from CodePage enumeration that the ASCII string belongs to
     * @param	convertAsciiControl	optional parameter (defaults to 'false') that if 'true',
     *                              also converts ASCII control codes [0; 31, 127] to Unicode
     * @return	the equivalent UTF-32 encoded string
     * @since	1.0
     */
    static u32string convertStringAscii_to_StringUtf32(const string& narrowString, const CodePage codePage, const bool convertAsciiControl = false);

    /**
     * Converts a system narrow character encoded string to the equivalent system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	narrowString		the system narrow character encoded string to be converted
     * @return	the equivalent system wide character string
     * @since	1.0
     */
    static wstring convertStringNarrow_to_StringWide(const string& narrowString);

    /**
     * Converts a system wide character encoded string to the equivalent system narrow character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString		the system wide character encoded string to be converted
     * @return	the equivalent system narrow character string
     * @since	1.0
     */
    static string convertStringWide_to_StringNarrow(const wstring& wideString);

    /**
     * Converts an UTF-16 encoded string to the equivalent UTF-32 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf16String			the UTF-16 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-32 encoded string
     * @since	1.0
     */
    static u32string convertStringUtf16_to_StringUtf32(const u16string& utf16String, const bool strictConversion);

    /**
     * Converts an UTF-32 encoded string to the equivalent UTF-16 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf32String			the UTF-32 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-16 encoded string
     * @since	1.0
     */
    static u16string convertStringUtf32_to_StringUtf16(const u32string& utf32String, const bool strictConversion = false);

    /**
     * Converts an UTF-16 encoded string to the equivalent system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf16String			the UTF-16 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent wide character encoded string
     * @since	1.0
     */
    inline static wstring convertStringUtf16_to_StringWide(const u16string& utf16String, const bool strictConversion = false)
    {
        wstring strRet;

        if(isWideCharUtf16())
        {
            // wchar_t is UCS-2/UTF-16
            strRet = convertStringUtf16_to_StringWide2(utf16String, strictConversion);
        }
        else
        {
            // wchar_t is UCS-4/UTF-32
            strRet = convertStringUtf16_to_StringWide4(utf16String, strictConversion);
        }

        return strRet;
    }

    /**
     * Converts a system wide character encoded string to the equivalent UTF-16 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString			the system wide character encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-16 encoded string
     * @since	1.0
     */
    inline static u16string convertStringWide_to_StringUtf16(const wstring& wideString, const bool strictConversion = false)
    {
        u16string strRet;

        if(isWideCharUtf16())
        {
            // wchar_t is UCS-2/UTF-16
            strRet = convertStringWide2_to_StringUtf16(wideString, strictConversion);
        }
        else
        {
            // wchar_t is UCS-4/UTF-32
            strRet = convertStringWide4_to_StringUtf16(wideString, strictConversion);
        }

        return strRet;
    }

    /**
     * Converts an UTF-32 encoded string to the equivalent system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf32String			the UTF-32 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent wide character encoded string
     * @since	1.0
     */
    inline static wstring convertStringUtf32_to_StringWide(const u32string& utf32String, const bool strictConversion = false)
    {
        wstring strRet;

        if(isWideCharUtf16())
        {
            // wchar_t is UCS-2/UTF-16
            strRet = convertStringUtf32_to_StringWide2(utf32String, strictConversion);
        }
        else
        {
            // wchar_t is UCS-4/UTF-32
            strRet = convertStringUtf32_to_StringWide4(utf32String, strictConversion);
        }

        return strRet;
    }

    /**
     * Converts a system wide character encoded string to the equivalent UTF-32 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	wideString			the system wide character encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-32 encoded string
     * @since	1.0
     */
    inline static u32string convertStringWide_to_StringUtf32(const wstring& wideString, const bool strictConversion = false)
    {
        u32string strRet;

        if(isWideCharUtf16())
        {
            // wchar_t is UCS-2/UTF-16
            strRet = convertStringWide2_to_StringUtf32(wideString, strictConversion);
        }
        else
        {
            // wchar_t is UCS-4/UTF-32
            strRet = convertStringWide4_to_StringUtf32(wideString, strictConversion);
        }

        return strRet;
    }

    /**
     * Converts an UTF-16 encoded string to the equivalent UTF-8 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf16String			the UTF-16 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-8 encoded string
     * @since	1.0
     */
    static string convertStringUtf16_to_StringUtf8(const u16string& utf16String, const bool strictConversion = false);

    /**
     * Converts an UTF-8 encoded string to the equivalent UTF-16 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf8String			the UTF-8 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-16 encoded string
     * @since	1.0
     */
    static u16string convertStringUtf8_to_StringUtf16(const string& utf8String, const bool strictConversion = false);

    /**
     * Converts an UTF-32 encoded string to the equivalent UTF-8 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf32String			the UTF-32 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-8 encoded string
     * @since	1.0
     */
    static string convertStringUtf32_to_StringUtf8(const u32string& utf32String, const bool strictConversion = false);

    /**
     * Converts an UTF-8 encoded string to the equivalent UTF-32 encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf8String			the UTF-8 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent UTF-32 encoded string
     * @since	1.0
     */
    static u32string convertStringUtf8_to_StringUtf32(const string& utf8String, const bool strictConversion = false);

    inline static string convertStringWide_to_StringUtf8(const wstring& wideString, const bool strictConversion = false)
    {
        string utf8String;
        u32string utf32String;

        if(isWideCharUtf16())
        {
            // wchar_t is UCS-2/UTF-16
            utf32String = convertStringWide2_to_StringUtf32(wideString, strictConversion);
        }
        else
        {
            // wchar_t is UCS-4/UTF-32
            utf32String = convertStringWide4_to_StringUtf32(wideString, strictConversion);
        }
        utf8String = convertStringUtf32_to_StringUtf8(utf32String, strictConversion);

        return utf8String;
    }

    /**
     * Converts an UTF-8 encoded string to the equivalent system wide character encoded string.
     *
     * @author	Jos&eacute; Caetano Silva
     * @version	%I%, %G%
     * @param	utf8String			the UTF-8 encoded string to be converted
     * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
     *                              invalid conversion, if 'false' replaces invalid character width the replacement character
     * @return	the equivalent wide character encoded string
     * @since	1.0
     */
    inline static wstring convertStringUtf8_to_StringWide(const string& utf8String, const bool strictConversion = false)
    {
        wstring wideString;
        u32string utf32String = convertStringUtf8_to_StringUtf32(utf8String, strictConversion);

        if(isWideCharUtf16())
        {
            // wchar_t is UCS-2/UTF-16
            wideString = convertStringUtf32_to_StringWide2(utf32String, strictConversion);
        }
        else
        {
            // wchar_t is UCS-4/UTF-32
            wideString = convertStringUtf32_to_StringWide4(utf32String, strictConversion);
        }

        return wideString;
    }
};

#endif /* _CODEPAGE2UNICODE_H_ */
