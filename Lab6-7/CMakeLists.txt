cmake_minimum_required(VERSION 3.15)
project(Lab6_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab6_7 main.cpp Domain/Application.cpp Domain/Application.h Repository/MapRepository.cpp
        Repository/MapRepository.h Service/ApplicationService.cpp
        Service/ApplicationService.h UI/Console.cpp UI/Console.h Repository/FileRepository.cpp
        Repository/FileRepository.h Tests/Tests.h Tests/Tests.cpp)
