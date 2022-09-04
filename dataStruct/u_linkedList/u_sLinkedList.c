/**
 * @file u_sLinkedList.c
 * @author TranHoangAnh (anh.embedded@gamil.com)
 * @brief
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "u_sLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

 /**
  * @brief
  *
  */
sList_data_T sList_outOfSizeReturnVar = UINT32_MAX;

/**
 * @brief
 *
 * @param this_
 */
void sList_constructor(sList_obj_T* this_)
{
    this_->head = NULL;
}
void sList_constructorSize(sList_obj_T* this_, uint32_t sizeParam)
{
    sList_constructor(this_);
    for (uint32_t i = 0; i < sizeParam;i++) {
        sList_pushFront(this_, node_dataInit);
    }
}
/**
 * @brief
 *
 * @param this_
 * @return pdBool
 */
pdBool sList_isEmpty(sList_obj_T* this_)
{
    pdBool res = 0;
    if (this_->head == NULL)
    {
        res = 1;
    }
    return res;
}
/**
 * @brief
 *
 * @param this_
 * @return uint32_t
 */
uint32_t sList_size(sList_obj_T* this_)
{
    uint32_t counterElements = 0;
    sList_iterator_T iter;
    iter = this_->head;
    if (sList_isEmpty(this_))
    {
        counterElements = 0;
    }
    else
    {
        while (iter != NULL)
        {
            iter = iter->next;
            counterElements++;
        }
    }
    return counterElements;
}
/**
 * @brief
 *
 * @param this_
 */
void sList_addFront(sList_obj_T* this_)
{
    sList_node_T* newNode = sList_s_creatNewNode();
    sList_node_T* oldListHead = this_->head;
    if (newNode != NULL)
    {
        if (sList_isEmpty(this_))
        {
            this_->head = newNode;
            newNode->next = oldListHead;
        }
        else
        {
            newNode->next = oldListHead;
            this_->head = newNode;
        }
    }
}
/**
 * @brief
 *
 * @param this_
 * @param newData
 */
void sList_pushFront(sList_obj_T* this_, sList_data_T newData) {
    sList_addFront(this_);
    if (this_->head != NULL)
    {
        this_->head->data = newData;
    }
}
/**
 * @brief
 *
 * @param this_
 * @return sList_iterator_T
 */
sList_iterator_T sList_begin(sList_obj_T* this_) {

    sList_iterator_T res = NULL;
    if (sList_isEmpty(this_))
    {
        res = NULL;
    }
    else
    {
        res = this_->head;
    }
    return res;
}
/**
 * @brief
 *
 * @param this_
 * @return sList_iterator_T
 */
sList_iterator_T sList_end(sList_obj_T* this_)
{

    sList_iterator_T res = this_->head;
    if (sList_isEmpty(this_))
    {
        res = NULL;
    }
    else
    {
        while (res->next != NULL)
        {
            res = res->next;
        }
    }
    return res;
}
/**
 * @brief
 *
 * @param this_
 * @param newData
 */
void sList_pushBack(sList_obj_T* this_, sList_data_T newData)
{
    sList_node_T* newNode = sList_s_creatNewNode();
    sList_iterator_T theLastElement = NULL;
    theLastElement = sList_end(this_);
    if (theLastElement == NULL)
    {
        this_->head = newNode;
    }
    else
    {
        theLastElement->next = newNode;
    }
    newNode->next = NULL;
    newNode->data = newData;
}
/**
 * @brief
 *
 * @return sList_node_T*
 */
sList_node_T* sList_s_creatNewNode() {
    sList_node_T* newNode = malloc(sizeof(sList_node_T));
    node_constructor(newNode);
    return newNode;
}
/**
 * @brief
 *
 * @param theNode
 */
void sList_s_freeNode(sList_iterator_T theNode) {
    if (theNode != NULL)
    {
        node_destructor(theNode);
        free(theNode);
    }
}
/**
 * @brief
 *
 * @param this_
 * @return sList_data_T
 */
sList_data_T sList_popBack(sList_obj_T* this_)
{
    sList_data_T res;
    uint32_t sizeOfList = sList_size(this_);
    sList_iterator_T theLastElement;
    sList_iterator_T iter = this_->head;
    theLastElement = sList_end(this_);
    if (sizeOfList == 0)
    {
        res = sList_outOfSizeReturnVar;
    }
    else if (sizeOfList == 1)
    {
        res = sList_s_getData(theLastElement);
        sList_s_freeNode(theLastElement);
        this_->head = NULL;
    }
    else
    {
        while (iter->next != theLastElement)
        {
            iter = iter->next;
        }
        iter->next = NULL;
        res = sList_s_getData(theLastElement);
        sList_s_freeNode(theLastElement);
    }
    return res;
}
/**
 * @brief
 *
 * @param theNode
 * @return sList_data_T
 */
sList_data_T sList_s_getData(sList_iterator_T theNode) {
    return theNode->data;
}
/**
 * @brief
 *
 * @param this_
 * @return sList_data_T
 */
sList_data_T sList_popFront(sList_obj_T* this_) {
    sList_data_T res;
    if (sList_isEmpty(this_))
    {
        res = sList_outOfSizeReturnVar;
    }
    else
    {
        sList_iterator_T  oldHead = sList_begin(this_);
        res = sList_s_getData(oldHead);
        this_->head = oldHead->next;
        sList_s_freeNode(oldHead);
    }
    return  res;
}
/**
 * @brief
 *
 * @param this_
 * @param pos
 * @return sList_iterator_T
 */
sList_iterator_T sList_advance(sList_obj_T* this_, uint32_t pos) {
    uint32_t counter = 0;
    sList_iterator_T  iter = sList_begin(this_);
    if (sList_isEmpty(this_))
    {
        iter = NULL;
    }
    else
    {
        while (counter < pos)
        {
            iter = iter->next;
            counter++;
        }
    }
    return iter;
}
/**
 * @brief
 *
 * @param this_
 * @param position
 */
void sList_erase(sList_obj_T* this_, uint32_t position) {
    uint32_t sizeOfList = 0;
    sizeOfList = sList_size(this_);
    if (position == sizeOfList - 1)
    {
        (void)sList_popBack(this_);
    }
    else if (position == 0)
    {
        (void)sList_popFront(this_);
    }
    else
    {
        sList_iterator_T frontIter = sList_advance(this_, position - 1);
        sList_iterator_T behindIter = sList_advance(this_, position + 1);
        sList_iterator_T posIter = sList_advance(this_, position);
        frontIter->next = behindIter;
        sList_s_freeNode(posIter);
    }
}
/**
 * @brief
 *
 * @param this_
 * @param position
 * @param newData
 */
void sList_insert(sList_obj_T* this_, uint32_t position, sList_data_T newData) {
    uint32_t sizeOfList = 0;
    sizeOfList = sList_size(this_);
    if (position == sizeOfList - 1)
    {
        sList_pushBack(this_, newData);
    }
    else if (position == 0)
    {
        sList_pushFront(this_, newData);
    }
    else
    {
        sList_iterator_T frontIter = sList_advance(this_, position - 1);
        sList_iterator_T behindIter = sList_advance(this_, position + 1);
        sList_iterator_T posIter = sList_s_creatNewNodeData(newData);
        frontIter->next = posIter;
        posIter->next = behindIter;
    }
}
/**
 * @brief
 *
 * @param newData
 * @return sList_node_T*
 */
sList_node_T* sList_s_creatNewNodeData(sList_data_T newData) {
    sList_node_T* temp;
    temp = sList_s_creatNewNode();
    temp->data = newData;
    return temp;
}
/**
 * @brief
 *
 * @param this_
 */
void sList_destructor(sList_obj_T* this_) {
    while (!sList_isEmpty(this_))
    {
        sList_popFrontNonReturn(this_);
    }

}
/**
 * @brief
 *
 * @param this_
 */
void sList_popFrontNonReturn(sList_obj_T* this_) {

    if (!sList_isEmpty(this_))
    {
        sList_iterator_T  oldHead = sList_begin(this_);
        this_->head = oldHead->next;
        sList_s_freeNode(oldHead);
    }

}

void sList_print(sList_obj_T *this_) {
    uint32_t sizeOfList = sList_size(this_);
    printf("\n SList_print: \n");
    for (uint32_t i = 0U; i < sizeOfList; i++)
    {
        uint32_t temp =  sList_advance(this_,i)->data;
        printf(" | %d",temp);
    }
}

pdBool sList_find(sList_obj_T *this_, sList_data_T key) {
    pdBool res = 0;
    if(sList_isEmpty(this_))
    {
        res = 0;
    } else
    {
        uint32_t sizeOfList = sList_size(this_);
        for(uint32_t i = 0; i < sizeOfList; i++)
        {
            if(sList_advance(this_, i)->data == key)
            {
                res = 1;
                break;
            }
        }
    }
    return res;
}

sList_obj_T sList_copy(sList_obj_T *this_) {
    sList_obj_T tempList;
    sList_constructor(&tempList);
    for(uint32_t i = 0; i < sList_size(this_); i++)
    {
        sList_data_T tempData;
        tempData = sList_advance(this_,i)->data;
        sList_pushBack(&tempList,tempData);
    }
    return tempList;
}

sList_obj_T sList_move(sList_obj_T *this_) {
    sList_obj_T result;
    sList_constructor(&result);
    result = sList_copy(this_);
    sList_destructor(this_);
    return result;
}

void sList_delete(sList_obj_T *this_, sList_data_T key)
{
    if(!sList_isEmpty(this_))
    {
        uint32_t counter = 0;
        uint32_t sizeOfList = sList_size(this_);



    }
}
