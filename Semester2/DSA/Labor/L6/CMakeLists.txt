cmake_minimum_required(VERSION 3.19)
project(L6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(L6
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h SMMKIterator.cpp SMMKIterator.h)
