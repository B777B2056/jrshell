cmake_minimum_required(VERSION 2.8)
project(jrshell)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c11")
aux_source_directory(../src SRC_LIST)
add_executable(jrshell ${SRC_LIST})

