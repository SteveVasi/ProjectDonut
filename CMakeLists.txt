cmake_minimum_required(VERSION 3.10)
project(ProjectDonut C)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCES "*.c")

list(FILTER SOURCES EXCLUDE REGEX ".*/cmake-build.*/.*")


add_executable(main ${SOURCES})

target_include_directories(main PRIVATE . math)
target_link_libraries(main m pthread rt)