cmake_minimum_required(VERSION 3.15)
project(Lab4_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab4_5 App.cpp Domain/GymExercise.cpp Domain/GymExercise.h Repository/RepositorySTL.cpp
        Repository/RepositorySTL.h Tests/Tests.cpp Tests/Tests.h Service/GymExerciseService.cpp
        Service/GymExerciseService.h UI/Console.cpp UI/Console.h)
