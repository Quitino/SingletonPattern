cmake_minimum_required(VERSION 3.2)

PROJECT(singleton_demo_1)

INCLUDE_DIRECTORIES(
include
)

add_executable(singleton_demo_1 main.cpp sing.cpp)
