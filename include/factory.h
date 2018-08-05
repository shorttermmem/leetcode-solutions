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

#include "version.h"
#include "categories/arrays.h"

#if defined(__cplusplus)
namespace ZZ
{
#endif
    //----------------------------------------------------------------------------------------------
    // ZZFactory interface - singleton
    //----------------------------------------------------------------------------------------------
#if defined(__cplusplus)
    class ZZ_NO_VTABLE ZZFactory
    {
    public:
        virtual ZZ_RESULT  ZZ_STD_CALL CreateArrays(Arrays** ppArrays) = 0;
   };
#else
    typedef struct ZZFactory ZZFactory;

    typedef struct ZZFactoryVtbl
    {
        ZZ_RESULT          (ZZ_STD_CALL *CreateArrays)(ZZFactory* pThis, int** ppContext);
    } ZZFactoryVtbl;

    struct ZZFactory
    {
        const ZZFactoryVtbl *pVtbl;
    };

#endif
#if defined(__cplusplus)
}
#endif

//----------------------------------------------------------------------------------------------
// shared library entry points
//----------------------------------------------------------------------------------------------

#define INIT_FUNCTION_NAME             "ZZInit"
#define QUERY_VERSION_FUNCTION_NAME    "ZZQueryVersion"

#if defined(__cplusplus)
extern "C"
{
    typedef ZZ_RESULT    (ZZ_CDECL_CALL *ZZInit_Fn)(int version, ZZ::ZZFactory **ppFactory);
    typedef ZZ_RESULT    (ZZ_CDECL_CALL *ZZQueryVersion_Fn)(int  *pVersion);

    SHARED_EXPORT ZZ_RESULT ZZ_CDECL_CALL ZZInit(ZZ_uint64 version, ZZ::ZZFactory **ppFactory);
    SHARED_EXPORT ZZ_RESULT ZZ_CDECL_CALL ZZQueryVersion(ZZ_uint64 *pVersion);
}
#else 
    typedef ZZ_RESULT             (ZZ_CDECL_CALL *ZZInit_Fn)(int version, ZZFactory **ppFactory);
    typedef ZZ_RESULT             (ZZ_CDECL_CALL *ZZQueryVersion_Fn)(int *pVersion);
#endif

#if defined(_WIN32)
    #if defined(_M_AMD64)
        #define ZZ_DLL_NAME    L"ZZrt64.dll"
        #define ZZ_DLL_NAMEA   "ZZrt64.dll"
    #else
        #define ZZ_DLL_NAME    L"ZZrt32.dll"
        #define ZZ_DLL_NAMEA   "ZZrt32.dll"
    #endif
#elif defined(__linux__)
    #if defined(__x86_64__)
        #define ZZ_DLL_NAME    L"ZZrt64.so"
        #define ZZ_DLL_NAMEA   "ZZrt64.so"
    #else
        #define ZZ_DLL_NAME    L"ZZrt32.so"
        #define ZZ_DLL_NAMEA   "ZZrt32.so"
    #endif
#endif 
