cmake_minimum_required(VERSION 3.26)
project(LinkListC2 C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkListC2 main.c
        LinkList.h
        LinkList.c)
