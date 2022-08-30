/**
 * @file u_dQueue.h
 * @author Tran Hoang Anh (anh.embedded@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-30
 *
 *
 */

#ifndef DATASTRUCTPROJECT_U_DQUEUE_H
#define DATASTRUCTPROJECT_U_DQUEUE_H
#include "u_linkedList/u_sLinkedList.h"

typedef node_data_T dQueue_data_T;
typedef sList_obj_T dQueue_list_T;
typedef node_obj_T dQueue_node_T;
typedef node_obj_T* dQueue_iterator_T;

/*PUBLIC properties */
typedef struct dQueue_obj
{
    sList_obj_T data;
}dQueue_obj_T;

/* Constructor and Destructor */

void dQueue_constructor(dQueue_obj_T * this_);
void dQueue_destructor(dQueue_obj_T* this_);
/* Public Methods */

pdBool  dQueue_isEmpty(dQueue_obj_T * this_);
void dQueue_push(dQueue_obj_T * this_, dQueue_data_T newData);
dQueue_data_T dQueue_pop(dQueue_obj_T *this_);
uint32_t  dQueue_size(dQueue_obj_T *this_);

/* Overloading operator */
/* static method */

#endif //DATASTRUCTPROJECT_U_DQUEUE_H
