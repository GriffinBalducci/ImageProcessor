cmake_minimum_required(VERSION 3.26)
project(ImageProcessor)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImageProcessor main.cpp
        Image.cpp)
