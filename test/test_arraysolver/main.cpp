#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gmock/gmock.h>

#include "factory.h"
#include "arraysolver.h"

using namespace std;

LS::ArraySolver* g_solutions = nullptr;

static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    cin.tie(NULL);
    return 0;
}();

TEST(BasicCase, test1)
{   
    vector<int> input{1,2,3,4,5,6};
    
    auto output = g_solutions->twoSum(input, 8);

    EXPECT_TRUE(
        (output == vector<int>{2,4})
    );
   
}

int main(int argc, char** argv){

    cout << "hello" <<endl;
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    testing::InitGoogleTest(&argc, argv);

    LS::Factory* factory = nullptr;
    LS_RESULT res = LSInit(LS_FULL_VERSION, &factory);
    LS::ISolver* solver = nullptr;
    factory->CreateSolver(LS::ArraySolverType, &solver);
    g_solutions = (LS::ArraySolver*)solver;
    
    return RUN_ALL_TESTS();
}
