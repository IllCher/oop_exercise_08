cmake_minimum_required(VERSION 3.0)
project(oop_exercise_08)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(oop_exercise_08 main.cpp figure.h point.h point.cpp figure.cpp triangle.cpp triangle.h quadrate.cpp quadrate.h octagon.cpp octagon.h factory.cpp factory.h processor.cpp processor.h subscriber.cpp subscriber.h)
enable_testing()

#add_test(FirstTest for_test 10 5)
