#include "factoryimpl.h"
#include "arraysolver.h"
#include "stringsolver.h"
#include "sortingsolver.h"

using namespace LS;

//-------------------------------------------------------------------------------------------------
LS_RESULT LS_CDECL_CALL LSInit(LS_uint64 version, LS::Factory **ppFactory)
{
    static FactoryImpl factory;
    *ppFactory = &factory;
    return LS_OK;
}
//-------------------------------------------------------------------------------------------------
LS_RESULT LS_CDECL_CALL LSQueryVersion(LS_uint64 *pVersion)
{
    //LS_RETURN_IF_FALSE(pVersion != NULL, LS_INVALID_ARG, L"pVersion==NULL");
    *pVersion = LS_FULL_VERSION;
    return LS_OK;
}
//-------------------------------------------------------------------------------------------------
LS_RESULT LS_STD_CALL FactoryImpl::CreateSolver(SolverType type, ISolver** ppSolver)
{
    // Create new instance each time and relinguish its ownership.
    switch(type)
    {
    case ArraySolverType:
        *ppSolver = new ArraySolver();
        break;
    case StringSolverType:
        *ppSolver = new StringSolver();
        break;
    case SortingSolverType:
        *ppSolver = new SortingSolver();
        break;
    default:
        return LS_NOT_FOUND;
    }
    return LS_OK;
}