cmake_minimum_required(VERSION 3.24)
project(Part_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Part_1 main.cpp md5.h md5.cpp)

