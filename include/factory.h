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

#if defined(__cplusplus)
namespace LS
{
    enum SolverType : int{
        ArraySolverType = 0,
        StringSolverType = 1,
        DPSolverType = 2,
    };

    class ISolver;

    //----------------------------------------------------------------------------------------------
    // LSFactory interface - singleton
    //----------------------------------------------------------------------------------------------
    class LS_NO_VTABLE Factory
    {
    public:
        virtual LS_RESULT  LS_STD_CALL CreateSolver(SolverType type, ISolver** ppSolver) = 0;
   };
}
#else
/*
C style API not yet supported.

typedef struct Factory Factory;

typedef struct FactoryVtbl
{
    LS_RESULT         (LS_STD_CALL *CreateSolver)(Factory* pThis, SolverType type,  ISolver** ppSolver);
} FactoryVtbl;

struct Factory
{
    const FactoryVtbl *pVtbl;
};
*/
#endif

//----------------------------------------------------------------------------------------------
// shared library entry points
//----------------------------------------------------------------------------------------------

#define INIT_FUNCTION_NAME             "LSInit"
#define QUERY_VERSION_FUNCTION_NAME    "LSQueryVersion"

#if defined(__cplusplus)
extern "C"
{
    typedef LS_RESULT    (LS_CDECL_CALL *LSInit_Fn)(int version, LS::Factory **ppFactory);
    typedef LS_RESULT    (LS_CDECL_CALL *LSQueryVersion_Fn)(int  *pVersion);

    SHARED_EXPORT LS_RESULT LS_CDECL_CALL LSInit(LS_uint64 version, LS::Factory **ppFactory);
    SHARED_EXPORT LS_RESULT LS_CDECL_CALL LSQueryVersion(LS_uint64 *pVersion);
}
#else 
    typedef LS_RESULT             (LS_CDECL_CALL *LSInit_Fn)(int version, LSFactory **ppFactory);
    typedef LS_RESULT             (LS_CDECL_CALL *LSQueryVersion_Fn)(int *pVersion);
#endif

