cmake_minimum_required(VERSION 3.0)

project("test")

enable_testing()
add_executable(test_app BstTest.cpp)
target_link_libraries(test_app gtest gmock pthread)