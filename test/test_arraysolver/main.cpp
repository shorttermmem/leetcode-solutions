#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

#include "factory.h"
#include "arraysolver.h"

using namespace std;

namespace{
struct Incrementor {
    Incrementor(int start = 0, int step = 1) : _start(start), _step(step) { }
    int operator()() { return _start+=_step; }
    int _start;
    int _step;
};
}

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

static void BM_BasicCase(benchmark::State& state) {
  
  vector<int> input(6, 0);
  std::generate(input.begin(), input.end(), Incrementor(1,1)); // elements are set to 1
  
  std::vector<int> res{};
  for (auto _ : state) 
  {
    res = g_solutions->twoSum(input, 8);
  }  
  // Prevent compiler optimizations
  std::stringstream ss;
  ss << res.size();
  state.SetLabel(ss.str());
}
BENCHMARK(BM_BasicCase);
BENCHMARK(BM_BasicCase)->UseRealTime();
BENCHMARK(BM_BasicCase)->ThreadPerCpu();

int main(int argc, char** argv){

    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    google::SetCommandLineOption("GLOG_minloglevel", "2");
    testing::InitGoogleTest(&argc, argv);

    LS::Factory* factory = nullptr;
    LS_RESULT res = LSInit(LS_FULL_VERSION, &factory);
    LS::ISolver* solver = nullptr;
    factory->CreateSolver(LS::ArraySolverType, &solver);
    g_solutions = (LS::ArraySolver*)solver;
    
    int test_res = RUN_ALL_TESTS();
    if(test_res == 0)
    {
        ::benchmark::Initialize(&argc, argv); 
        if (::benchmark::ReportUnrecognizedArguments(argc, argv)) 
            return 1;
        ::benchmark::RunSpecifiedBenchmarks();
    }
                                
    return test_res;
}
