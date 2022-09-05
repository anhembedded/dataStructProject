//
// Created by pcx on 9/5/2022.
//

#ifndef DATASTRUCTPROJECT_MOCK2_MAIN_H
#define DATASTRUCTPROJECT_MOCK2_MAIN_H


#include "dataStruct/u_linkedList/u_sLinkedList.h"
#include "dataStruct/u_stack/u_dStack.h"
#include "dataStruct/u_queue/u_dQueue.h"
#include "dataStruct/u_graph/u_dGraph.h"


#include <stdlib.h>

extern sList_obj_T* adjListOfPeople;

typedef struct relationPair
{
    pair_T* data;
    uint32_t size;
}relationPair_T;

typedef struct f0Type
{
    uint32_t* dataPtr;
    uint32_t size;
}f0Type_T;

typedef struct dataCovid
{
    relationPair_T  relation;
    f0Type_T f0;
    uint32_t numbOfPeople;
}dataCovid_T;


void printGroupOfContractedPeople(uint32_t numberOfGroup, sList_obj_T * arrayOfListOfContractedPeople);
pdBool isAllPeopleBeGrouped(const uint32_t *peopleArray, uint32_t numbOfPeople);
uint32_t whichPersonIsNotGrouped(const uint32_t *peopleArray, uint32_t numbOfPeople);
void updatePersonIsGrouped(sList_obj_T *groupList, uint32_t *nonGroupPeopleArray, uint32_t numbOfPeople);
void creatGroupOfPeople(dataCovid_T * dataCovid);
dataCovid_T dataCovidInit( uint32_t numbOfPeople , pair_T* relationArray , uint32_t relationArraySize , uint32_t* f0Array , uint32_t f0ArraySize );
sList_obj_T* peopleInit( dataCovid_T* dataCovid );

#endif //DATASTRUCTPROJECT_MOCK2_MAIN_H
