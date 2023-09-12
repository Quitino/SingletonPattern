cmake_minimum_required(VERSION 3.2)

PROJECT(singleton_demo_4)

INCLUDE_DIRECTORIES(
include
)

add_executable(singleton_demo_4 main.cpp sing.cpp)
