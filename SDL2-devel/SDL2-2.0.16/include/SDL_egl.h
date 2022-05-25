/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2021 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file SDL_egl.h
 *
 *  This is a simple file to encapsulate the EGL API headers.
 */
#if !defined(_MSC_VER) && !defined(__ANDROID__)

#include <EGL/egl.h>
#include <EGL/eglext.h>

#else /* _MSC_VER */

/* EGL headers for Visual Studio */

#ifndef __khrplatform_h_
#define __khrplatform_h_

/*
** Copyright (c) 2008-2009 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
*
* $Revision: 23298 $ on $Date: 2013-09-30 17:07:13 -0700 (Mon, 30 Sep 2013) $
*
* Adopters may modify this file to suit their platform. Adopters are
* encouraged to submit platform specific modifications to the Khronos
* group so that they can be included in future versions of this file.
* Please submit changes by sending them to the public Khronos Bugzilla
* (http://khronos.org/bugzilla) by filing a bug against product
* "Khronos (general)" component "Registry".
*
* A predefined template which fills in some of the bug fields can be
* reached using http://tinyurl.com/khrplatform-h-bugreport, but you
* must create a Bugzilla login first.
*
*
* See the Implementer's Guidelines for information about where this file
* should be located on your system and for more details of its use:
*    http://www.khronos.org/registry/implementers_guide.pdf
*
* This file should be included as
*        #include <KHR/khrplatform.h>
* by Khronos client API header files that use its types and defines.
*
* The types in khrplatform.h should only be used to define API-specific types.
*
* Types defined in khrplatform.h:
*    khronos_int8_t              signed   8  bit
*    khronos_uint8_t             unsigned 8  bit
*    khronos_int16_t             signed   16 bit
*    khronos_uint16_t            unsigned 16 bit
*    khronos_int32_t             signed   32 bit
*    khronos_uint32_t            unsigned 32 bit
*    khronos_int64_t             signed   64 bit
*    khronos_uint64_t            unsigned 64 bit
*    khronos_intptr_t            signed   same number of bits as a pointer
*    khronos_uintptr_t           unsigned same number of bits as a pointer
*    khronos_ssize_t             signed   size
*    khronos_usize_t             unsigned size
*    khronos_float_t             signed   32 bit floating point
*    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
*    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
*                                         nanoseconds
*    khronos_stime_nanoseconds_t signed time interval in nanoseconds
*    khronos_boolean_enum_t      enumerated boolean type. This should
*      only be used as a base type when a client API's boolean type is
*      an enum. Client APIs which use an integer or other type for
*      booleans cannot use this as the base type for their boolean.
*
* Tokens defined in khrplatform.h:
*
*    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
*
*    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
*    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
*
* Calling convention macros defined in this file:
*    KHRONOS_APICALL
*    KHRONOS_APIENTRY
*    KHRONOS_APIATTRIBUTES
*
* These may be used in function prototypes as:
*
*      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
*                                  int arg1,
*                                  int arg2) KHRONOS_APIATTRIBUTES;
*/

/*-------------------------------------------------------------------------
* Definition of KHRONOS_APICALL
*-------------------------------------------------------------------------
* This precedes the return type of the function in the function prototype.
*/
#if defined(_WIN32) && !defined(__SCITECH_SNAP__) && !defined(SDL_VIDEO_STATIC_ANGLE)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#else
#   define KHRONOS_APICALL
#endif

/*-------------------------------------------------------------------------
* Definition of KHRONOS_APIENTRY
*-------------------------------------------------------------------------
* This follows the return type of the function  and precedes the function
* name in the function prototype.
*/
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
/* Win32 but not WinCE */
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif

/*-------------------------------------------------------------------------
* Definition of KHRONOS_APIATTRIBUTES
*-------------------------------------------------------------------------
* This follows the closing parenthesis of the function prototype arguments.
*/
#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

/*-------------------------------------------------------------------------
* basic type definitions
*-----------------------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


/*
* Using <stdint.h>
*/
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__VMS ) || defined(__sgi)

/*
* Using <inttypes.h>
*/
#include <inttypes.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

/*
* Win32
*/
typedef __int32                 khronos_int32_t;
typedef unsigned __int32        khronos_uint32_t;
typedef __int64                 khronos_int64_t;
typedef unsigned __int64        khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

/*
* Sun or Digital
*/
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
typedef long int                khronos_int64_t;
typedef unsigned long int       khronos_uint64_t;
#else
typedef long long int           khronos_int64_t;
typedef unsigned long long int  khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

/*
* Hypothetical platform with no float or int64 support
*/
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

/*
* Generic fallback
*/
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif


/*
* Types that are (so far) the same on all platforms
*/
typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;

/*
* Types that differ between LLP64 and LP64 architectures - in LLP64,
* pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
* to be the only LLP64 architecture in current use.
*/
#ifdef _WIN64
typedef signed   long long int khronos_intptr_t;
typedef unsigned long long int khronos_uintptr_t;
typedef signed   long long int khronos_ssize_t;
typedef unsigned long long int khronos_usize_t;
#else
typedef signed   long  int     khronos_intptr_t;
typedef unsigned long  int     khronos_uintptr_t;
typedef signed   long  int     khronos_ssize_t;
typedef unsigned long  int     khronos_usize_t;
#endif

#if KHRONOS_SUPPORT_FLOAT
/*
* Float type
*/
typedef          float         khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
/* Time types
*
* These types can be used to represent a time interval in nanoseconds or
* an absolute Unadjusted System Time.  Unadjusted System Time is the number
* of nanoseconds since some arbitrary system event (e.g. since the last
* time the system booted).  The Unadjusted System Time is an unsigned
* 64 bit value that wraps back to 0 every 584 years.  Time intervals
* may be either signed or unsigned.
*/
typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif

/*
* Dummy value used to pad enum types to 32 bits.
*/
#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

/*
* Enumerated boolean type
*
* Values other than zero should be considered to be true.  Therefore
* comparisons should not be made against KHRONOS_TRUE.
*/
typedef enum {
    KHRONOS_FALSE = 0,
    KHRONOS_TRUE = 1,
    KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;

#endif /* __khrplatform_h_ */


#ifndef __eglplatform_h_
#define __eglplatform_h_

/*
** Copyright (c) 2007-2009 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Platform-specific types and definitions for egl.h
* $Revision: 12306 $ on $Date: 2010-08-25 09:51:28 -0700 (Wed, 25 Aug 2010) $
*
* Adopters may modify khrplatform.h and this file to suit their platform.
* You are encouraged to submit all modifications to the Khronos group so that
* they can be included in future versions of this file.  Please submit changes
* by sending them to the public Khronos Bugzilla (http://khronos.org/bugzilla)
* by filing a bug against product "EGL" component "Registry".
*/

/*#include <KHR/khrplatform.h>*/

/* Macros used in EGL function prototype declarations.
*
* EGL functions should be prototyped as:
*
* EGLAPI return-type EGLAPIENTRY eglFunction(arguments);
* typedef return-type (EXPAPIENTRYP PFNEGLFUNCTIONPROC) (arguments);
*
* KHRONOS_APICALL and KHRONOS_APIENTRY are defined in KHR/khrplatform.h
*/

#ifndef EGLAPI
#define EGLAPI KHRONOS_APICALL
#endif

#ifndef EGLAPIENTRY
#define EGLAPIENTRY  KHRONOS_APIENTRY
#endif
#define EGLAPIENTRYP EGLAPIENTRY*

/* The types NativeDisplayType, NativeWindowType, and NativePixmapType
* are aliases of window-system-dependent types, such as X Display * or
* Windows Device Context. They must be defined in platform-specific
* code below. The EGL-prefixed versions of Native*Type are the same
* types, renamed in EGL 1.3 so all types in the API start with "EGL".
*
* Khronos STRONGLY RECOMMENDS that you use the default definitions
* provided below, since these changes affect both binary and source
* portability of applications using EGL running on different EGL
* implementations.
*/

#if defined(_WIN32) || defined(__VC32__) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__) /* Win32 and WinCE */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX   /* don't define min() and max(). */
#define NOMINMAX
#endif
#include <windows.h>

#if __WINRT__
#include <Unknwn.h>
typedef IUnknown * EGLNativeWindowType;
typedef IUnknown * EGLNativePixmapType;
typedef IUnknown * EGLNativeDisplayType;
#else
typedef HDC     EGLNativeDisplayType;
typedef HBITMAP EGLNativePixmapType;
typedef HWND    EGLNativeWindowType;
#endif

#elif defined(__WINSCW__) || defined(__SYMBIAN32__)  /* Symbian */

typedef int   EGLNativeDisplayType;
typedef void *EGLNativeWindowType;
typedef void *EGLNativePixmapType;

#elif defined(WL_EGL_PLATFORM)

typedef struct wl_display     *EGLNativeDisplayType;
typedef struct wl_egl_pixmap  *EGLNativePixmapType;
typedef struct wl_egl_window  *EGLNativeWindowType;

#elif defined(__GBM__)

typedef struct gbm_device  *EGLNativeDisplayType;
typedef struct gbm_bo      *EGLNativePixmapType;
typedef void               *EGLNativeWindowType;

#elif defined(__ANDROID__) /* Android */

struct ANativeWindow;
struct egl_native_pixmap_t;

typedef struct ANativeWindow        *EGLNativeWindowType;
typedef struct egl_native_pixmap_t  *EGLNativePixmapType;
typedef void                        *EGLNativeDisplayType;

#elif defined(MIR_EGL_PLATFORM)

#include <mir_toolkit/mir_client_library.h>
typedef MirEGLNativeDisplayType EGLNativeDisplayType;
typedef void                   *EGLNativePixmapType;
typedef MirEGLNativeWindowType  EGLNativeWi