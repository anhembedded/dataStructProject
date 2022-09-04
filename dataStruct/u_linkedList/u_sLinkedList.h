/**
 * @file u_sLinkedList.h
 * @author TranHoangAnh (anh.embedded@gamil.com)
 * @brief
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DATASTRUCTPROJECT_U_SLINKEDLIST_H
#define DATASTRUCTPROJECT_U_SLINKEDLIST_H

#include "node/u_node.h"

typedef node_data_T sList_data_T;
typedef node_obj_T sList_node_T;
typedef node_obj_T* sList_iterator_T;
extern sList_data_T sList_outOfSizeReturnVar;
/**
 * @brief
 *
 */
typedef struct sList_obj
{
    sList_node_T* head;
}sList_obj_T;

/* Constructor and Destructor */

void sList_constructor(sList_obj_T* this_);
void sList_constructorSize(sList_obj_T* this_, uint32_t sizeParam);
void sList_destructor(sList_obj_T* this_);
/* Public Methods */

pdBool sList_isEmpty(sList_obj_T* this_);
uint32_t sList_size(sList_obj_T* this_);
sList_iterator_T sList_begin(sList_obj_T* this_);
sList_iterator_T sList_end(sList_obj_T* this_);
void sList_addFront(sList_obj_T* this_);
void sList_pushFront(sList_obj_T* this_, sList_data_T newData);
void sList_pushBack(sList_obj_T* this_, sList_data_T newData);
sList_data_T sList_popBack(sList_obj_T* this_);
sList_data_T sList_popFront(sList_obj_T* this_);
void sList_popFrontNonReturn(sList_obj_T* this_);
sList_iterator_T sList_advance(sList_obj_T* this_, uint32_t pos);
void sList_erase(sList_obj_T* this_, uint32_t position);
void sList_insert(sList_obj_T* this_, uint32_t position, sList_data_T newData);
void sList_swap(sList_obj_T* this_, uint32_t firstPos, uint32_t secondPos);
void sList_sortAscending(sList_obj_T* this_);
void sList_sortDescending(sList_obj_T* this_);
void sList_reverse(sList_obj_T* this_);
void sList_unique(sList_obj_T* this_);
pdBool sList_find(sList_obj_T *this_,sList_data_T key);
void sList_print(sList_obj_T* this_);
void sList_delete(sList_obj_T* this_, sList_data_T key);

/* Overloading operator */

pdBool sList_isTheSame(sList_obj_T* this_, sList_obj_T* otherOperand);
sList_obj_T sList_move(sList_obj_T* this_);
sList_obj_T sList_copy(sList_obj_T* this_);

/* static method */

static sList_node_T* sList_s_creatNewNode();
static sList_node_T* sList_s_creatNewNodeData(sList_data_T newData);
static void sList_s_freeNode(sList_iterator_T theNode);
static sList_data_T sList_s_getData(sList_iterator_T theNode);

#endif //DATASTRUCTPROJECT_U_SLINKEDLIST_H
