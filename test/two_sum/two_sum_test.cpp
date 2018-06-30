#include <gtest/gtest.h>
#include "two_sum.h"

#include <iostream>

using namespace std;

static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();


TEST(BasicCase, test1)
{
    solution::TwoSum twoSum;
    
    vector<int> input{1,2,3,4,5,6};
    
    auto output = twoSum.find(input, 8);

    EXPECT_TRUE(
        (output == vector<int>{2,4})
        );
}