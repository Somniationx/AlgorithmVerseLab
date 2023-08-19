cmake_minimum_required(VERSION 3.26)
project(DynSeqCppImpl)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynSeqCppImpl main.cpp
        SeqList.hpp)
