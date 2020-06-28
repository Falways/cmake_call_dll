cmake_minimum_required(VERSION 3.16)
project(cmake_call_dll)

set(CMAKE_CXX_STANDARD 14)
set(BUILD_ARCH "-m64")
add_executable(cmake_call_dll main.cpp)