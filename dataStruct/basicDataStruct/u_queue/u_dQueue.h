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
#include "basicDataStruct/u_linkedList/u_sLinkedList.h"

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

static void dQueue_constructor(dQueue_obj_T * this_);
static void dQueue_destructor(dQueue_obj_T* this_);
/* Public Methods */

static pdBool  dQueue_isEmpty(dQueue_obj_T * this_);
static void dQueue_push(dQueue_obj_T * this_, dQueue_data_T newData);
static  dQueue_data_T dQueue_pop(dQueue_obj_T *this_);
static uint32_t  dQueue_size(dQueue_obj_T *this_);

/* Overloading operator */

/* static method */


static void dQueue_constructor(dQueue_obj_T *this_) {
    sList_destructor(&this_->data);
}

static void dQueue_destructor(dQueue_obj_T *this_) {
    sList_destructor(&this_->data);
}

static pdBool dQueue_isEmpty(dQueue_obj_T *this_) {
    pdBool res = sList_isEmpty(&this_->data);
    return res;
}

static void dQueue_push(dQueue_obj_T *this_, dQueue_data_T newData) {
    sList_pushFront(&this_->data,newData);
}

static dQueue_data_T dQueue_pop(dQueue_obj_T *this_) {
    return sList_popBack(&this_->data);
}

static uint32_t dQueue_size(dQueue_obj_T *this_) {
    return sList_size(&this_->data);
}



#endif //DATASTRUCTPROJECT_U_DQUEUE_H
