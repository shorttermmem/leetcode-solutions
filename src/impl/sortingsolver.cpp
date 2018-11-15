
#include <string>
#include <functional>
#include <algorithm>
#include <glog/logging.h>

#include "sortingsolver.h"

using namespace LS;
using namespace std;

struct SortingSolver::Impl{

    int findKthLargest(std::vector<int>& nums, int k)
    {
        if(nums.size() < k) 
                throw std::out_of_range("K is out of range.");

        std::function<void (std::vector<int>&, int)> max_heapify = [&](std::vector<int>& nums, int i){
            #define LEFT(cur)   (cur*2 + 1)
            #define RIGHT(cur)  (cur*2 + 2)
            
            int l = LEFT(i);
            int r = RIGHT(i);

            int largest = i;

            if (l < nums.size() && nums[l] > nums[i])
            {
                largest = l;
            }

            if (r < nums.size() && nums[r] > nums[largest])
            {
                largest = r;
            }

            if (largest != i)
                std::swap(nums[i], nums[largest]);
        };     

        std::function<int (std::vector<int>&)> extract_max = [&](std::vector<int>& nums){
           
            for(int i = (int)nums.size()/2 ; i >= 0; --i)
            {
                max_heapify(nums, i);
            }
            return nums.front();
        };
        
        for(int i = 1; i < k; ++i)
        {
            extract_max(nums);
            
            std::swap(nums[0], nums[nums.size()-1]);
            nums.pop_back();
        }

        return extract_max(nums);
    }

}; // SortingSolver::Impl

SortingSolver::SortingSolver() : m_impl(
    new Impl(), 
    [](Impl *impl) { delete impl; }
)
{}

int SortingSolver::findKthLargest(std::vector<int>& nums, int k) const noexcept
{
    return m_impl->findKthLargest(nums, k);
}
