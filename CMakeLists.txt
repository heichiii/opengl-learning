cmake_minimum_required(VERSION 3.30)
project(gl_learning)

set(CMAKE_CXX_STANDARD 11)

# 指定库的路径
link_directories(libs)
# 添加头文件路径
include_directories(libs/includes
        components/includes)

add_executable(gl_learning main.cpp
        libs/glad.c
        components/utils.cpp)


target_link_libraries(gl_learning PRIVATE glfw3)
