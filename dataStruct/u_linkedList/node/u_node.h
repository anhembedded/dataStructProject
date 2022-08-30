/**
 * @file u_node.h
 * @author Tran Hoang Anh (anh.embedded@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-30
 * 
 * 
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
pdBool node_isTheSame(node_obj_T* this_, node_obj_T* otherNode);
pdBool node_greater(node_obj_T* firstOperand, node_obj_T* secondOperand);
pdBool node_smaller(node_obj_T* firstOperand, node_obj_T* secondOperand);
pdBool node_smallerOrEqual(node_obj_T* firstOperand, node_obj_T* secondOperand);
pdBool node_greaterOrEqual(node_obj_T* firstOperand, node_obj_T* secondOperand);
#endif // DATASTRUCTPROJECT_U_NODE_H
