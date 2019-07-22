#ifndef __COMMON_H
#define __COMMON_H

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

DEFINE_bool(test, false, "enable/disable running all tests");
DEFINE_bool(bench, false, "enable/disable running all benchmarks");

static void google_env_setup(int argc, char** argv)
{
    /// argv[0] is app name
    google::InitGoogleLogging(argv[0]);
    
    /// parse gtest args
    testing::InitGoogleTest(&argc, argv);

    /// parse googlebench args
    ::benchmark::Initialize(&argc, argv); 
    ::benchmark::ReportUnrecognizedArguments(argc, argv);
    
    /// parse and remove all custom args
    google::ParseCommandLineFlags(&argc, &argv, true);
}

#endif