cmake_minimum_required(VERSION 3.19)
project(L5)

set(CMAKE_CXX_STANDARD 14)


add_executable(L5
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
