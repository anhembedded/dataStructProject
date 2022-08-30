cmake_minimum_required(VERSION 3.23)
project(dataStructProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)



add_executable(dataStructProject main.cpp dataStruct/u_linkedList/node/u_node.c dataStruct/u_linkedList/node/u_node.h dataStruct/u_linkedList/u_sLinkedList.c dataStruct/u_linkedList/u_sLinkedList.h dataStruct/u_stack/u_dStack.c dataStruct/u_stack/u_dStack.h dataStruct/u_queue/u_dQueue.c dataStruct/u_queue/u_dQueue.h dataStruct/u_graph/u_dGraph.c dataStruct/u_graph/u_dGraph.h)
include_directories(dataStruct)