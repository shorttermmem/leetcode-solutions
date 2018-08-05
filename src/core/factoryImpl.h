#pragma once

#include "factory.h"
#include "arrays.h"
namespace ZZ
{
    class ZZFactoryImpl : public ZZFactory
    {
    public:
        ZZ_RESULT ZZ_STD_CALL CreateArrays(Arrays** ppArrays);
    };

} // namespace ZZ