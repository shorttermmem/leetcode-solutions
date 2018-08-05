#include <iostream>

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <gmock/gmock.h>

#include "factory.h"
#include "arrays.h"

using namespace std;
using namespace ZZ;

static unique_ptr<Arrays> g_solutions{};

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
    
   // auto output = solution::find(input, 8);

   // EXPECT_TRUE(
   //     (output == vector<int>{2,4})
   //     );
   
}

int main(int argc, char **argv){

    google::ParseCommandLineFlags(&argc, &argv, true);
    google::InitGoogleLogging(argv[0]);
    testing::InitGoogleTest(&argc, argv);

    ZZFactory* factory = nullptr;
    ZZ_RESULT res = ZZInit(ZZ_FULL_VERSION, &factory);

   // factory->CreateArrays(&(g_solutions.get());

    return RUN_ALL_TESTS();
}
