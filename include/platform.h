// MIT License
// 
// Copyright (c) [2018] [MITfullname]
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include "shared_EXPORTS.h"

//-------------------------------------------------------------------------------------------------
// return error code
//-------------------------------------------------------------------------------------------------
enum LS_RESULT: short
{
    LS_OK  = 0,
    LS_FINISHED,

    LS_FAIL = -1,
    LS_NOT_SUPPORTED,
    LS_NOT_FOUND,
    LS_NOT_AVAILABLE,
};

//-------------------------------------------------------------------------------------------------
// common macros
//-------------------------------------------------------------------------------------------------
#define LS_TODO(_todo) (__FILE__ "(" LS_MACRO_STRING(__LINE__) "): TODO: "_todo)

#define LS_MACRO_STRING2(x) #x
#define LS_MACRO_STRING(x) LS_MACRO_STRING2(x)

#define LS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LS_MAX(a, b) ((a) > (b) ? (a) : (b))

#if defined(_WIN32)
    #define PATH_SEPARATOR_WSTR         L"\\"
    #define PATH_SEPARATOR_WCHAR        L'\\'
#elif defined(__linux) // Linux
    #define PATH_SEPARATOR_WSTR          L"/"
    #define PATH_SEPARATOR_WCHAR         L'/'
#endif

#define LS_countof(x) (sizeof(x) / sizeof(x[0]))

//-------------------------------------------------------------------------------------------------
// function attributes
//-------------------------------------------------------------------------------------------------
#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
    #define LS_CALL                __stdcall
    #define LS_STD_CALL            __stdcall
    #define LS_CDECL_CALL          __cdecl
    #define LS_FAST_CALL           __fastcall
#if defined(__GNUC__) || defined(__clang__)
    #define LS_INLINE              inline
    #define LS_FORCEINLINE         inline
#else
    #define LS_INLINE              __inline
    #define LS_FORCEINLINE         __forceinline
#endif
    #define LS_NO_VTABLE           __declspec(novtable)

    #define LSPRId64   "I64d"
    #define LPRId64    L"I64d"

    #define LSPRIud64   "Iu64d"
    #define LPRIud64    L"Iu64d"

    #define LSPRIx64   "I64x"
    #define LPRIx64    L"I64x"

#else // Linux and Mac
    #define LS_CALL 
    #define LS_STD_CALL
    #define LS_CDECL_CALL
    #define LS_FAST_CALL
#if defined(__GNUC__) || defined(__clang__)
    #define LS_INLINE              inline
    #define LS_FORCEINLINE         inline
#else
    #define LS_INLINE              __inline__
    #define LS_FORCEINLINE         __inline__
#endif
    #define LS_NO_VTABLE           

    #if !defined(LSPRId64)
        #define LSPRId64    "lld"
        #define LPRId64     L"lld"

        #define LSPRIud64    "ulld"
        #define LPRIud64     L"ulld"

        #define LSPRIx64    "llx"
        #define LPRIx64     L"llx"
    #endif

#endif // WIN32

#if defined(__GNUC__) || defined(__clang__)
    #define LS_ALIGN(n) __attribute__((aligned(n)))
#elif defined(_MSC_VER) || defined(__INTEL_COMPILER)
    #define LS_ALIGN(n) __declspec(align(n))
#else
#define LS_ALIGN(n)
//     #error Need to define LS_ALIGN
#endif

#if defined(_MSC_VER)
#define LS_WEAK __declspec( selectany ) 
#elif defined (__GNUC__) || defined (__GCC__) || defined(__clang__)//GCC or CLANG
#define LS_WEAK __attribute__((weak))
#endif

//-------------------------------------------------------------------------------------------------
// basic data types
//-------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef     int64_t             LS_int64;
typedef     int32_t             LS_int32;
typedef     int16_t             LS_int16;
typedef     int8_t              LS_int8;

typedef     uint64_t            LS_uint64;
typedef     uint32_t            LS_uint32;
typedef     uint16_t            LS_uint16;
typedef     uint8_t             LS_uint8;
typedef     size_t              LS_size;

typedef     void*               LS_handle;
typedef     double              LS_double;
typedef     float               LS_float;

typedef     void                LS_void;

#if defined(__cplusplus)
typedef     bool                LS_bool;
#else
typedef     LS_uint8           LS_bool;
#define     true                1 
#define     false               0 
#endif

typedef     long                LS_long; 
typedef     int                 LS_int; 
typedef     unsigned long       LS_ulong; 
typedef     unsigned int        LS_uint; 

typedef     LS_int64           LS_pts;     // in 100 nanosecs

typedef LS_uint32              LS_flags;

#define LS_SECOND          10000000L    // 1 second in 100 nanoseconds
