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
 
// http://www.tutorialspoint.com/compile_cpp11_online.php

#include "StdAfx.h"

#include "CodePage2Unicode.h"

using namespace std;

/* Unicode UTF BOMs (Byte Order Markers) */

/**
 * UTF-7 BOM - (5 bytes, endianless).
 */
const char CodePage2Unicode::BOM_UTF7[5] = {
    '\x2B', '\x2F', '\x76', '\x38', '\x2D'
};

/**
 * UTF-8 BOM - (3 bytes, endianless, should not be used).
 */
const char CodePage2Unicode::BOM_UTF8[3] = {
    '\xEF', '\xBB', '\xBF'
};

/**
 * UTF-16 BOM - (2 bytes, little endian).
 */
const char16_t CodePage2Unicode::BOM_UTF16LE[1] = {
    0xFEFFU
};

/**
 * UTF-16 BOM - (2 bytes, big endian).
 */
const char16_t CodePage2Unicode::BOM_UTF16BE[1] = {
    0xFFFEU
};

/**
 * UTF-32 BOM - (4 bytes, little endian).
 */
const char32_t CodePage2Unicode::BOM_UTF32LE[1] = {
    0x0000FEFFUL
};

/**
 * UTF-32 BOM - (4 bytes, big endian).
 */
const char32_t CodePage2Unicode::BOM_UTF32BE[1] = {
    0xFFFE0000UL
};

/* Standard ASCII Code Page Maps to Unicode */

/**
 * Standard ISO/ANSI ASCII (7-bit).
 */
/*const char32_t CodePage2Unicode::m_arrASCII[128] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
    0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x007F
   };*/

/**
 * Standard ISO/ANSI ASCII MS-DOS extensions (7-bit).
 */
const char32_t CodePage2Unicode::m_arrDOS_ASCII[128] = {
    0x0000, 0x263A, 0x263B, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022, 0x25D8, 0x25CB, 0x25D9, 0x2642, 0x2640, 0x266A, 0x266B, 0x263C,
    0x25BA, 0x25C4, 0x2195, 0x203C, 0x00B6, 0x00A7, 0x25AC, 0x21A8, 0x2191, 0x2193, 0x2192, 0x2190, 0x221F, 0x2194, 0x25B2, 0x25BC,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x2302
};

/**
 * Standard ISO/ANSI ASCII Mac OS extensions (7-bit).
 */
/*const char32_t CodePage2Unicode::m_arrMac_ASCII[128] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
    0x0010, 0x2318, 0x21E7, 0x2325, 0x2388, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x007F
   };*/

/* Extended ASCII Code Page Maps to Unicode */

/**
 * Extended ASCII code page IBM 437/OEM 437: MS-DOS Latin US.
 * Suitable for writing in: English, Western Europe, etc. .
 * Script:	Latin<br />
 * IANA/MIME: IBM437, cp437, OEM-437
 * C/C++ locale options:
 * Win32 CP: 437
 */
const char32_t CodePage2Unicode::m_arrDOS_CP437[128] = {
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7, 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
    0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9, 0x00FF, 0x00D6, 0x00DC, 0x00A2, 0x00A3, 0x00A5, 0x20A7, 0x0192,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x2310, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
    0x03B1, 0x00DF, 0x0393, 0x03C0, 0x03A3, 0x03C3, 0x00B5, 0x03C4, 0x03A6, 0x0398, 0x03A9, 0x03B4, 0x221E, 0x03C6, 0x03B5, 0x2229,
    0x2261, 0x00B1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00F7, 0x2248, 0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x00A0
};

/**
 * Extended ASCII code page IBM 737/OEM 737: MS-DOS Greek.<br />
 * Suitable for writing in: Greek, English, etc. .<br />
 * Script:	Greek<br />
 * IANA/MIME: IBM737, cp737, OEM-737<br />
 * C/C++ locale options: <br />
 * Win32 CP: 737
 */
const char32_t CodePage2Unicode::m_arrDOS_CP737[128] = {
    0x0391, 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397, 0x0398, 0x0399, 0x039A, 0x039B, 0x039C, 0x039D, 0x039E, 0x039F, 0x03A0,
    0x03A1, 0x03A3, 0x03A4, 0x03A5, 0x03A6, 0x03A7, 0x03A8, 0x03A9, 0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5, 0x03B6, 0x03B7, 0x03B8,
    0x03B9, 0x03BA, 0x03BB, 0x03BC, 0x03BD, 0x03BE, 0x03BF, 0x03C0, 0x03C1, 0x03C3, 0x03C2, 0x03C4, 0x03C5, 0x03C6, 0x03C7, 0x03C8,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
    0x03C9, 0x03AC, 0x03AD, 0x03AE, 0x03CA, 0x03AF, 0x03CC, 0x03CD, 0x03CB, 0x03CE, 0x0386, 0x0388, 0x0389, 0x038A, 0x038C, 0x038E,
    0x038F, 0x00B1, 0x2265, 0x2264, 0x03AA, 0x03AB, 0x00F7, 0x2248, 0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x00A0
};

/**
 * Extended ASCII code page IBM 850/OEM 850: MS-DOS Latin-1/Multilingual.<br />
 * Suitable for writing in: Latin-1, Western Europe, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: IBM850, cp850, OEM-850<br />
 * C/C++ locale options: <br />
 * Win32 CP: 850
 */
const char32_t CodePage2Unicode::m_arrDOS_CP850[128] = {
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7, 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
    0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9, 0x00FF, 0x00D6, 0x00DC, 0x00F8, 0x00A3, 0x00D8, 0x00D7, 0x0192,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x00AE, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00C1, 0x00C2, 0x00C0, 0x00A9, 0x2563, 0x2551, 0x2557, 0x255D, 0x00A2, 0x00A5, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x00E3, 0x00C3, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x00A4,
    0x00F0, 0x00D0, 0x00CA, 0x00CB, 0x00C8, 0x0131, 0x00CD, 0x00CE, 0x00CF, 0x2518, 0x250C, 0x2588, 0x2584, 0x00A6, 0x00CC, 0x2580,
    0x00D3, 0x00DF, 0x00D4, 0x00D2, 0x00F5, 0x00D5, 0x00B5, 0x00FE, 0x00DE, 0x00DA, 0x00DB, 0x00D9, 0x00FD, 0x00DD, 0x00AF, 0x00B4,
    0x00AD, 0x00B1, 0x2017, 0x00BE, 0x00B6, 0x00A7, 0x00F7, 0x00B8, 0x00B0, 0x00A8, 0x00B7, 0x00B9, 0x00B3, 0x00B2, 0x25A0, 0x00A0
};

/**
 * Extended ASCII code page IBM 858/OEM 858: MS-DOS Latin-1/Multilingual with €.<br />
 * Suitable for writing in: Latin-1, Western Europe, €, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: IBM858, cp858, OEM-858<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 858
 */
/*const char32_t CodePage2Unicode::m_arrDOS_CP858[128]    = {
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7, 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
    0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9, 0x00FF, 0x00D6, 0x00DC, 0x00F8, 0x00A3, 0x00D8, 0x00D7, 0x0192,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x00AE, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00C1, 0x00C2, 0x00C0, 0x00A9, 0x2563, 0x2551, 0x2557, 0x255D, 0x00A2, 0x00A5, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x00E3, 0x00C3, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x00A4,
    0x00F0, 0x00D0, 0x00CA, 0x00CB, 0x00C8, 0x20AC, 0x00CD, 0x00CE, 0x00CF, 0x2518, 0x250C, 0x2588, 0x2584, 0x00A6, 0x00CC, 0x2580,
    0x00D3, 0x00DF, 0x00D4, 0x00D2, 0x00F5, 0x00D5, 0x00B5, 0x00FE, 0x00DE, 0x00DA, 0x00DB, 0x00D9, 0x00FD, 0x00DD, 0x00AF, 0x00B4,
    0x00AD, 0x00B1, 0x2017, 0x00BE, 0x00B6, 0x00A7, 0x00F7, 0x00B8, 0x00B0, 0x00A8, 0x00B7, 0x00B9, 0x00B3, 0x00B2, 0x25A0, 0x00A0
   };*/

/**
 * Extended ASCII code page IBM 859/OEM 859: MS-DOS Latin-9.<br />
 * Suitable for writing in: Latin-9, Latin-1, Western Europe, €, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: IBM859, cp859, OEM-859<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 859
 */
const char32_t CodePage2Unicode::m_arrDOS_CP859[128] = {
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7, 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
    0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9, 0x00FF, 0x00D6, 0x00DC, 0x00F8, 0x00A3, 0x00D8, 0x00D7, 0x0192,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x00AE, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00C1, 0x00C2, 0x00C0, 0x00A9, 0x2563, 0x2551, 0x2557, 0x255D, 0x00A2, 0x00A5, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x00E3, 0x00C3, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x00A4,
    0x00F0, 0x00D0, 0x00CA, 0x00CB, 0x00C8, 0x20AC, 0x00CD, 0x00CE, 0x00CF, 0x2518, 0x250C, 0x2588, 0x2584, 0x0160, 0x00CC, 0x017D,
    0x00D3, 0x00DF, 0x00D4, 0x00D2, 0x00F5, 0x00D5, 0x00B5, 0x00FE, 0x00DE, 0x00DA, 0x00DB, 0x00D9, 0x00FD, 0x00DD, 0x00AF, 0x00B4,
    0x00AD, 0x00B1, 0xFFFD, 0x0178, 0x00B6, 0x00A7, 0x00F7, 0x017E, 0x00B0, 0x0161, 0x00B7, 0x00B9, 0x00B3, 0x00B2, 0x25A0, 0x00A0
};

/**
 * Extended ASCII code page IBM 860/OEM 860: MS-DOS Portuguese.<br />
 * Suitable for writing in: Portuguese, Western Europe, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: IBM860, cp860, OEM-860<br />
 * C/C++ locale options: <br />
 * Win32 CP: 860
 */
const char32_t CodePage2Unicode::m_arrDOS_CP860[128] = {
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E3, 0x00E0, 0x00C1, 0x00E7, 0x00EA, 0x00CA, 0x00E8, 0x00CD, 0x00D4, 0x00EC, 0x00C3, 0x00C2,
    0x00C9, 0x00C0, 0x00C8, 0x00F4, 0x00F5, 0x00F2, 0x00DA, 0x00F9, 0x00CC, 0x00D5, 0x00DC, 0x00A2, 0x00A3, 0x00D9, 0x20A7, 0x00D3,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x00D2, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
    0x03B1, 0x00DF, 0x0393, 0x03C0, 0x03A3, 0x03C3, 0x00B5, 0x03C4, 0x03A6, 0x0398, 0x03A9, 0x03B4, 0x221E, 0x03C6, 0x03B5, 0x2229,
    0x2261, 0x00B1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00F7, 0x2248, 0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x00A0
};

/**
 * Extended ASCII code page Apple Macintosh/Mac OS Roman: Mac OS Latin-1/Roman.<br />
 * Suitable for writing in: Latin-1, Western Europe, €, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: macintosh, mac, MacRoman<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 10000
 */
const char32_t CodePage2Unicode::m_arrMac_Roman[128] = {
    0x00C4, 0x00C5, 0x00C7, 0x00C9, 0x00D1, 0x00D6, 0x00DC, 0x00E1, 0x00E0, 0x00E2, 0x00E4, 0x00E3, 0x00E5, 0x00E7, 0x00E9, 0x00E8,
    0x00EA, 0x00EB, 0x00ED, 0x00EC, 0x00EE, 0x00EF, 0x00F1, 0x00F3, 0x00F2, 0x00F4, 0x00F6, 0x00F5, 0x00FA, 0x00F9, 0x00FB, 0x00FC,
    0x2020, 0x00B0, 0x00A2, 0x00A3, 0x00A7, 0x2022, 0x00B6, 0x00DF, 0x00AE, 0x00A9, 0x2122, 0x00B4, 0x00A8, 0x2260, 0x00C6, 0x00D8,
    0x221E, 0x00B1, 0x2264, 0x2265, 0x00A5, 0x00B5, 0x2202, 0x2211, 0x220F, 0x03C0, 0x222B, 0x00AA, 0x00BA, 0x03A9, 0x00E6, 0x00F8,
    0x00BF, 0x00A1, 0x00AC, 0x221A, 0x0192, 0x2248, 0x2206, 0x00AB, 0x00BB, 0x2026, 0x00A0, 0x00C0, 0x00C3, 0x00D5, 0x0152, 0x0153,
    0x2013, 0x2014, 0x201C, 0x201D, 0x2018, 0x2019, 0x00F7, 0x25CA, 0x00FF, 0x0178, 0x2044, 0x20AC, 0x2039, 0x203A, 0xFB01, 0xFB02,
    0x2021, 0x00B7, 0x201A, 0x201E, 0x2030, 0x00C2, 0x00CA, 0x00C1, 0x00CB, 0x00C8, 0x00CD, 0x00CE, 0x00CF, 0x00CC, 0x00D3, 0x00D4,
    0xF8FF, 0x00D2, 0x00DA, 0x00DB, 0x00D9, 0x0131, 0x02C6, 0x02DC, 0x00AF, 0x02D8, 0x02D9, 0x02DA, 0x00B8, 0x02DD, 0x02DB, 0x02C7
};

/**
 * Extended ASCII code page Apple Macintosh/Mac OS Greek: Mac OS Greek.<br />
 * Suitable for writing in: Greek, English, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: x-mac-greek, MacGreek<br />
 * C/C++ locale options: <br />
 * Win32 CP: 10006
 */
const char32_t CodePage2Unicode::m_arrMac_Greek[128] = {
    0x00C4, 0x00B9, 0x00B2, 0x00C9, 0x00B3, 0x00D6, 0x00DC, 0x0385, 0x00E0, 0x00E2, 0x00E4, 0x0384, 0x00A8, 0x00E7, 0x00E9, 0x00E8,
    0x00EA, 0x00EB, 0x00A3, 0x2122, 0x00EE, 0x00EF, 0x2022, 0x00BD, 0x2030, 0x00F4, 0x00F6, 0x00A6, 0x20AC, 0x00F9, 0x00FB, 0x00FC,
    0x2020, 0x0393, 0x0394, 0x0398, 0x039B, 0x039E, 0x03A0, 0x00DF, 0x00AE, 0x00A9, 0x03A3, 0x03AA, 0x00A7, 0x2260, 0x00B0, 0x00B7,
    0x0391, 0x00B1, 0x2264, 0x2265, 0x00A5, 0x0392, 0x0395, 0x0396, 0x0397, 0x0399, 0x039A, 0x039C, 0x03A6, 0x03AB, 0x03A8, 0x03A9,
    0x03AC, 0x039D, 0x00AC, 0x039F, 0x03A1, 0x2248, 0x03A4, 0x00AB, 0x00BB, 0x2026, 0x00A0, 0x03A5, 0x03A7, 0x0386, 0x0388, 0x0153,
    0x2013, 0x2015, 0x201C, 0x201D, 0x2018, 0x2019, 0x00F7, 0x0389, 0x038A, 0x038C, 0x038E, 0x03AD, 0x03AE, 0x03AF, 0x03CC, 0x038F,
    0x03CD, 0x03B1, 0x03B2, 0x03C8, 0x03B4, 0x03B5, 0x03C6, 0x03B3, 0x03B7, 0x03B9, 0x03BE, 0x03BA, 0x03BB, 0x03BC, 0x03BD, 0x03BF,
    0x03C0, 0x03CE, 0x03C1, 0x03C3, 0x03C4, 0x03B8, 0x03C9, 0x03C2, 0x03C7, 0x03C5, 0x03B6, 0x03CA, 0x03CB, 0x0390, 0x03B0, 0x00AD
};

/**
 * Extended ASCII code page Microsoft Windows 1252: Windows Latin-1/Western Europe.<br />
 * Suitable for writing in: Latin-1, Western Europe, €, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: windows-1252, cp1252<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 1252
 */
const char32_t CodePage2Unicode::m_arrWindows_1252[128] = {
    0x20AC, 0xFFFD, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021, 0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0xFFFD, 0xFFFD, 0x017D,
    0xFFFD, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 0xFFFD, 0x2122, 0x0161, 0x203A, 0x0153, 0xFFFD, 0x017E, 0x0178,
    0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
    0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
    0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
    0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
    0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
    0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF
};

/**
 * Extended ASCII code page Microsoft Windows 1253: Windows Greek.<br />
 * Suitable for writing in: Greek, English, €, etc. .<br />
 * Script:	Greek<br />
 * IANA/MIME: windows-1253, cp1253<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 1253
 */
const char32_t CodePage2Unicode::m_arrWindows_1253[128] = {
    0x20AC, 0xFFFD, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021, 0xFFFD, 0x2030, 0xFFFD, 0x2039, 0xFFFD, 0xFFFD, 0xFFFD, 0xFFFD,
    0xFFFD, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014, 0xFFFD, 0x2122, 0xFFFD, 0x203A, 0xFFFD, 0xFFFD, 0xFFFD, 0xFFFD,
    0x00A0, 0x0385, 0x0386, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0xFFFD, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x2015,
    0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x0384, 0x00B5, 0x00B6, 0x00B7, 0x0388, 0x0389, 0x038A, 0x00BB, 0x038C, 0x00BD, 0x038E, 0x038F,
    0x0390, 0x0391, 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397, 0x0398, 0x0399, 0x039A, 0x039B, 0x039C, 0x039D, 0x039E, 0x039F,
    0x03A0, 0x03A1, 0xFFFD, 0x03A3, 0x03A4, 0x03A5, 0x03A6, 0x03A7, 0x03A8, 0x03A9, 0x03AA, 0x03AB, 0x03AC, 0x03AD, 0x03AE, 0x03AF,
    0x03B0, 0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5, 0x03B6, 0x03B7, 0x03B8, 0x03B9, 0x03BA, 0x03BB, 0x03BC, 0x03BD, 0x03BE, 0x03BF,
    0x03C0, 0x03C1, 0x03C2, 0x03C3, 0x03C4, 0x03C5, 0x03C6, 0x03C7, 0x03C8, 0x03C9, 0x03CA, 0x03CB, 0x03CC, 0x03CD, 0x03CE, 0xFFFD
};

/**
 * Extended ASCII code page ISO/IEC 8859-1: ISO/IEC Latin-1.<br />
 * Suitable for writing in: Latin-1, Western Europe, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: ISO-8859-1, iso8859-1<br />
 * C/C++ locale options: <br />
 * Win32 CP: 28591
 */
/*const char32_t CodePage2Unicode::m_arrISO_8859_1[128] = {
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
    0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
    0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
    0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
    0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
    0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
    0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF
   };*/

/**
 * Extended ASCII code page ISO/IEC 8859-7: ISO/IEC Greek.<br />
 * Suitable for writing in: Greek, English, €, etc. .<br />
 * Script:	Greek<br />
 * IANA/MIME: ISO-8859-7, iso8859-7<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 28597
 */
const char32_t CodePage2Unicode::m_arrISO_8859_7[128] = {
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
    0x00A0, 0x2018, 0x2019, 0x00A3, 0x20AC, 0x20AF, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x037A, 0x00AB, 0x00AC, 0x00AD, 0xFFFD, 0x2015,
    0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x0384, 0x0385, 0x0386, 0x00B7, 0x0388, 0x0389, 0x038A, 0x00BB, 0x038C, 0x00BD, 0x038E, 0x038F,
    0x0390, 0x0391, 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397, 0x0398, 0x0399, 0x039A, 0x039B, 0x039C, 0x039D, 0x039E, 0x039F,
    0x03A0, 0x03A1, 0xFFFD, 0x03A3, 0x03A4, 0x03A5, 0x03A6, 0x03A7, 0x03A8, 0x03A9, 0x03AA, 0x03AB, 0x03AC, 0x03AD, 0x03AE, 0x03AF,
    0x03B0, 0x03B1, 0x03B2, 0x03B3, 0x03B4, 0x03B5, 0x03B6, 0x03B7, 0x03B8, 0x03B9, 0x03BA, 0x03BB, 0x03BC, 0x03BD, 0x03BE, 0x03BF,
    0x03C0, 0x03C1, 0x03C2, 0x03C3, 0x03C4, 0x03C5, 0x03C6, 0x03C7, 0x03C8, 0x03C9, 0x03CA, 0x03CB, 0x03CC, 0x03CD, 0x03CE, 0xFFFD
};

/**
 * Extended ASCII code page ISO/IEC 8859-15: ISO/IEC Latin-9.<br />
 * Suitable for writing in: Latin-9, Latin-1, Western Europe, €, etc. .<br />
 * Script:	Latin<br />
 * IANA/MIME: ISO-8859-15, iso8859-15<br />
 * C/C++ locale options: @euro<br />
 * Win32 CP: 28605
 */
/*const char32_t CodePage2Unicode::m_arrISO_8859_15[128] = {
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
    0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
    0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x20AC, 0x00A5, 0x0160, 0x00A7, 0x0161, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
    0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x017D, 0x00B5, 0x00B6, 0x00B7, 0x017E, 0x00B9, 0x00BA, 0x00BB, 0x0152, 0x0153, 0x0178, 0x00BF,
    0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
    0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
    0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
    0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF
   };*/

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
bool CodePage2Unicode::isUtf8(const char* utf8String, const size_t utf8Lenght, bool* unicodeFound)
{
    // Validate parameters
    assert(utf8String != nullptr);

    size_t i = 0;
    size_t sequenceBytes = 0;

    if(unicodeFound != nullptr)
    {
        *unicodeFound = false;
    }

    // Check first byte
    while(i < utf8Lenght)
    {
        unsigned char charUtf8 = static_cast<unsigned char>(utf8String[i]);

        if(charUtf8 <= 0x7FU)
        {
            // 7-bit Unicode code point (7-bit ASCII [U+00000000; U+0000007F]) => 1 byte
            sequenceBytes = 0;
        }
        else if((charUtf8 >= 0xC0U) && (charUtf8 <= 0xDFU))
        {
            // 11-bit Unicode code point ([U+00000080; U+000007FF]) => 2 bytes
            // Sequence 11000000 to 11011111
            sequenceBytes = 1;
            if(unicodeFound != nullptr)
            {
                *unicodeFound = true;
            }
        }
        else if((charUtf8 >= 0xE0U) && (charUtf8 <= 0xEFU))
        {
            // 16-bit Unicode code point ([U+00000800; U+00000FFFF]) => 3 bytes
            // Sequence 11100000 to 11101111
            sequenceBytes = 2;
            if(unicodeFound != nullptr)
            {
                *unicodeFound = true;
            }
        }
        else if((charUtf8 >= 0xF0U) && (charUtf8 <= 0xF7U))
        {
            // 21-bit Unicode code point ([U+00010000; U+0001FFFFF]) => 3 bytes
            // Sequence 11110000 to 11110111
            sequenceBytes = 3;
            if(unicodeFound != nullptr)
            {
                *unicodeFound = true;
            }
        }
        else if((charUtf8 >= 0xF8U) && (charUtf8 <= 0xFBU))
        {
            // 26-bit Unicode code point ([U+00010000; U+0001FFFFF]) => 4 bytes
            // Sequence 11111000 to 11111011
            sequenceBytes = 4;
            if(unicodeFound != nullptr)
            {
                *unicodeFound = true;
            }
        }
        else if((charUtf8 >= 0xFCU) && (charUtf8 <= 0xFDU))
        {
            // 26-bit Unicode code point ([U+200000; U+3FFFFFF]) => 5 bytes
            // Sequence 11111100 to 11111101
            sequenceBytes = 5;
            if(unicodeFound != nullptr)
            {
                *unicodeFound = true;
            }

            // Invalid sequence
            return false;
        }
        else if((charUtf8 >= 0xFEU) && (charUtf8 <= 0xFDU))
        {
            // 26-bit Unicode code point ([U+4000000; U+7FFFFFFF]) => 6 bytes
            // Sequence 11111110 to 11111111
            sequenceBytes = 6;
            if(unicodeFound != nullptr)
            {
                *unicodeFound = true;
            }

            // Invalid sequence
            return false;
        }
        else
        {
            // Invalid sequence
            return false;
        }

        // Next byte
        ++i;

        // Check if the surrogate is valid
        while((i < utf8Lenght) && (sequenceBytes > 0) &&
              (charUtf8 >= 0x80U) && (charUtf8 <= 0xFFU))
        {
            ++i;
            --sequenceBytes;
        }

        // Invalid sequence
        if(sequenceBytes != 0)
        {
            return false;
        }
    }

    return true;
}

bool CodePage2Unicode::hasUtf7Bom(const string& str)
{
    // Validate parameters
    assert(&str != nullptr);

    bool bRet = true;

    size_t iLen = (sizeof(BOM_UTF7) / sizeof(BOM_UTF7[0]));
    if(str.length() >= iLen)
    {
        for(size_t i = 0; i < iLen; ++i)
        {
            if(str.at(i) != BOM_UTF8[i])
            {
                return false;
            }
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool CodePage2Unicode::hasUtf8Bom(const string& str)
{
    // Validate parameters
    assert(&str != nullptr);

    bool bRet = true;

    size_t iLen = (sizeof(BOM_UTF8) / sizeof(BOM_UTF8[0]));
    if(str.length() >= iLen)
    {
        for(size_t i = 0; i < iLen; ++i)
        {
            if(str.at(i) != BOM_UTF8[i])
            {
                return false;
            }
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool CodePage2Unicode::hasUtf16BeBom(const u16string& str)
{
    // Validate parameters
    assert(&str != nullptr);

    bool bRet = true;

    size_t iLen = (sizeof(BOM_UTF16BE) / sizeof(BOM_UTF16BE[0]));
    if(str.length() >= iLen)
    {
        for(size_t i = 0; i < iLen; ++i)
        {
            if(str[i] != BOM_UTF16BE[i])
            {
                return false;
            }
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool CodePage2Unicode::hasUtf16LeBom(const u16string& str)
{
    // Validate parameters
    assert(&str != nullptr);

    bool bRet = true;

    size_t iLen = (sizeof(BOM_UTF16LE) / sizeof(BOM_UTF16LE[0]));
    if(str.length() >= iLen)
    {
        for(size_t i = 0; i < iLen; ++i)
        {
            if(str[i] != BOM_UTF16LE[i])
            {
                return false;
            }
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool CodePage2Unicode::hasUtf32BeBom(const u32string& str)
{
    assert(&str != nullptr);

    bool bRet = true;

    size_t iLen = (sizeof(BOM_UTF32BE) / sizeof(BOM_UTF32BE[0]));
    if(str.length() >= iLen)
    {
        for(size_t i = 0; i < iLen; ++i)
        {
            if(str[i] != BOM_UTF32BE[i])
            {
                return false;
            }
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

bool CodePage2Unicode::hasUtf32LeBom(const u32string& str)
{
    assert(&str != nullptr);

    bool bRet = true;

    size_t iLen = (sizeof(BOM_UTF32LE) / sizeof(BOM_UTF32LE[0]));
    if(str.length() >= iLen)
    {
        for(size_t i = 0; i < iLen; ++i)
        {
            if(str[i] != BOM_UTF32LE[i])
            {
                return false;
            }
        }
    }
    else
    {
        bRet = false;
    }

    return bRet;
}

string CodePage2Unicode::removeUtf8Bom(const string& str)
{
    string strRer;

    if(isUtf8(str) && hasUtf8Bom(str))
    {
        size_t iLen = (sizeof(BOM_UTF8) / sizeof(BOM_UTF8[0]));
        strRer = str.substr(iLen);
    }
    else
    {
        strRer = str;
    }

    return strRer;
}


CodePage CodePage2Unicode::getDefaultNarrowCodePage(void)
{
	CodePage retCP = CodePage::UNKNOWN;
	string strLocale(locale().name());
	if(strLocale.compare("") != 0)
	{
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
		// Windows-1252, the default for latin based Windows OS
#	if !defined(_CONSOLE)
		retCP = static_cast<CodePage>(::GetOEMCP());
#	else
		retCP = static_cast<CodePage>(::GetACP());
#	endif
#else
		// UTF-8
		retCP = CodePage::UTF_8;
#endif
	}
	else if((strLocale.compare("C") != 0) || (strLocale.compare("POSIX") != 0))
	{
		// US-ASCII
		retCP = CodePage::US_ASCII;
	}
	else if((strLocale.find(".ISO-8859-15") != string::npos) || (strLocale.find(".28605") != string::npos))
	{
		// ISO-8859-15: ISO Latin 9; Western European + Finnish + French + € (same as ISO-8859-1, but with 8 replaced characters like the € insted of ¤)
		retCP = CodePage::ISO_8859_15;
	}
	else if((strLocale.find(".ISO-8859-7") != string::npos) || (strLocale.find(".28597") != string::npos))
	{
		// ISO-8859-7: ISO Greek; Greek + €
		retCP = CodePage::ISO_8859_7;
	}
	else if((strLocale.find(".ISO-8859-1") != string::npos) || (strLocale.find(".28591") != string::npos))
	{
		// ISO-8859-1: ISO Latin 1; ANSI Western European
		retCP = CodePage::ISO_8859_1;
	}
	else if((strLocale.find(".x-mac-roman") != string::npos) || (strLocale.find(".MacRoman") != string::npos) || (strLocale.find(".Macintosh") != string::npos) || (strLocale.find(".10000") != string::npos))
	{
		// MacRoman: Macintosh Latin 1; Mac Western European
		retCP = CodePage::MAC_ROMAN;
	}
	else if((strLocale.find(".x-mac-greek") != string::npos) || (strLocale.find(".MacGreek") != string::npos) || (strLocale.find(".10006") != string::npos))
	{
		// MacRoman: Macintosh Latin 1; Mac Western European
		retCP = CodePage::MAC_GREEK;
	}
	else if((strLocale.find(".Windows-1252") != string::npos) || (strLocale.find(".CP1252") != string::npos) || (strLocale.find(".1252") != string::npos))
	{
		// Windows-1252: ANSI Latin 1 + €; Windows Western European (same as ISO-8859-1, but with more printing characters insted of control codes defined like the €)
		retCP = CodePage::WINDOWS_1252;
	}
	else if((strLocale.find(".Windows-1253") != string::npos) || (strLocale.find(".CP1253") != string::npos) || (strLocale.find(".1253") != string::npos))
	{
		// Windows-1253: Greek + €
		retCP = CodePage::WINDOWS_1252;
	}
	else if((strLocale.find(".US-ASCII") != string::npos) || (strLocale.find(".CP367") != string::npos) || (strLocale.find(".20127") != string::npos))
	{
		// IBM437: OEM USA; DOS USA
		retCP = CodePage::US_ASCII;
	}
	else if((strLocale.find(".CP437") != string::npos) || (strLocale.find(".437") != string::npos))
	{
		// IBM437: OEM USA; DOS USA
		retCP = CodePage::DOS_CP437;
	}
	else if((strLocale.find(".CP737") != string::npos) || (strLocale.find(".737") != string::npos))
	{
		// IBM737: OEM Greek; DOS Greek
		retCP = CodePage::DOS_CP737;
	}
	else if((strLocale.find(".CP850") != string::npos) || (strLocale.find(".850") != string::npos))
	{
		// IBM850: OEM Multilingual Latin 1; DOS Western European
		retCP = CodePage::DOS_CP850;
	}
	else if((strLocale.find(".CP851") != string::npos) || (strLocale.find(".851") != string::npos))
	{
		// IBM851: OEM Greek 1; DOS Greek 1
		retCP = CodePage::DOS_CP851;
	}
	else if((strLocale.find(".CP858") != string::npos) || (strLocale.find(".858") != string::npos))
	{
		// IBM858: OEM Multilingual Latin 1  + €; DOS Western European + € (same as IBM850, but with € insted of ı)
		retCP = CodePage::DOS_CP858;
	}
	else if((strLocale.find(".CP859") != string::npos) || (strLocale.find(".859") != string::npos))
	{
		// IBM859: OEM Latin 9  + €; DOS Western European + Finnish + French + €
		retCP = CodePage::DOS_CP859;
	}
	else if((strLocale.find(".CP860") != string::npos) || (strLocale.find(".860") != string::npos))
	{
		// IBM860: OEM Portuguese; DOS Portuguese
		retCP = CodePage::DOS_CP860;
	}
	else if((strLocale.find(".CP869") != string::npos) || (strLocale.find(".869") != string::npos))
	{
		// IBM869: OEM Greek 2; DOS Greek 2
		retCP = CodePage::DOS_CP869;
	}
	else if((strLocale.find(".UTF-8") != string::npos) || (strLocale.find(".utf8") != string::npos) || (strLocale.find(".65001") != string::npos))
	{
		// UTF-8
		retCP = CodePage::UTF_8;
	}
	
	return retCP;
}

/**
 * Converts a 8-bit extended ASCII character from a given code page to the equivalent UTF-32 code point,
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
char32_t CodePage2Unicode::convertCharAscii_to_CharUtf32(const char narrowChar, const CodePage codePage, const bool convertAsciiControl)
{
    char32_t code = static_cast<char32_t>(static_cast<unsigned char>(narrowChar));

    // Validate parameters
#if defined(_DEBUG)
    assert((code >= 0) && (code <= 255));
#endif

    // Standard ISO/ANSI ASCII
    if(code <= 127)
    {
        if(convertAsciiControl)
        {
            if((codePage == CodePage::DOS_CP437) ||
               (codePage == CodePage::DOS_CP737) ||
               (codePage == CodePage::DOS_CP850) ||
               (codePage == CodePage::DOS_CP858) ||
               (codePage == CodePage::DOS_CP859) ||
               (codePage == CodePage::DOS_CP860))
            {
                // MS-DOS extensions
                return convertDOS_ASCII_To_Unicode((char)code);
            }
            else if((codePage == CodePage::MAC_ROMAN) ||
                    (codePage == CodePage::MAC_GREEK))
            {
                // MacOS extensions
                return convertMac_ASCII_To_Unicode((char)code);
            }
        }
        // else
        return convertASCII_To_Unicode((char)code);
    }
    // else
    // Extended ASCII
    switch(codePage)
    {
		// US_ASCII, IBM367, cp367, 367 - Code page IBM 367, MS-DOS US-ASCII
        case CodePage::US_ASCII:
            return convertDOS_CP367_To_Unicode((char)code);
            break;

        // IBM437, cp437, 437 - Code page IBM 437, MS-DOS Latin US (English, Western Europe)
        case CodePage::DOS_CP437:
            return convertDOS_CP437_To_Unicode((char)code);
            break;

        // IBM737, cp737, 737 - Code page IBM 737, MS-DOS Greek (Greek, English)
        case CodePage::DOS_CP737:
            return convertDOS_CP737_To_Unicode((char)code);
            break;

        // IBM850, cp850, 850 - Code page IBM 850, MS-DOS Latin-1/Multilingual (Latin-1, Western Europe)
        case CodePage::DOS_CP850:
            return convertDOS_CP850_To_Unicode((char)code);
            break;

        // IBM858, cp858@euro, 858 - Code page IBM 858, MS-DOS Latin-1/Multilingual with € (Latin-1, Western Europe, €)
        case CodePage::DOS_CP858:
            return convertDOS_CP858_To_Unicode((char)code);
            break;

        // IBM859, cp859@euro, 859 - Code page IBM 859, MS-DOS Latin-9 (Latin-9, Latin-1, Western Europe, €)
        case CodePage::DOS_CP859:
            return convertDOS_CP859_To_Unicode((char)code);
            break;

        // IBM860, cp860, 860 - Code page IBM 860, MS-DOS Portuguese (Portuguese, Western Europe)
        case CodePage::DOS_CP860:
            return convertDOS_CP860_To_Unicode((char)code);
            break;

        // macintosh@euro, mac, MacRoman, 10000 - Code page Apple Macintosh, Mac OS Latin-1/Roman (Latin-1, Western Europe, €)
        case CodePage::MAC_ROMAN:
            return convertMac_Roman_To_Unicode((char)code);
            break;

        // x-mac-greek, MacGreek, 10006 - Code page Apple Macintosh, Mac OS Greek (Greek, English)
        case CodePage::MAC_GREEK:
            return convertMac_Greek_To_Unicode((char)code);
            break;

        // windows-1252@euro, 1252 - Code page Microsoft Windows 1252, Windows Latin-1/Western Europe (Latin-1, Western Europe, €)
        case CodePage::WINDOWS_1252:
            return convertWindows_1252_To_Unicode((char)code);
            break;

        // windows-1253@euro, 1253 - Code page Microsoft Windows 1253, Windows Greek (Greek, English, €)
        case CodePage::WINDOWS_1253:
            return convertWindows_1253_To_Unicode((char)code);
            break;

        // ISO-8859-1, 28591 - Code page ISO 8859-1, ISO/IEC Latin-1 (Latin-1, Western Europe)
        case CodePage::ISO_8859_1:
            return convertISO_8859_1_To_Unicode((char)code);
            break;

        // ISO-8859-7@euro, 28597 - Code page ISO 8859-7, ISO/IEC Greek (Greek, English, €)
        case CodePage::ISO_8859_7:
            return convertISO_8859_7_To_Unicode((char)code);
            break;

        // ISO-8859-15@euro, 28605 - Code page ISO 8859-15, ISO/IEC Latin-9 (Latin-9, Latin-1, Western Europe, €)
        case CodePage::ISO_8859_15:
            return convertISO_8859_15_To_Unicode((char)code);
            break;
    }

    return (char32_t)(L'\0');
}

/**
 * Converts a 8-bit extended ASCII encoded string from a given code page to the equivalent UTF-32 encoded string,
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
u32string CodePage2Unicode::convertStringAscii_to_StringUtf32(const string& narrowString, const CodePage codePage, const bool convertAsciiControl)
{
    u32string strRet;

    char32_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < narrowString.length(); i++)
    {
        codeUnits[0] = convertCharAscii_to_CharUtf32(narrowString.at(i), codePage, convertAsciiControl);

        strRet.append(codeUnits);
    }

    return strRet;
}

/**
 * Converts an UTF-16 encoded string to the equivalent 2 bytes system wide character encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	utf16String			the UTF-16 encoded string to be converted
 * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
 *                          invalid conversion, if 'false' replaces invalid character width the replacement character
 * @return	the equivalent 2 bytes system wide character encoded string
 * @since	1.0
 */
wstring CodePage2Unicode::convertStringUtf16_to_StringWide2(const u16string& utf16String, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 16-bit
        assert(isWideCharUtf16());
#endif

    wstring strRet;
    wchar_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < utf16String.length(); i++)
    {
        codeUnits[0] = static_cast<wchar_t>(utf16String.at(i));
        strRet.append(codeUnits);
    }

    return strRet;
}

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
u16string CodePage2Unicode::convertStringWide2_to_StringUtf16(const wstring& wideString, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 16-bit
        assert(isWideCharUtf16());
#endif

    u16string strRet;
    char16_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < wideString.length(); i++)
    {
        codeUnits[0] = static_cast<char16_t>(wideString.at(i));
        strRet.append(codeUnits);
    }

    return strRet;
}

/**
 * Converts an UTF-16 encoded string to the equivalent 4 bytes system wide character encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	utf16String			the UTF-16 encoded string to be converted
 * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
 *                          invalid conversion, if 'false' replaces invalid character width the replacement character
 * @return	the equivalent 4 bytes system wide character encoded string
 * @since	1.0
 */
wstring CodePage2Unicode::convertStringUtf16_to_StringWide4(const u16string& utf16String, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 32-bit
        assert(isWideCharUtf32());
#endif

    wstring strRet;
    u32string strRetT = convertStringUtf16_to_StringUtf32(utf16String, strictConversion);
    wchar_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < strRetT.length(); i++)
    {
        codeUnits[0] = static_cast<wchar_t>(strRetT.at(i));
        strRet.append(codeUnits);
    }

    return strRet;
}

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
u16string CodePage2Unicode::convertStringWide4_to_StringUtf16(const wstring& wideString, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 32-bit
        assert(isWideCharUtf32());
#endif

    u32string strRetT = convertStringWide4_to_StringUtf32(wideString, strictConversion);
    u16string strRet = convertStringUtf32_to_StringUtf16(strRetT, strictConversion);

    return strRet;
}

/**
 * Converts an UTF-32 encoded string to the equivalent 2 bytes system wide character encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	utf32String			the UTF-32 encoded string to be converted
 * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
 *                          invalid conversion, if 'false' replaces invalid character width the replacement character
 * @return	the equivalent 2 bytes system wide character encoded string
 * @since	1.0
 */
wstring CodePage2Unicode::convertStringUtf32_to_StringWide2(const u32string& utf32String, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 16-bit
        assert(isWideCharUtf16());
#endif

    wstring strRet;
    u16string strRetT = convertStringUtf32_to_StringUtf16(utf32String, strictConversion);
    wchar_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < strRetT.length(); i++)
    {
        codeUnits[0] = static_cast<wchar_t>(strRetT.at(i));
        strRet.append(codeUnits);
    }

    return strRet;
}

/**
 * Converts an 2 bytes system wide character encoded string to the equivalent  encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	wideString			the 2 bytes system wide character encoded string to be converted
 * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
 *                              invalid conversion, if 'false' replaces invalid character width the replacement character
 * @return	the equivalent UTF-32 string
 * @since	1.0
 */
u32string CodePage2Unicode::convertStringWide2_to_StringUtf32(const wstring& wideString, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 16-bit
        assert(isWideCharUtf16());
#endif

    u16string strRetT = convertStringWide2_to_StringUtf16(wideString, strictConversion);
    u32string strRet = convertStringUtf16_to_StringUtf32(strRetT, strictConversion);

    return strRet;
}

/**
 * Converts an UTF-32 encoded string to the equivalent 4 bytes system wide character encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	utf32String			the UTF-32 encoded string to be converted
 * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
 *                          invalid conversion, if 'false' replaces invalid character width the replacement character
 * @return	the equivalent 4 bytes system wide character encoded string
 * @since	1.0
 */
wstring CodePage2Unicode::convertStringUtf32_to_StringWide4(const u32string& utf32String, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 32-bit
        assert(isWideCharUtf32());
#endif

    wstring strRet;
    wchar_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < utf32String.length(); i++)
    {
        codeUnits[0] = static_cast<wchar_t>(utf32String.at(i));
        strRet.append(codeUnits);
    }

    return strRet;
}

/**
 * Converts an 4 bytes system wide character encoded string to the equivalent  encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	wideString			the 4 bytes system wide character encoded string to be converted
 * @param	strictConversion	optional parameter (default is 'false'), if 'true' throws exceptions in case of
 *                              invalid conversion, if 'false' replaces invalid character width the replacement character
 * @return	the equivalent UTF-32 string
 * @since	1.0
 */
u32string CodePage2Unicode::convertStringWide4_to_StringUtf32(const wstring& wideString, const bool strictConversion)
{
#if defined(_DEBUG)
        // wchar_t must be 32-bit
        assert(isWideCharUtf32());
#endif

    u32string strRet;
    char32_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < wideString.length(); i++)
    {
        codeUnits[0] = static_cast<char32_t>(wideString.at(i));
        strRet.append(codeUnits);
    }

    return strRet;
}

/**
 * Converts an system narrow character encoded string to the equivalent system wide character encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	narrowString		the system narrow character encoded string to be converted
 * @return	the equivalent system wide character string
 * @since	1.0
 */
wstring CodePage2Unicode::convertStringNarrow_to_StringWide(const string& narrowString)
{
    wstring wideString;
    size_t requiredSize = 0;
    wchar_t* cstrUnicode = nullptr;
    size_t nRet = 0;

#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
        // Microsoft Windows
        requiredSize = (size_t)::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, narrowString.c_str(), -1, nullptr, 0);
#else
        // ANSI C/C++
        requiredSize = ::mbstowcs(nullptr, narrowString.c_str(), 0);
#endif

    if(requiredSize > 0)
    {
        cstrUnicode = (wchar_t*)::malloc((requiredSize + 1) * sizeof(wchar_t));
        if(cstrUnicode != nullptr)
        {
            cstrUnicode[requiredSize] = L'\0';
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
                // Microsoft Windows
                nRet = (size_t)::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, narrowString.c_str(), -1, cstrUnicode, (int)requiredSize);
#else
                // ANSI C/C++
                nRet = ::mbstowcs(cstrUnicode, narrowString.c_str(), requiredSize);
#endif

            if((nRet == 0) || (nRet == static_cast<size_t>(-1)) || (nRet > requiredSize))
            {
                // Error converting string
                ::free((void*)cstrUnicode);
                cstrUnicode = nullptr;
            }
        }
        else
        {
            // Error allocating memory
            cstrUnicode = nullptr;
        }
    }
    else
    {
        // Error, can't convert
        cstrUnicode = nullptr;
    }

    if(cstrUnicode == nullptr)
    {
        throw logic_error("Can't convert narrow string to wide string");
    }
    else
    {
        wideString = wstring(cstrUnicode);
        ::free(cstrUnicode);
        cstrUnicode = nullptr;
    }

    return wideString;
}

/**
 * Converts an system wide character encoded string to the equivalent system narrow character encoded string.
 *
 * @author	Jos&eacute; Caetano Silva
 * @version	%I%, %G%
 * @param	wideString		the system wide character encoded string to be converted
 * @return	the equivalent system narrow character string
 * @since	1.0
 */
string CodePage2Unicode::convertStringWide_to_StringNarrow(const wstring& wideString)
{
    string narrowString;
    size_t requiredSize = 0;
    char* cstrASCII = nullptr;
    size_t nRet = 0;

#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
        // Microsoft Windows
        requiredSize = (size_t)::WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK | WC_SEPCHARS | WC_NO_BEST_FIT_CHARS, wideString.c_str(), -1, nullptr, 0, nullptr, nullptr);
#else
        // ANSI C/C++
        requiredSize = ::wcstombs(nullptr, wideString.c_str(), 0);
#endif

    if(requiredSize > 0)
    {
        cstrASCII = (char*)::malloc((requiredSize + 1) * sizeof(char));
        if(cstrASCII != nullptr)
        {
            cstrASCII[requiredSize] = '\0';
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
                // Microsoft Windows
                nRet = (size_t)::WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK | WC_SEPCHARS | WC_NO_BEST_FIT_CHARS, wideString.c_str(), -1, cstrASCII, (int)requiredSize, nullptr, nullptr);
#else
                // ANSI C/C++
                nRet = ::wcstombs(cstrASCII, wideString.c_str(), requiredSize);
#endif

            if((nRet == 0) || (nRet == static_cast<size_t>(-1)) || (nRet > requiredSize))
            {
                // Error converting string
                ::free((void*)cstrASCII);
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
        throw logic_error("Can't convert wide string to narrow string");
    }
    else
    {
        narrowString = string(cstrASCII);
        ::free(cstrASCII);
        cstrASCII = nullptr;
    }

    return narrowString;
}

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
u32string CodePage2Unicode::convertStringUtf16_to_StringUtf32(const u16string& utf16String, const bool strictConversion)
{
    u32string strRet;
    char16_t charUtf16_1;
    char16_t charUtf16_2;
    char32_t codeUnits[2] = {
        0, 0
    };
    for(unsigned i = 0; i < utf16String.length(); i++)
    {
        charUtf16_1 = utf16String.at(i);
        if(isUtf16HighSurrogate(charUtf16_1))
        {
            // If we have a surrogate pair, convert to UTF-32 first
            ++i;
            if(i < utf16String.length())
            {
                // Read surrogate low
                charUtf16_2 = utf16String.at(i);
                if(isUtf16LowSurrogate(charUtf16_2))
                {
                    codeUnits[0] = static_cast<char32_t>(((charUtf16_1 - UNICODE_HIGH_SURROGATE_START) << UTF16_HALF_SHIFT) +
                                                         (charUtf16_2 - UNICODE_LOW_SURROGATE_START) + UTF16_HALF_BASE);
                }
                else
                {
                    if(strictConversion)
                    {
                        throw logic_error("Invalid UTF-16 low surrogate pair");
                        break;
                    }
                    else
                    {
                        // Ignore
                        --i;
                    }
                }
            }
            else
            {
                if(strictConversion)
                {
                    throw logic_error("Invalid UTF-16 unpaired high surrogate pair");
                    break;
                }
                else
                {
                    // Ignore
                    --i;
                }
            }
        }
        else if(isUtf16LowSurrogate(charUtf16_1))
        {
            if(strictConversion)
            {
                throw logic_error("Invalid UTF-16 unpaired low surrogate pair");
                break;
            }
            else
            {
                codeUnits[0] = static_cast<char32_t>(UNICODE_REPLACEMENT_CHARACTER);
                strRet.append(codeUnits);
            }
        }
        else
        {
            // OK, code point in BMP
            codeUnits[0] = static_cast<char32_t>(charUtf16_1);
        }

        // Check if UTF-32 code point is valid
        if(!isUnicodeInterchangeCharacter(codeUnits[0]) && !isUtf16Surrogate((char16_t)codeUnits[0]))
        {
            if(strictConversion)
            {
                throw logic_error("Invalid UTF-32 code point");
            }
            else
            {
                codeUnits[0] = static_cast<char32_t>(UNICODE_REPLACEMENT_CHARACTER);
            }
        }

        // Add code point to UTF-32 string
        strRet.append(codeUnits);
    }

    return strRet;
}

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
u16string CodePage2Unicode::convertStringUtf32_to_StringUtf16(const u32string& utf32String, const bool strictConversion)
{
    u16string strRet;
    char32_t charUtf32;
    bool surrogate32;
    for(unsigned i = 0; i < utf32String.length(); i++)
    {
        charUtf32 = utf32String.at(i);
        surrogate32 = isUtf32Surrogate(charUtf32);

        // Check if UTF-32 code point is valid
        if(!isUnicodeInterchangeCharacter(charUtf32) && !isUtf16Surrogate((char16_t)charUtf32))
        {
            if(strictConversion)
            {
                throw logic_error("Invalid UTF-32 code point");
            }
            else
            {
                char16_t codeUnits[2] = {
                    0, 0
                };
                codeUnits[1] = static_cast<char16_t>(UNICODE_REPLACEMENT_CHARACTER);
                strRet.append(codeUnits);
            }
        }
        else
        {
            if((charUtf32 <= UNICODE_MAXIMUM_BMP) && !(surrogate32))
            {
                // UCS-4/UTF-32 BMP code point doesn't needs to be converted to UTF-16 surrogate
                char16_t codeUnits[2] = {
                    0, 0
                };

                if(isUtf16Surrogate(static_cast<char16_t>(charUtf32)) || (charUtf32 == 0XFFFE) || (charUtf32 == 0XFFFF))
                {
                    // UTF-16 surrogate values are illegal in UTF-32; 0XFFFF and 0XFFFE are both reserved values
                    if(strictConversion)
                    {
                        throw logic_error("Invalid UTF-32 code point");
                        break;
                    }
                    else
                    {
                        codeUnits[0] = static_cast<char16_t>(UNICODE_REPLACEMENT_CHARACTER);
                    }
                }
                else
                {
                    // OK, normal case
                    codeUnits[0] = static_cast<char16_t>(charUtf32);
                }

                strRet.append(codeUnits);
            }
            else if(surrogate32)
            {
                // As Unicode 7.0, no UTF-32 surrogates exist
            }
            else
            {
                // UCS-4/UTF-32 code point needs to be converted to UTF-16 surrogate
                char16_t codeUnits[3] = {
                    0, 0, 0
                };

                if(charUtf32 > UNICODE_MAXIMUM)
                {
                    // UTF-32 code point is invalid, due to be hider than the maximum value of Unicode
                    if(strictConversion)
                    {
                        throw logic_error("Invalid UTF-32 code point");
                        break;
                    }
                    else
                    {
                        codeUnits[0] = static_cast<char16_t>(UNICODE_REPLACEMENT_CHARACTER);
                        strRet.append(codeUnits);
                    }
                }
                else
                {
                    // OK, UTF-32 code point in range 0x10000 - 0x10FFFF
                    charUtf32 -= UTF16_HALF_BASE;
                    codeUnits[0] = static_cast<wchar_t>((charUtf32 >> UTF16_HALF_SHIFT) + UNICODE_HIGH_SURROGATE_START);
                    codeUnits[1] = static_cast<wchar_t>((charUtf32 & UTF16_HALF_MASK) + UNICODE_LOW_SURROGATE_START);
                    strRet.append(codeUnits);
                }
            }
        }
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
string CodePage2Unicode::convertStringUtf16_to_StringUtf8(const u16string& utf16String, const bool strictConversion)
{
    // Validate parameters
    assert(&utf16String != nullptr);

    u32string utf32String = convertStringUtf16_to_StringUtf32(utf16String, strictConversion);
    string utf8String = convertStringUtf32_to_StringUtf8(utf32String, strictConversion);

    return utf8String;
}

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
u16string CodePage2Unicode::convertStringUtf8_to_StringUtf16(const string& utf8String, const bool strictConversion)
{
    u32string utf32String = convertStringUtf8_to_StringUtf32(utf8String, strictConversion);
    u16string utf16String = convertStringUtf32_to_StringUtf16(utf32String, strictConversion);

    return utf16String;
}

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
string CodePage2Unicode::convertStringUtf32_to_StringUtf8(const u32string& utf32String, const bool strictConversion)
{
    // Validate parameters
    assert(&utf32String != nullptr);

    static const char firstByteMark[6] = {
        0x00, UTF8_LEAD_BYTES2, UTF8_LEAD_BYTES3, UTF8_LEAD_BYTES4, UTF8_LEAD_BYTES5, UTF8_LEAD_BYTES6
    };

    string utf8String;

    size_t i = 0;

    while(i < utf32String.length())
    {
        try
        {
            // Maximum code points length is 6 bytes, but as Unicode 7.0, only 4 bytes are valid (plus one for null)
            char codeUnits[7] = {
                '\0', '\0', '\0', '\0', '\0', '\0', '\0'
            };

            char32_t codePoint = utf32String.at(i);
            size_t sequenceBytes = getCodeUnitsForUtf8Char(codePoint);
            ++i;

            // Check if UTF-32 code point is valid
            if(!isUnicodeInterchangeCharacter(codePoint) && !isUtf16Surrogate((char16_t)codePoint))
            {
                if(strictConversion)
                {
                    throw logic_error("Invalid UTF-32 code point");
                }
                else
                {
                    codeUnits[0] = static_cast<char>(0xEFU);
                    codeUnits[1] = static_cast<char>(0xBFU);
                    codeUnits[2] = static_cast<char>(0xBDU);
                }
            }
            else if(isUtf32Surrogate(codePoint))
            {
                // UTF-32 surrogate don't exist as Unicode 7.0
                if(strictConversion)
                {
                    throw logic_error("Invalid UTF-32 code point");
                }
                else
                {
                    codeUnits[0] = static_cast<char>(0xEFU);
                    codeUnits[1] = static_cast<char>(0xBFU);
                    codeUnits[2] = static_cast<char>(0xBDU);
                }
            }
            else
            {
                if(sequenceBytes == 1)
                {
                    // OK, it's an ASCII, so no surrogate needed
                    codeUnits[0] = static_cast<char>(codePoint);
                }
                else
                {
                    for(size_t j = sequenceBytes - 1; j >= 1; --j)
                    {
                        codeUnits[j] = static_cast<unsigned char>((codePoint | UTF8_NEXT) & 0xBFU);
                        codePoint >>= UTF8_HALF_SHIFT;
                    }
                    codeUnits[0] = static_cast<unsigned char>((codePoint | firstByteMark[sequenceBytes - 1]));
                }
            }

            // Add code point to UTF-32 string
            utf8String.append((char*)&(codeUnits[0]));
        }
        catch(logic_error& ex)
        {
            // Invalid UTF-8 code unit
            throw;
			// Remove unreferenced local variable warning
			ex;
        }
        catch(...)
        {
            // Invalid UTF-8 code unit or generic error
            throw;
        }
    }

    return utf8String;
}

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
u32string CodePage2Unicode::convertStringUtf8_to_StringUtf32(const string& utf8String, const bool strictConversion)
{
    // Validate parameters
    assert(&utf8String != nullptr);

    u32string utf32String;
    size_t i = 0;

    while(i < utf8String.length())
    {
        try
        {
            char32_t codeUnits[2] = {
#if defined(_WIN32)
                L'\0', L'\0'
#else
				U'\0', U'\0'
#endif
            };

            char codeUnit = utf8String.at(i);
            size_t sequenceBytes = getCodeUnitsForUtf8Leads(codeUnit) - 1;
            ++i;

            if(isUtf8NextSurrogate(codeUnit))
            {
                // Invalid next lead surrogate
                if(strictConversion)
                {
                    throw logic_error("Invalid UTF-8 sequence first surrogate");
                }
                else
                {
                    codeUnits[0] = static_cast<char32_t>(UNICODE_REPLACEMENT_CHARACTER);
                }
            }
            else
            {
                if(sequenceBytes == 0)
                {
                    // OK, it's an ASCII, so no surrogate needed
                    codeUnits[0] = static_cast<char32_t>(static_cast<unsigned char>(codeUnit));
                }
                else
                {   // First surrogate sequence code unit
                    switch(sequenceBytes)
                    {
                        case 1:
                            codeUnits[0] = codeUnit & UTF8_LEAD_BYTES2_MASK;
                            break;

                        case 2:
                            codeUnits[0] = codeUnit & UTF8_LEAD_BYTES3_MASK;
                            break;

                        case 3:
                            codeUnits[0] = codeUnit & UTF8_LEAD_BYTES4_MASK;
                            break;

                        case 4:
                            codeUnits[0] = codeUnit & UTF8_LEAD_BYTES5_MASK;
                            break;

                        case 5:
                            codeUnits[0] = codeUnit & UTF8_LEAD_BYTES6_MASK;
                            break;
                    }

                    for(size_t j = 0; j < sequenceBytes; ++j)
                    {
                        // Read the next code unit of the surrogate sequence
                        if(i >= utf8String.length())
                        {
                            // Error, the UTF-8 string ended to soon
                            throw logic_error("Invalid UTF-8 size");
                        }
                        char codeUnitNext = utf8String.at(i);
                        if(!isUtf8NextSurrogate(codeUnitNext))
                        {
                            // Error, not a next code unit of the surrogate sequence
                            if(strictConversion)
                            {
                                throw logic_error("Invalid UTF-8 sequence");
                            }
                            else
                            {
                                codeUnits[0] = static_cast<char32_t>(UNICODE_REPLACEMENT_CHARACTER);
                            }
                        }
                        else
                        {
                            // OK, build UTF-32 character from sequence
                            codeUnits[0] = (codeUnits[0]) << UTF8_HALF_SHIFT;
                            codeUnits[0] = (codeUnits[0]) + (codeUnitNext & UTF8_NEXT_MASK);
                        }

                        ++i;
                    }
                }
            }

            // Check if UTF-32 code point is valid
            if(!isUnicodeInterchangeCharacter(codeUnits[0]) && !isUtf16Surrogate((char16_t)codeUnits[0]))
            {
                if(strictConversion)
                {
                    throw logic_error("Invalid UTF-32 code point");
                }
                else
                {
                    codeUnits[0] = static_cast<char32_t>(UNICODE_REPLACEMENT_CHARACTER);
                }
            }

            // Add code point to UTF-32 string
            utf32String.append(codeUnits);
        }
        catch(logic_error& ex)
        {
            // Invalid UTF-8 code unit
            throw;
			// Remove unreferenced local variable warning
			ex;
        }
        catch(...)
        {
            // Invalid UTF-8 code unit or generic error
            throw;
        }
    }

    return utf32String;
}
