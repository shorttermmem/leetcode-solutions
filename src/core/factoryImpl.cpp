#include "factoryImpl.h"

using namespace ZZ;

/*
extern "C"
{
    SHARED_EXPORT ZZ_RESULT ZZ_CDECL_CALL ZZInit(ZZ_uint64 version, ZZ::ZZFactory **ppFactory);
    SHARED_EXPORT ZZ_RESULT ZZ_CDECL_CALL ZZQueryVersion(ZZ_uint64 *pVersion);
}
*/
//-------------------------------------------------------------------------------------------------
ZZ_RESULT ZZ_CDECL_CALL ZZInit(ZZ_uint64 version, ZZ::ZZFactory **ppFactory)
{
    static ZZFactoryImpl factory;
    *ppFactory = &factory;
    return ZZ_OK;
}
//-------------------------------------------------------------------------------------------------
ZZ_RESULT ZZ_CDECL_CALL ZZQueryVersion(ZZ_uint64 *pVersion)
{
    //ZZ_RETURN_IF_FALSE(pVersion != NULL, ZZ_INVALID_ARG, L"pVersion==NULL");
    *pVersion = ZZ_FULL_VERSION;
    return ZZ_OK;
}
//-------------------------------------------------------------------------------------------------
ZZ_RESULT ZZ_STD_CALL ZZFactoryImpl::CreateArrays(Arrays** ppArrays)
{
    static Arrays sol;
    *ppArrays = &sol;
    return ZZ_OK;
}