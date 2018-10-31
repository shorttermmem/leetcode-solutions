
#include <string>
#include <unordered_map>
#include <algorithm>

#include <glog/logging.h>

#include "arraysolver.h"

using namespace LS;
using namespace std;

struct ArraySolver::Impl{

    std::vector<int> twoSum1(const std::vector<int>& nums, int target){
            
        unordered_map<int, int> saved_diff;
        saved_diff.reserve(nums.size());
        
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            LOG(INFO) << "Exam: " << nums[i] << "@"<< i;
            int diff = target - nums[i];
            LOG(INFO) << "Diff: " << diff;

            auto iter = saved_diff.find(diff);
            if (iter != saved_diff.end())
            {
                LOG(INFO) << "Found solution!";
                return vector<int>{ iter->second, (int)i };
            }
            
            LOG(INFO) << "Not Found and store: " << nums[i] << " - " << i; 
            saved_diff[nums[i]] = i;   
        }
        
        LOG(INFO) << "Not solution"; 
        return vector<int>{};
    }

    std::vector<std::vector<int>> threeSum1(vector<int>& nums, int target){
            
        std::vector<vector<int>> res{};
        std::sort(nums.begin(),nums.end(), std::less<int>());    
        int N = (int)nums.size();
        
        for (int i = 0; i < N; ++i)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int target_ = nums[i] * (-1) + target;
            int start = i+1;
            int end = N-1;
            
            LOG(INFO) << "Start: " << start << " end: " << end;
            while (start < end){
                
                LOG(INFO) << "Check: " << nums[i] << nums[start] << nums[end];
                if (nums[start] + nums[end] == target_)
                {
                    //Found one
                    res.emplace_back( std::vector<int>{nums[i], nums[start], nums[end]} );
                    LOG(INFO) << "Found: " << nums[i] << nums[start] << nums[end];
                    
                    // Exhaust non-unique triplets
                    do{
                        start++;
                    }while (start < end && nums[start] == nums[start -1 ]);
                }
                else if (nums[start] + nums[end] < target_)
                    start++;
                else
                    end--;
            }
        }
        return res;
    };
}; // ArraySolver::Impl

ArraySolver::ArraySolver() : m_impl(
    new Impl(), 
    [](Impl *impl) { delete impl; }
)
{}

std::vector<int> ArraySolver::twoSum(const std::vector<int>& nums, int target) const noexcept
{
    return m_impl->twoSum1(nums, target);
}

std::vector<std::vector<int>>  ArraySolver::threeSum(std::vector<int>& nums, int target) const noexcept
{
    return m_impl->threeSum1(nums, target);
}