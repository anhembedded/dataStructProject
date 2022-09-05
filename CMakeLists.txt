cmake_minimum_required(VERSION 3.23)
project(dataStructProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)



add_executable(dataStructProject main.cpp dataStruct/node/u_node.c dataStruct/node/u_node.h dataStruct/u_linkedList/u_sLinkedList.c dataStruct/u_linkedList/u_sLinkedList.h dataStruct/u_stack/u_dStack.c dataStruct/u_stack/u_dStack.h dataStruct/u_queue/u_dQueue.c dataStruct/u_queue/u_dQueue.h dataStruct/u_graph/u_dGraph.c
        dataStruct/u_graph/u_dGraph.h
        dataStruct/node/u_node.h
        dataStruct/node/u_node.c main.h mock2/mock2_main.c mock2/mock2_main.h dataOfTestingCase.c dataOfTestingCase.h)
include_directories(dataStruct)
include_directories(${MY_CURRENT_DIR}/)