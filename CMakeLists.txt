cmake_minimum_required(VERSION 3.23)
project(dataStructProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_executable(dataStructProject main.cpp dataStruct/u_linkedList/node/u_node.c dataStruct/u_linkedList/node/u_node.h dataStruct/u_linkedList/u_sLinkeList.c dataStruct/u_linkedList/u_sLinkeList.h)
