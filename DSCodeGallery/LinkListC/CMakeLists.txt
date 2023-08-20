cmake_minimum_required(VERSION 3.26)
project(LinkList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkList main.c
        LinkList.h
        LinkList.c)
