cmake_minimum_required(VERSION 3.3)
project(tibco-oa)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(suite tests.cpp)
target_link_libraries(suite ${GTEST_LIBRARIES} pthread)