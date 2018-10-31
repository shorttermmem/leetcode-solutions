#pragma once

#include "factory.h"

namespace LS
{
    class FactoryImpl final : public Factory
    {
    public:
        LS_RESULT LS_STD_CALL CreateSolver(SolverType type, ISolver** ppSolver) final;
    };

} // namespace LS