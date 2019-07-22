#include "common.h"
#include "factory.h"
#include "dpsolver.h"

using namespace std;

LS::DPSolver* g_solutions = nullptr;

static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

TEST(BasicCase, longestParlindrome)
{   
    vector<LS_size> weights{2,3,1,4};
    vector<LS_size> profits{4,5,3,7};
    LS_size capacity = 5;
    auto output = g_solutions->knapsackBasic(weights, profits, capacity);

    EXPECT_TRUE(
        (10 == output)
    );
}

int main(int argc, char** argv){

    google_env_setup(argc, argv);

    LS::Factory* factory = nullptr;
    LS_RESULT res = LSInit(LS_FULL_VERSION, &factory);
    LS::ISolver* solver = nullptr;
    factory->CreateSolver(LS::DPSolverType, &solver);
    g_solutions = (LS::DPSolver*)solver;

    int test_res = 0;
    if(FLAGS_test)
        test_res = ::RUN_ALL_TESTS();

    if(FLAGS_bench && 0 == test_res)
        ::benchmark::RunSpecifiedBenchmarks();
                                
    return test_res;
}
