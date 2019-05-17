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

namespace LS{ 

class ArraySolver : public ISolver{
public:
    ArraySolver();

    /**
     * @brief Movable and non-copyable 
     */
    ArraySolver(ArraySolver&&);
    ArraySolver& operator=(ArraySolver&&);

    /**
    @brief Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You mayassume that each input would have exactly one solution, and you may not use the same element twice.
    https://leetcode.com/problems/two-sum/description/
    @return two indices
    @param nums array of integers
    @param target two sum target
    */ 
    virtual std::vector<int> twoSum(const std::vector<int>& nums, int target) const noexcept;

    /**
    @brief Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
    Find all unique triplets in the array which gives the sum of zero.
    https://leetcode.com/problems/3sum/description/
    @return array of triplets sum to target
    @param nums array of integers
    @param target three sum target
    */ 
    virtual std::vector<std::vector<int>> threeSum(std::vector<int>& nums, int target) const noexcept;

    /**
    @brief Given an array nums of n heights, find two heights that can contain most water.
    https://leetcode.com/problems/container-with-most-water/
    @return max area
    @param array of heights
    */ 
    virtual int maxArea(std::vector<int>& height) const noexcept;

private:
    struct Impl;
    /**
     * @brief Pimpl design
     */
    std::unique_ptr<Impl, void(*)(Impl*)> m_impl;
};

} // LS

