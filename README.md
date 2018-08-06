# leetcode-solutions
[![Build Status](https://travis-ci.org/shorttermmem/leetcode-solutions.svg?branch=master)](https://travis-ci.org/shorttermmem/leetcode-solutions)
[![Build status](https://ci.appveyor.com/api/projects/status/q5u3egroej92iakg/branch/master?svg=true)](https://ci.appveyor.com/project/shorttermmem/leetcode-solutions/branch/master)
[![Coverage Status](https://coveralls.io/repos/github/shorttermmem/leetcode-solutions/badge.svg?branch=master)](https://coveralls.io/github/shorttermmem/leetcode-solutions?branch=master)


## Building

The basic steps for configuring and building the library look like this:

```bash
$ git clone https://github.com/shorttermmem/leetcode-solutions.git
$ mkdir build && cd build
$ cmake  -G <generator> [options] ..
```

By default, this project is managed by hunter package manager. The configuration process of CMake will automatically download, build and install project dependencies: glog, gflags, gtest, gmock and benchmark.

### Happy Hacking!
