cmake_minimum_required(VERSION 4.0)
project(CachingCppBugExample)

set(CMAKE_CXX_STANDARD 23)

add_executable(CachingCppBugExample main.cpp
        Player.cpp
        Player.h
        Health.cpp
        Health.h)
