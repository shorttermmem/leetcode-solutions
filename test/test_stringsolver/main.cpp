#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gmock/gmock.h>

#include "factory.h"
#include "stringsolver.h"

using namespace std;

LS::StringSolver* g_solutions = nullptr;

static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

TEST(BasicCase, test1)
{   
    static std::vector<std::pair<string, string>> tests = {
        {"abcdcba", "abcdcba"},
        {"abcd112", "11"},
        {"aacdbbb", "bbb"},
        {"abcd", "a"},
        {"a", "a"}
    };
   
    for(auto test : tests)
    {
        auto output = g_solutions->longestPalindrome(test.first);
        EXPECT_TRUE(
            (test.second == output)
        );
    }  
}

int main(int argc, char** argv){

    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    google::SetCommandLineOption("GLOG_minloglevel", "2");
    testing::InitGoogleTest(&argc, argv);

    LS::Factory* factory = nullptr;
    LS_RESULT res = LSInit(LS_FULL_VERSION, &factory);
    LS::ISolver* solver = nullptr;
    factory->CreateSolver(LS::StringSolverType, &solver);
    g_solutions = (LS::StringSolver*)solver;

    return RUN_ALL_TESTS();
}
