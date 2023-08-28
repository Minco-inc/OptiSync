cmake_minimum_required(VERSION 3.10)

project(OptiComm)

# cpp
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp )

add_library(OptiComm STATIC ${SOURCES})

target_include_directories(OptiComm PUBLIC src)


add_subdirectory(evpp)
target_link_libraries(OptiComm evpp_static)
target_include_directories(OptiComm PUBLIC evpp)
