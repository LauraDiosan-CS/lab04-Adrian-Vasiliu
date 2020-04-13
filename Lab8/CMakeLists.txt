cmake_minimum_required(VERSION 3.15)
project(Lab8)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab8 main.cpp Domain/Order.cpp Domain/Order.h Domain/Food.cpp Domain/Food.h Domain/Shopping.cpp
        Domain/Shopping.h)
