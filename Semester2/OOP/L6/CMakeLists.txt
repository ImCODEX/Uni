cmake_minimum_required(VERSION 3.19)
project(L6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(L6
        application.cpp
        Cars.cpp
        Cars.h
        Controller.cpp
        Controller.h
        CRUD_Repository.h
        Error.cpp
        Error.h
        Repo.cpp
        Repo.h
        UI.cpp
        UI.h
        Users.cpp
        Users.h)
