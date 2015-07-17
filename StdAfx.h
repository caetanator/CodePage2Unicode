// StdAfx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#pragma once


#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE) || defined(__CYGWIN__)
    // Windows Specific
//#   include "Windows/TargetVer.h"
    // Windows Header Files
#   include <tchar.h>
#   include <windows.h>
#   include <shlobj.h>
#   include <strsafe.h>
#   include <fcntl.h>
#   include <io.h>
#else
    // POSIX Specific
#   include <sys/stat.h>
#   include <sys/types.h>
#   include <dirent.h>
#   include <fcntl.h>
#   include <unistd.h>
#endif

// C Standard Header Files
// * The NDEBUG macro controls if the assert macro is enabled in <assert.h>
#ifdef _DEBUG
#   ifdef NDEBUG
    // Enables the assert macro
#   undef NDEBUG
#       endif
#else
    // Disable the assert macro
#   define NDEBUG
#endif
#include <assert.h>
#include <errno.h>
#include <limits.h>
#if _MSC_VER
	// * The _USE_MATH_DEFINES enables non ANSI C/C++ defines like M_PI in <math.h> for MS VC++
#	define _USE_MATH_DEFINES
#elif defined(__GNUC__ )
	// * The _BSD_SOURCE enables non ANSI C/C++ defines like M_PI in <math.h> for GNU GCC
#	ifndef _BSD_SOURCE
#		define _BSD_SOURCE
#		define ___MY_ERRASE_BSD_SOURCE
#	endif
// * The _GNU_SOURCE enables non ANSI C/C++ defines like M_PIl in <math.h> for GNU GCC
#	ifndef _GNU_SOURCE
#		define _GNU_SOURCE
#		define ___MY_ERRASE_GNU_SOURCE
#	endif
#endif
#include <math.h>
#ifdef ___MY_ERRASE_BSD_SOURCE
#   undef _BSD_SOURCE
#   undef ___MY_ERRASE_BSD_SOURCE
#endif
#ifdef ___MY_ERRASE_GNU_SOURCE
#   undef _GNU_SOURCE
#   undef ___MY_ERRASE_GNU_SOURCE
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

// C++ Standard Header Files
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <codecvt>
#include <cmath>
#include <cwchar>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <new>
#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <vector>

// OpenGL Header Files
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
// Microsoft Windows
//#  include <GL/gl.h>
//#  include <GL/glu.h>
#  include <GL/glew.h>
#  include <GL/glut.h>
#  if(defined(__FREEGLUT_STD_H__))
#    include <GL/freeglut_ext.h>
#  endif
#  if(defined(__OPENGLUT_STD_H__))
#    include <GL/openglut_ext.h>
#  endif
#elif defined(__APPLE__)
// Mac OS
//#  include <OpenGL/gl.h>
//#  include <OpenGL/glu.h>
//#  include <AGL/agl.h>
#  include <OpenGL/glew.h>
#  include <GLUT/glut.h>
#else
// UNIX, Linux, BSD
//#  include <GL/gl.h>
//#  include <GL/glu.h>
//#    include <GL/glx.h>
#  include <GL/glew.h>
#  include <GL/glut.h>
#  if(defined(__FREEGLUT_STD_H__))
#    include <GL/freeglut_ext.h>
#  endif
#  if(defined(__OPENGLUT_STD_H__))
#    include <GL/openglut_ext.h>
#  endif
#endif

// OpenAL Header Files
#if defined(_WIN32) || defined(_WIN64) || defined(_WIN32_WCE)
// Microsoft Windows
#  include <al.h>
#  include <alc.h>
#  include <alut.h>
#  include <efx.h>
#  include <efx-creative.h>
#  include <xram.h>
#elif defined(__APPLE__)
// Mac OS
#  include <OpenAL/al.h>
#  include <OpenAL/alc.h>
#  include <OpenAL/alext.h>
#  include <OpenAL/alut.h>
#else
// UNIX, Linux, BSD
#  include <AL/al.h>
#  include <AL/alc.h>
#  include <AL/alext.h>
#  include <AL/alut.h>
#endif

// OGG/Vorvis Header Files
#include <vorbis/codec.h>
#include <vorbis/vorbisfile.h>

// LibPNG Header Files
#include <png.h>

// Compiler Abstraction Header Files
#include "CompilerEnvironment.h"
#include "CompilerConfig.h"

#endif // __STDAFX_H__
