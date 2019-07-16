
#include <glog/logging.h>

#include <functional>
#include <algorithm>

#include "dpsolver.h"

using namespace LS;
using namespace std;

struct DPSolver::Impl
{

    LS_size knapsackBasic(const std::vector<LS_size> &weights, const std::vector<LS_size> &profits, LS_size capacity)
    {

        LS_size max_profit = 0;

        std::function<LS_size (const std::vector<LS_size> &, const std::vector<LS_size> &, LS_size, LS_size)> recurHelper;
        recurHelper = [&recurHelper](const std::vector<LS_size> &weights, const std::vector<LS_size> &profits, LS_size capacity, LS_size currentIndex) -> LS_size
        {
            if (capacity <= 0 || currentIndex >= weights.size())
                return 0;

            LS_size profitL = 0;
            LS_size profitR = 0;
            LS_size w = weights[currentIndex];

            //LOG(INFO) << "weight" << w << endl;

            if (w <= capacity)
            {
                profitL = profits.at(currentIndex) + recurHelper(weights, profits, capacity - w, currentIndex + 1);
            }    

            profitR = recurHelper(weights, profits, capacity, currentIndex + 1);

            return std::max(profitL, profitR);
        };

        max_profit = recurHelper(weights, profits, capacity, 0);

        return max_profit;
    }

}; // DPSolver::Impl

DPSolver::DPSolver() : m_impl(
                           new Impl(),
                           [](Impl *impl) { delete impl; })
{
}

LS_size DPSolver::knapsackBasic(const std::vector<LS_size> &weights, const std::vector<LS_size> &profits, LS_size capacity) const noexcept
{
    return m_impl->knapsackBasic(weights, profits, capacity);
}
