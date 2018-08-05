#pragma once

#include "factory.h"
#include "arrays.h"
namespace LS
{
    class FactoryImpl : public Factory
    {
    public:
        LS_RESULT LS_STD_CALL CreateArrays(Arrays** ppArrays);
    };

} // namespace LS