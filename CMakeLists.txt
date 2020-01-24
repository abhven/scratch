cmake_minimum_required(VERSION 3.5.1)
  
set(CMAKE_CXX_STANDARD 14)

project(scratch)

add_executable(matrix_test src/matrix/matrix_test.cpp src/matrix/matrix.cpp)

add_executable(ticket_test src/train_tickets/ticket.cpp)

add_executable(virus_test src/virus_world/virus_world.cpp)
