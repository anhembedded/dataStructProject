/**
  ******************************************************************************
  * @file    u_node.h
  * @author  TranHoangAnh
  * @brief
  *
  ==============================================================================
                        ##### NODE Class #####
  ==============================================================================
  */
#ifndef DATASTRUCTPROJECT_U_NODE_H
#define DATASTRUCTPROJECT_U_NODE_H
#include <stdint.h>

typedef  size_t pdBool;

typedef uint32_t node_data_T;
extern const node_data_T node_dataInit;


typedef struct u_node_obj
{
  node_data_T data;
  struct u_node_obj* next;
} node_obj_T;

/* Constructor and Destructor */
void node_constructor(node_obj_T* this_);
void node_constructorInitData(node_obj_T* this_, node_data_T newData);
void node_destructor(node_obj_T* this_);
/* Public Methods */

/* Overloading operator */
pdBool node_compare(node_obj_T* this_, node_obj_T* otherNode);

#endif // DATASTRUCTPROJECT_U_NODE_H
