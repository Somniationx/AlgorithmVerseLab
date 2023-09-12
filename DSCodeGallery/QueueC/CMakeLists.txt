cmake_minimum_required(VERSION 3.26)
project(QueueC C)

set(CMAKE_C_STANDARD 11)

add_executable(QueueC main.c
        Queue.h
        Queue.c)
