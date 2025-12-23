cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC "${PROJECT_SOURCE_DIR}/source/src/*.cpp")
#file(GLOB_RECURSE INC "${PROJECT_SOURCE_DIR}/source/include/*.h")

add_executable(untitled ${SRC})
target_include_directories(untitled PUBLIC ${PROJECT_SOURCE_DIR}/source/include)
