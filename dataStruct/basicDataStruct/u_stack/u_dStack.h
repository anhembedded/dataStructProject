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

#include "basicDataStruct/u_linkedList/u_sLinkedList.h"

 // the pos-fix of this module is dStack

typedef node_data_T dStack_data_T;
typedef sList_obj_T dStack_list_T;
typedef node_obj_T dStack_node_T;
typedef node_obj_T* dStack_iterator_T;

const uint32_t dStack_emptyStack = UINT32_MAX;
const dStack_data_T dStack_outOfSize = UINT32_MAX;
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





/**
 * @brief
 *
 * @param this_
 * @param capacityParam
 */
void dStack_constructor(dStack_obj_T* this_, uint32_t capacityParam)
{
    sList_constructorSize(&this_->data, capacityParam);
    this_->capacity = capacityParam;
    this_->top = dStack_emptyStack;
}
/**
 * @brief
 *
 * @param this_
 */
void dStack_destructor(dStack_obj_T* this_) {
    sList_destructor(&this_->data);
    this_->top = 0U;
    this_->capacity = 0U;
}
/**
 * @brief
 *
 * @param this_
 * @return pdBool
 */
pdBool dStack_isEmpty(dStack_obj_T* this_) {
    pdBool  res = 0;
    if (this_->top == dStack_emptyStack)
    {
        res = 1;
    }
    return  res;
}
/**
 * @brief
 *
 * @param this_
 * @return pdBool
 */
pdBool dStack_isFull(dStack_obj_T* this_) {
    pdBool  res = 0;
    if (this_->top == this_->capacity - 1)
    {
        res = 1;
    }
    return  res;
}
/**
 * @brief
 *
 * @param this_
 * @return uint32_t
 */
uint32_t dStack_count(dStack_obj_T* this_) {
    uint32_t counter = this_->top + 1;
    return  counter;
}
/**
 * @brief
 *
 * @param this_
 * @return dStack_data_T
 */
dStack_data_T dStack_Top(dStack_obj_T* this_) {
    dStack_data_T res = dStack_outOfSize;
    res = sList_advance(&this_->data, this_->top)->data;
    return res;
}
/**
 * @brief
 *
 * @param this_
 * @param newData
 */
void dStack_push(dStack_obj_T* this_, dStack_data_T newData) {
    if (!dStack_isFull(this_))
    {
        this_->top++;
        sList_advance(&this_->data, this_->top)->data = newData;
    }
}
/**
 * @brief
 *
 * @param this_
 * @return dStack_data_T
 */
dStack_data_T dStack_pop(dStack_obj_T* this_) {
    dStack_data_T res = dStack_outOfSize;
    if (!dStack_isEmpty(this_))
    {
        res = dStack_Top(this_);
        this_->top--;
    }
    return  res;
}

#endif //DATASTRUCTPROJECT_U_DSTACK_H
