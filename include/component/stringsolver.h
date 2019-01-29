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

namespace LS{ 

class StringSolver : public ISolver{
public:
    StringSolver();

    /**
     * @brief Movable and non-copyable 
     */
    StringSolver(StringSolver&&);
    StringSolver& operator=(StringSolver&&);

    /**
    @brief Given a string, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
    https://leetcode.com/explore/interview/card/amazon/76/array-and-strings/489/
    @return longest palindrome
    @param source string
    */ 
    virtual std::string longestPalindrome(const std::string& str) const noexcept;

    /**
    @brief Given a string of roman chars "Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.".
    https://leetcode.com/problems/roman-to-integer/
    @return int value
    @param string of roman chars
    */ 
    virtual int romanToInt(const std::string& str) const noexcept;

private:
    struct Impl;
    /**
     * @brief Pimpl design
     */
    std::unique_ptr<Impl, void(*)(Impl*)> m_impl;
};

} // LS

