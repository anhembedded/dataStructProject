//
// Created by hoang on 9/1/2022.
//

#ifndef DATASTRUCTPROJECT_MAIN_H
#define DATASTRUCTPROJECT_MAIN_H

#include <stdlib.h>
extern "C"
{
#include "dataStruct/u_linkedList/u_sLinkedList.h"
#include "dataStruct/u_stack/u_dStack.h"
#include "dataStruct/u_queue/u_dQueue.h"
#include "dataStruct/u_graph/u_dGraph.h"
}




typedef struct relationPair
{
    pair_T *data;
    uint32_t size;
}relationPair_T;

typedef struct f0Type
{
    uint32_t *dataPtr;
    uint32_t size;
}f0Type_T;

typedef struct dataCovid
{
    relationPair_T  relation;
    f0Type_T f0;
    uint32_t numbOfPeople;
}dataCovid_T;

extern "C"
{

}

void dataCovidPrint(dataCovid_T *data);
dataCovid_T dataCovidInit(uint32_t numbOfPeople,pair_T *relationArray, uint32_t relationArraySize,  uint32_t *f0Array, uint32_t f0ArraySize);
sList_obj_T * peopleInit( dataCovid_T*dataCovid);
#endif //DATASTRUCTPROJECT_MAIN_H
