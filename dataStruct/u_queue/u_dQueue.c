/**
 * @file u_dQueue.c
 * @author Tran Hoang Anh (anh.embedded@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-30
 *
 *
 */

#include "u_dQueue.h"

void dQueue_constructor(dQueue_obj_T *this_) {
    sList_destructor(&this_->data);
}

void dQueue_destructor(dQueue_obj_T *this_) {
    sList_destructor(&this_->data);
}

pdBool dQueue_isEmpty(dQueue_obj_T *this_) {
    pdBool res = sList_isEmpty(&this_->data);
    return res;
}

void dQueue_push(dQueue_obj_T *this_, dQueue_data_T newData) {
    sList_pushFront(&this_->data,newData);
}

dQueue_data_T dQueue_pop(dQueue_obj_T *this_) {
    return sList_popBack(&this_->data);
}

uint32_t dQueue_size(dQueue_obj_T *this_) {
    return sList_size(&this_->data);
}
