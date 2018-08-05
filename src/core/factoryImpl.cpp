#include "factoryImpl.h"

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
LS_RESULT LS_STD_CALL FactoryImpl::CreateArrays(Arrays** ppArrays)
{
    static Arrays sol;
    *ppArrays = &sol;
    return LS_OK;
}