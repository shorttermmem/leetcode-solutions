#include <string>
#include <unordered_map>
#include "two_sum.h"

using namespace solution;
using namespace std;

vector<int> TwoSum::find(const vector<int>& nums, int target) {
        
    unordered_map<int, int> saved_diff;
    saved_diff.reserve(nums.size());
    
    for (unsigned int i = 0; i < nums.size(); ++i)
    {
        int diff = target - nums[i];
        auto iter = saved_diff.find(diff);
        
        if (iter != saved_diff.end())
            return vector<int>{ iter->second, (int)i };
            
        saved_diff[nums[i]] = i;   
    }
    
    return vector<int>{};
};

