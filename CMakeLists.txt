cmake_minimum_required(VERSION 3.10)
project(rvemu-lite CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rvemu-lite
    main.cpp
    rvemu/cpu.cpp
    rvemu/memory.cpp
    rvemu/decoder.cpp
)

target_include_directories(rvemu-lite PRIVATE rvemu)
