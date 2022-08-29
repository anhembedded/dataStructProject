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
    sList_node_T* newNode = sList_obj_creatNewNode();
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
    else
    {
        // Malloc NULL handler
    }

}

void sList_pushFront(sList_obj_T* this_, sList_data_T newData) {
    sList_addFront(this_);
    this_->head->data = newData;
}

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

void sList_pushBack(sList_obj_T* this_, sList_data_T newData)
{
    sList_node_T * newNode = sList_obj_creatNewNode();
    sList_iterator_T theLastElement = NULL;
    theLastElement = sList_end(this_);
   if(theLastElement == NULL)
   {
       this_->head = newNode;
   }else
   {
       theLastElement->next = newNode;
   }
    newNode->next = NULL;
    newNode->data = newData;
}

sList_node_T* sList_obj_creatNewNode() {
    sList_node_T* newNode = malloc(sizeof(sList_node_T));
    node_constructor(newNode);
    return newNode;
}

void sList_obj_freeNode(sList_iterator_T theNode) {
    if(theNode != NULL)
    {
        free(theNode);
    }else
    {
        //NULL handler
    }
}

sList_data_T sList_popBack(sList_obj_T *this_)
{
    sList_data_T res = sList_outOfSizeReturnVar;
    uint32_t sizeOfList = sList_size(this_);
    sList_iterator_T theLastElement;
    sList_iterator_T iter = this_->head;
    theLastElement = sList_end(this_);
 if(sizeOfList == 0)
 {
    res = sList_outOfSizeReturnVar;
 }else if(sizeOfList == 1)
 {
     res = sList_obj_getData(theLastElement);
     sList_obj_freeNode(theLastElement);
    this_->head = NULL;
 }else
 {
     while( iter->next != theLastElement)
     {
         iter = iter->next;
     }
     iter->next = NULL;
     res = sList_obj_getData(theLastElement);
     sList_obj_freeNode(theLastElement);
 }

    return res;
}

sList_data_T sList_obj_getData(sList_iterator_T theNode) {
    return theNode->data;
}

sList_data_T sList_popFront(sList_obj_T *this_) {
    sList_data_T res = sList_outOfSizeReturnVar;
    if(sList_isEmpty(this_))
    {
        res = sList_outOfSizeReturnVar;
    }else
    {
        sList_iterator_T  oldHead = sList_begin(this_);
        res = sList_obj_getData(oldHead);
        this_->head = oldHead->next;
        sList_obj_freeNode(oldHead);
    }
    return  res;
}

sList_iterator_T sList_advance(sList_obj_T *this_, uint32_t pos) {
 uint32_t counter = 0;
 sList_iterator_T  iter = sList_begin(this_);
 if(sList_isEmpty(this_))
 {

 }else
 {
     while(counter < pos)
     {
         iter = iter->next;
         counter++;
     }
 }
    return iter;
}

void sList_erase(sList_obj_T *this_, uint32_t position) {
    uint32_t sizeOfList = 0;
    sizeOfList = sList_size(this_);
    if(position == sizeOfList-1)
    {
        (void )sList_popBack(this_);
    }else if(position == 0)
    {
        (void)sList_popFront(this_);
    }else
    {
        sList_iterator_T frontIter = sList_advance(this_,position-1);
        sList_iterator_T behindIter = sList_advance(this_,position+1);
        sList_iterator_T posIter =  sList_advance(this_,position);
        frontIter->next = behindIter;
        sList_obj_freeNode(posIter);
    }
}

void sList_insert(sList_obj_T *this_, uint32_t position, sList_data_T newData) {
    uint32_t sizeOfList = 0;
    sizeOfList = sList_size(this_);
    if(position == sizeOfList-1)
    {
         sList_pushBack(this_,newData);
    }else if(position == 0)
    {
        sList_pushFront(this_,newData);
    }else
    {
        sList_iterator_T frontIter = sList_advance(this_,position-1);
        sList_iterator_T behindIter = sList_advance(this_,position+1);
        sList_iterator_T posIter = sList_obj_creatNewNode(newData);
        frontIter->next = posIter;
        posIter->next = behindIter;
    }
}

sList_node_T *sList_obj_creatNewNodeData(sList_data_T newData) {
    sList_node_T * temp;
    temp = sList_obj_creatNewNode();
    temp->data = newData;
    return temp;
}
