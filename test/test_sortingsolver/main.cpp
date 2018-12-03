#include <iostream>
#include <tuple>
#include <vector>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gmock/gmock.h>

#include "factory.h"
#include "sortingsolver.h"

using namespace std;

LS::SortingSolver* g_solutions = nullptr;

static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

TEST(BasicCase, test1)
{   
    using TestCase = std::tuple< std::vector<int>, int, int>;
    static std::vector< TestCase > tests {
        TestCase{
            {0}, 1, 0
        },
        TestCase{ 
            {1,2,3}, 2, 2
        },
        TestCase{
            {3,2,1}, 3, 1 
        },
        TestCase{
            {5,9,1,2,6}, 1, 9
        },
        TestCase{
            {5,9,1,2,6}, 5, 1
        }
    };
   
    for(auto test : tests)
    {
        auto local = std::get<0>(test);

        auto output = g_solutions->findKthLargest(std::get<0>(test), std::get<1>(test));
        EXPECT_TRUE(
            (std::get<2>(test) == output)
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
    factory->CreateSolver(LS::SortingSolverType, &solver);
    g_solutions = (LS::SortingSolver*)solver;

    return RUN_ALL_TESTS();
}
