#include <benchmark/benchmark.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>

#if defined(__GNUC__)
#define BENCHMARK_NOINLINE __attribute__((noinline))
#else
#define BENCHMARK_NOINLINE
#endif

namespace {
std::set<int> ConstructRandomSet(int size) {
  std::set<int> s;
  for (int i = 0; i < size; ++i) s.insert(s.end(), i);
  return s;
}

int BENCHMARK_NOINLINE Factorial(uint32_t n) {
  return (n == 1) ? 1 : n * Factorial(n - 1);
}

int RandomNumber(){
    return std::rand();
}
}  // end namespace

static void BM_Factorial(benchmark::State& state) {
  int fac_42 = 0;
  for (auto _ : state) fac_42 = Factorial(8);
  // Prevent compiler optimizations
  std::stringstream ss;
  ss << fac_42;
  state.SetLabel(ss.str());
}
BENCHMARK(BM_Factorial);
BENCHMARK(BM_Factorial)->UseRealTime();
BENCHMARK(BM_Factorial)->Threads(8);
BENCHMARK(BM_Factorial)->ThreadRange(1, 32);
BENCHMARK(BM_Factorial)->ThreadPerCpu();

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
BENCHMARK(BM_StringCreation);

static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

static void BM_memcpy(benchmark::State& state) {
  char* src = new char[state.range(0)];
  char* dst = new char[state.range(0)];
  memset(src, 'x', state.range(0));
  for (auto _ : state)
    memcpy(dst, src, state.range(0));
  state.SetBytesProcessed(int64_t(state.iterations()) *
                          int64_t(state.range(0)));
  delete[] src;
  delete[] dst;
}
BENCHMARK(BM_memcpy)->RangeMultiplier(2)->Range(8, 8<<10);

static void BM_SetInsert(benchmark::State& state) {
  std::set<int> data;
  for (auto _ : state) {
    state.PauseTiming();
    data = ConstructRandomSet(state.range(0));
    state.ResumeTiming();
    for (int j = 0; j < state.range(1); ++j)
      data.insert(RandomNumber());
  }
}
//BENCHMARK(BM_SetInsert)->Ranges({{1<<10, 8<<10}, {128, 512}});
BENCHMARK(BM_SetInsert)
    ->Args({1<<10, 128})
    ->Args({2<<10, 128})
    ->Args({4<<10, 128})
    ->Args({8<<10, 128})
    ->Args({1<<10, 512})
    ->Args({2<<10, 512})
    ->Args({4<<10, 512})
    ->Args({8<<10, 512});

static void BM_StringCompare(benchmark::State& state) {
  std::string s1(state.range(0), '-');
  std::string s2(state.range(0), '-');
  for (auto _ : state) {
    benchmark::DoNotOptimize(s1.compare(s2));
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_StringCompare)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

static void BM_MultiThreaded(benchmark::State& state) {
  if (state.thread_index == 0) {
    // Setup code here.
  }
  for (auto _ : state) {
    // Run the test as normal.
  }
  if (state.thread_index == 0) {
    // Teardown code here.
  }
}
BENCHMARK(BM_MultiThreaded)->Threads(2);

static void BM_vector_push_back(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> v;
    v.reserve(1);
    benchmark::DoNotOptimize(v.data()); // Allow v.data() to be clobbered.
    v.push_back(42);
    benchmark::ClobberMemory(); // Force 42 to be written to memory.
  }
}
BENCHMARK(BM_vector_push_back);

static void BM_MAD(benchmark::State& state) {
  int sum;
  for (auto _ : state)
    for (int i =0 ; i < 100000; ++i)
      benchmark::DoNotOptimize(sum += i);
}
BENCHMARK(BM_MAD);

BENCHMARK_MAIN();