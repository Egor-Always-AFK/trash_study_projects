cmake_minimum_required(VERSION 3.20)
project(rep_for_small_projects)

set(CMAKE_CXX_STANDARD 20)

add_executable(rep_for_small_projects main.cpp
        Node.hpp
        BST.hpp
        ../test/NodeTest.cpp)
