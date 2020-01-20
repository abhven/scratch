cmake_minimum_required(VERSION 3.5.1)
  
set(CMAKE_CXX_STANDARD 14)

project(scratch)

add_executable(matrix_test src/matrix_test.cpp src/matrix.cpp)