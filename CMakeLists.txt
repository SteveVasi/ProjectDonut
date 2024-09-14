cmake_minimum_required(VERSION 3.20)
project(donut C)

set(CMAKE_C_STANDARD 99)

add_executable(donut main.c math/matrix.h math/matrix.c
        buffer.c
        buffer.h
        buffer.c
        math/vector2.h
        screen.h
        screen.c
        math/vector2.c
        math/vector3.h)

target_link_libraries(donut)
