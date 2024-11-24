cmake_minimum_required(VERSION 3.29)
project(niemiec)

set(CMAKE_CXX_STANDARD 20, CMAKE_CXX_FLAGS "-O3")

add_executable(niemiec
        boyre-moore/boyremoore.cpp
#        distance/levensthein.cpp

)
