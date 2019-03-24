cmake_minimum_required(VERSION 2.8)
set(CMAKE_BUILD_TYPE "debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

project(lc)

add_executable(lc src/catch.hpp src/lc.cpp src/leetcode.h src/tests-main.cpp)
