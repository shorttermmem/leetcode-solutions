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
enum ZZ_RESULT: short
{
    ZZ_OK  = 0,
    ZZ_FINISHED,

    ZZ_FAIL = -1,
    ZZ_NOT_SUPPORTED,
    ZZ_NOT_FOUND,
    ZZ_NOT_AVAILABLE,
};

//-------------------------------------------------------------------------------------------------
// common macros
//-------------------------------------------------------------------------------------------------
#define ZZ_TODO(_todo) (__FILE__ "(" ZZ_MACRO_STRING(__LINE__) "): TODO: "_todo)

#define ZZ_MACRO_STRING2(x) #x
#define ZZ_MACRO_STRING(x) ZZ_MACRO_STRING2(x)

#define ZZ_MIN(a, b) ((a) < (b) ? (a) : (b))
#define ZZ_MAX(a, b) ((a) > (b) ? (a) : (b))

#if defined(_WIN32)
    #define PATH_SEPARATOR_WSTR         L"\\"
    #define PATH_SEPARATOR_WCHAR        L'\\'
#elif defined(__linux) // Linux
    #define PATH_SEPARATOR_WSTR          L"/"
    #define PATH_SEPARATOR_WCHAR         L'/'
#endif

#define ZZ_countof(x) (sizeof(x) / sizeof(x[0]))

//-------------------------------------------------------------------------------------------------
// function attributes
//-------------------------------------------------------------------------------------------------
#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
    #define ZZ_CALL                __stdcall
    #define ZZ_STD_CALL            __stdcall
    #define ZZ_CDECL_CALL          __cdecl
    #define ZZ_FAST_CALL           __fastcall
#if defined(__GNUC__) || defined(__clang__)
    #define ZZ_INLINE              inline
    #define ZZ_FORCEINLINE         inline
#else
    #define ZZ_INLINE              __inline
    #define ZZ_FORCEINLINE         __forceinline
#endif
    #define ZZ_NO_VTABLE           __declspec(novtable)

    #define ZZPRId64   "I64d"
    #define LPRId64    L"I64d"

    #define ZZPRIud64   "Iu64d"
    #define LPRIud64    L"Iu64d"

    #define ZZPRIx64   "I64x"
    #define LPRIx64    L"I64x"

#else // Linux and Mac
    #define ZZ_CALL 
    #define ZZ_STD_CALL
    #define ZZ_CDECL_CALL
    #define ZZ_FAST_CALL
#if defined(__GNUC__) || defined(__clang__)
    #define ZZ_INLINE              inline
    #define ZZ_FORCEINLINE         inline
#else
    #define ZZ_INLINE              __inline__
    #define ZZ_FORCEINLINE         __inline__
#endif
    #define ZZ_NO_VTABLE           

    #if !defined(ZZPRId64)
        #define ZZPRId64    "lld"
        #define LPRId64     L"lld"

        #define ZZPRIud64    "ulld"
        #define LPRIud64     L"ulld"

        #define ZZPRIx64    "llx"
        #define LPRIx64     L"llx"
    #endif

#endif // WIN32

#if defined(__GNUC__) || defined(__clang__)
    #define ZZ_ALIGN(n) __attribute__((aligned(n)))
#elif defined(_MSC_VER) || defined(__INTEL_COMPILER)
    #define ZZ_ALIGN(n) __declspec(align(n))
#else
#define ZZ_ALIGN(n)
//     #error Need to define ZZ_ALIGN
#endif

#if defined(_MSC_VER)
#define ZZ_WEAK __declspec( selectany ) 
#elif defined (__GNUC__) || defined (__GCC__) || defined(__clang__)//GCC or CLANG
#define ZZ_WEAK __attribute__((weak))
#endif

//-------------------------------------------------------------------------------------------------
// basic data types
//-------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef     int64_t             ZZ_int64;
typedef     int32_t             ZZ_int32;
typedef     int16_t             ZZ_int16;
typedef     int8_t              ZZ_int8;

typedef     uint64_t            ZZ_uint64;
typedef     uint32_t            ZZ_uint32;
typedef     uint16_t            ZZ_uint16;
typedef     uint8_t             ZZ_uint8;
typedef     size_t              ZZ_size;

typedef     void*               ZZ_handle;
typedef     double              ZZ_double;
typedef     float               ZZ_float;

typedef     void                ZZ_void;

#if defined(__cplusplus)
typedef     bool                ZZ_bool;
#else
typedef     ZZ_uint8           ZZ_bool;
#define     true                1 
#define     false               0 
#endif

typedef     long                ZZ_long; 
typedef     int                 ZZ_int; 
typedef     unsigned long       ZZ_ulong; 
typedef     unsigned int        ZZ_uint; 

typedef     ZZ_int64           ZZ_pts;     // in 100 nanosecs

typedef ZZ_uint32              ZZ_flags;

#define ZZ_SECOND          10000000L    // 1 second in 100 nanoseconds
