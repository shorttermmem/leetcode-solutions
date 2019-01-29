
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <glog/logging.h>

#include "stringsolver.h"

using namespace LS;
using namespace std;

struct StringSolver::Impl{

    std::string longestPalindrome(const std::string& str){
            
        
        return string{"abcdcba"};
    }

    int romanToInt(const std::string& str){

        std::unordered_map <char, int> dict { 
            { 'I', 1 }, 
            { 'V', 5 }, 
            { 'X', 10 }, 
            { 'L', 50 }, 
            { 'C', 100 }, 
            { 'D', 500 }, 
            { 'M', 1000 } 
        };
        
        int res = 0;
        int last = 0;
        for(auto iter = str.rbegin(); iter != str.rend(); ++iter)
        {
            auto&& it = dict.find(*iter);
            if(it == dict.end())
                break;
            
            int cur = it->second;
            
            //printf("%d",cur);
            //printf("[%d]", last);
            
            if (cur < last)
                res -= cur;
            else
                res += cur;
            
            last = cur;
        }
        return res;
    }

}; // StringSolver::Impl

StringSolver::StringSolver() : m_impl(
    new Impl(), 
    [](Impl *impl) { delete impl; }
)
{}

std::string StringSolver::longestPalindrome(const std::string& str) const noexcept
{
    return m_impl->longestPalindrome(str);
}

int StringSolver::romanToInt(const std::string& str) const noexcept
{
    return m_impl->romanToInt(str);
}