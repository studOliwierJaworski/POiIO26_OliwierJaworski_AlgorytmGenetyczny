cmake_minimum_required(VERSION 4.2)
project(AlgorytmGenetyczny)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorytmGenetyczny main.cpp
        TParam.h
        TParam.cpp
        TCandidate.h
        TCandidate.cpp)
