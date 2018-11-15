
#include <string>
#include <functional>
#include <algorithm>
#include <glog/logging.h>

#include "stringsolver.h"

using namespace LS;
using namespace std;

struct StringSolver::Impl{

    std::string longestPalindrome1(const std::string& str){

        if(str.empty()) return "";
        
        size_t n = str.size();

        // n x n table, per entry means i..j is parlindrome
        std::vector<std::vector<bool>> isSubstrPar{n, std::vector<bool>(n)}; 

        // one letter is parlindrome
        int maxParLen = 1;
        for(auto i = 0; i < n; ++i) 
            isSubstrPar[i][i] = true;

        int maxParStart = 0;
        // two letters 
        for(auto i = 0; i < n-1; ++i)
        {
            if(str[i] == str[i+1])
            {
                isSubstrPar[i][i+1] = true;
                maxParStart = i;
                maxParLen = 2;
            }
        }

        // 2..k letters
        for(auto k = 3; k <=n; ++k)
            for(auto l = 0; l < n-k+1; ++l)
            {
                int r = l + k - 1;
                
                if(isSubstrPar[l+1][r-1] && str[l] == str[r])
                {
                    isSubstrPar[l][r] = true;
                    
                    if(k > maxParLen)
                    {
                        maxParStart = l;
                        maxParLen = k;
                    }
                }
            }

        return str.substr(maxParStart, maxParLen);   
    }

     std::string longestPalindrome2_failed(const std::string& str){
         std::function<string (string, int, int, string&)> recur = [&](string str, int l, int r, string& lps){
            string res{};

            while(l >= 0 && r < str.length())
            {
                if(str[l] == str[r])
                {
                    res = str.substr(l, r - l + 1);
            
                    if(res.length() > lps.length())
                        lps = res;
            
                    l++;
                    r--;
                }
                else
                {
                    break;
                }
            }
            return res;
        };  

        string lps{};
        for (int i =0; i<str.length(); ++i)
        {
            recur(str, 0, i, lps);
            recur(str, i-1, i, lps);
        }      
         return lps; 
     }

}; // StringSolver::Impl

StringSolver::StringSolver() : m_impl(
    new Impl(), 
    [](Impl *impl) { delete impl; }
)
{}

std::string StringSolver::longestPalindrome(const std::string& str) const noexcept
{
    return m_impl->longestPalindrome1(str);
}
