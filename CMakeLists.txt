cmake_minimum_required(VERSION 3.20)
project(donut C)

set(CMAKE_C_STANDARD 99)

add_executable(donut main.c matrix.h matrix.c
        z_buffer.c
        z_buffer.h
        z_buffer.c)

target_link_libraries(donut)
