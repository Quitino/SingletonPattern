cmake_minimum_required(VERSION 3.2)

PROJECT(singleton_demo_51)

INCLUDE_DIRECTORIES(
include
)

add_executable(singleton_demo_51 main.cpp sing.cpp)
