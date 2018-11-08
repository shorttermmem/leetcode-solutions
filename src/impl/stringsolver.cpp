
#include <string>
#include <algorithm>

#include <glog/logging.h>

#include "stringsolver.h"

using namespace LS;
using namespace std;

struct StringSolver::Impl{

    std::string longestPalindrome(const std::string& str){
            
        
        return string{"abcdcba"};
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
