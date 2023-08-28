cmake_minimum_required(VERSION 3.10)

project(OptiSync)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(OptiSync ${SOURCES})

add_subdirectory(OptiComm)
target_link_libraries(OptiSync OptiComm)
target_include_directories(OptiSync PUBLIC OptiComm/src)

# link x11
find_package(X11 REQUIRED)
target_link_libraries(OptiSync ${X11_LIBRARIES})
target_include_directories(OptiSync PUBLIC ${X11_INCLUDE_DIR})
