cmake_minimum_required(VERSION 3.10)

project(KutuphaneProjesi LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(library_app
    src/main.cpp
    src/Book.cpp
    src/Inventory.cpp
)
