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
#include "solver.h"
#include <vector>

namespace LS
{

class DPSolver : public ISolver
{
public:
    DPSolver();

    /**
     * @brief Movable and non-copyable 
     */
    DPSolver(DPSolver &&) = default;
    DPSolver &operator=(DPSolver &&) = default;

    /**
    @brief Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You mayassume that each input would have exactly one solution, and you may not use the same element twice.
    https://leetcode.com/problems/two-sum/description/
    @return two indices
    @param nums array of weights
    @param nums array of profits
    @param max capacity of the knapsack
    */
    virtual LS_size knapsackBasic(const std::vector<LS_size> &weights, const std::vector<LS_size> &profits, LS_size capacity) const noexcept;

private:
    struct Impl;
    /**
     * @brief Pimpl design
     */
    std::unique_ptr<Impl, void (*)(Impl *)> m_impl;
};

} // namespace LS
