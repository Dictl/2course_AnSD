cmake_minimum_required(VERSION 3.30)
project(un6_lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(un6_lab2 main.cpp
        my_list.cpp
        my_list.h
        timsort.cpp
        timsort.h
        Stack.cpp
        Stack.h)
