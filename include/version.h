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


/**
***************************************************************************************************
* @file  Version.h
* @brief Version declaration
***************************************************************************************************
*/
#pragma once

#include "platform.h"

#define LS_MAKE_FULL_VERSION(VERSION_MAJOR, VERSION_MINOR, VERSION_RELEASE, VERSION_BUILD_NUM)    ( ((LS_uint64)(VERSION_MAJOR) << 48ull) | ((LS_uint64)(VERSION_MINOR) << 32ull) | ((LS_uint64)(VERSION_RELEASE) << 16ull)  | (LS_uint64)(VERSION_BUILD_NUM))

#define LS_GET_MAJOR_VERSION(x)      ((x >> 48ull) & 0xFFFF)
#define LS_GET_MINOR_VERSION(x)      ((x >> 32ull) & 0xFFFF)
#define LS_GET_SUBMINOR_VERSION(x)   ((x >> 16ull) & 0xFFFF)
#define LS_GET_BUILD_VERSION(x)      ((x >>  0ull) & 0xFFFF)

#define LS_VERSION_MAJOR       0
#define LS_VERSION_MINOR       0
#define LS_VERSION_RELEASE     1
#define LS_VERSION_BUILD_NUM   0

#define LS_FULL_VERSION LS_MAKE_FULL_VERSION(LS_VERSION_MAJOR, LS_VERSION_MINOR, LS_VERSION_RELEASE, LS_VERSION_BUILD_NUM)

