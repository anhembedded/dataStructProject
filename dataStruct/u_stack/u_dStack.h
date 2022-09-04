/**
 * @file u_dStack.h
 * @author TranHoangAnh (anh.embedded@gamil.com)
 * @brief
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DATASTRUCTPROJECT_U_DSTACK_H
#define DATASTRUCTPROJECT_U_DSTACK_H

#include "u_linkedList/u_sLinkedList.h"

 // the pos-fix of this module is dStack

typedef node_data_T dStack_data_T;
typedef sList_obj_T dStack_list_T;
typedef node_obj_T dStack_node_T;
typedef node_obj_T* dStack_iterator_T;

extern const uint32_t dStack_emptyStack;
extern const dStack_data_T dStack_outOfSize;
/*PUBLIC properties */
typedef struct dStack_obj
{
    uint32_t top;
    uint32_t capacity;
    dStack_list_T data;
}dStack_obj_T;

/* Constructor and Destructor */

void dStack_constructor(dStack_obj_T* this_, uint32_t capacityParam);
void dStack_destructor(dStack_obj_T* this_);
/* Public Methods */

pdBool dStack_isEmpty(dStack_obj_T* this_);
pdBool dStack_isFull(dStack_obj_T* this_);
uint32_t dStack_count(dStack_obj_T* this_);
dStack_data_T dStack_Top(dStack_obj_T* this_);
void dStack_push(dStack_obj_T* this_, dStack_data_T newData);
dStack_data_T dStack_pop(dStack_obj_T* this_);
/* Overloading operator */
/* static method */
#endif //DATASTRUCTPROJECT_U_DSTACK_H
