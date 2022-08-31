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




typedef struct u_node_obj
{
  node_data_T data;
  struct u_node_obj* next;
} node_obj_T;

const node_data_T node_dataInit = 0;

/* Constructor and Destructor */
static void node_constructor(node_obj_T* this_);
static void node_constructorInitData(node_obj_T* this_, node_data_T newData);
static void node_destructor(node_obj_T* this_);
/* Public Methods */

/* Overloading operator */
static pdBool node_isTheSame(node_obj_T* this_, node_obj_T* otherNode);
static pdBool node_greater(node_obj_T* firstOperand, node_obj_T* secondOperand);
static pdBool node_smaller(node_obj_T* firstOperand, node_obj_T* secondOperand);
static pdBool node_smallerOrEqual(node_obj_T* firstOperand, node_obj_T* secondOperand);
static pdBool node_greaterOrEqual(node_obj_T* firstOperand, node_obj_T* secondOperand);







void node_constructor(node_obj_T* this_)
{
    this_->data = node_dataInit;
    this_->next = NULL;
}

void node_constructorInitData(node_obj_T* this_, node_data_T newData)
{
    node_constructor(this_);
    this_->data = newData;
}

void node_destructor(node_obj_T* this_)
{
    //todo: implement that!!;
    (void)this_;
}

pdBool node_isTheSame(node_obj_T* this_, node_obj_T* otherNode)
{
    pdBool res = 0;
    if (this_->data == otherNode->data)
    {
        res = 1;
    }
    return res;
}
#endif // DATASTRUCTPROJECT_U_NODE_H
