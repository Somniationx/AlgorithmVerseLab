cmake_minimum_required(VERSION 3.26)
project(DynSeqCImpl C)

set(CMAKE_C_STANDARD 11)

add_executable(DynSeqCImpl main.c SeqList.c SeqList.h)
