cmake_minimum_required(VERSION 3.15)
project(Lab4_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4_5 App.cpp Tests/Tests.cpp Tests/Tests.h Domain/GymExercise.cpp Domain/GymExercise.h
        Repository/ArrayRepository.cpp Repository/ArrayRepository.h Service/GymExerciseService.cpp
        Service/GymExerciseService.h UI/Console.cpp UI/Console.h)
