cmake_minimum_required(VERSION 3.10)
project(vemu CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vemu
    main.cpp
    vemu/cpu.cpp
    vemu/memory.cpp
    vemu/decoder.cpp
)

target_include_directories(vemu PRIVATE vemu)
