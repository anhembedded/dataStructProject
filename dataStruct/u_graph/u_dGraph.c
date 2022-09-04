/**
 * @file u_dGraph.c
 * @author Tran Hoang Anh (anh.embedded@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 *
 */


#include "u_dGraph.h"
#include <stdlib.h>

sList_obj_T group_BFT(vertices_T key, sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList )
{
    dQueue_obj_T visited_queue;
    dQueue_obj_T tempQueue;
    sList_obj_T thisGroup;
    dQueue_constructor(&visited_queue);
    dQueue_constructor(&tempQueue);
    sList_constructor(&thisGroup);

    dQueue_push(&tempQueue, key);
    dQueue_push(&visited_queue,key);
    sList_pushBack(&thisGroup, key);

    while (!dQueue_isEmpty(&tempQueue))
    {
        dQueue_data_T temp = dQueue_pop(&tempQueue);

        dGraph_s_getAdjIntoQueue( &arrayOfAdjList[temp],&tempQueue,&visited_queue);
        uint32_t sizeOfTempQueue = dQueue_size(&tempQueue);

        for(uint32_t i = 0; i < sizeOfTempQueue;i++)
        {
            sList_data_T tempData = sList_advance(&tempQueue.data,i)->data;
           if(!dQueue_find(&visited_queue, tempData))
           {
               dQueue_push(&visited_queue,tempData);
               sList_pushBack(&thisGroup, tempData);
           }
        }
    }
    dQueue_destructor(&visited_queue);
    dQueue_destructor(&tempQueue);
    return thisGroup;
}

sList_obj_T *dGraph_s_adjacentListInit(pair_T *arrayOfRelationPairs, uint32_t numberOfRelationPairs) {

    sList_obj_T * arrayToListPeople =  (sList_obj_T*)malloc(sizeof (sList_obj_T)*numberOfRelationPairs);

    if(arrayToListPeople != NULL)
    {
        for (uint32_t i = 0U; i< numberOfRelationPairs; i++)
        {
            sList_constructor(&arrayToListPeople[i]);
        }
        for(uint32_t i = 0U; i< numberOfRelationPairs; i++)
        {
            uint32_t relationIndex0 =   (arrayOfRelationPairs + i)->pair[0];
            uint32_t relationIndex1 =   (arrayOfRelationPairs + i)->pair[1];
            sList_pushFront(&arrayToListPeople[relationIndex0],relationIndex1);
            sList_pushFront(&arrayToListPeople[relationIndex1],relationIndex0);
        }
        // todo: sList_Unified
    }
    return arrayToListPeople;
}


pdBool dGraph_s_isHadAdj(sList_obj_T *vertices) {
    pdBool res = 0;
    if(sList_size(vertices) > 1)
    {
        res = 1;
    }
    return res;
}

sList_obj_T dGraph_s_groupAdjList(sList_data_T key, sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList)
{
    sList_obj_T tempRes;
    sList_constructor(&tempRes);

    for(uint32_t i = 0; i < sizeOfAdjList; i++ )
    {
        if(sList_find(&arrayOfAdjList[i], key))
        {
            sList_pushFront(&tempRes, i);
        }
    }
    return tempRes;
}

void dGraph_s_getAdjIntoQueue(sList_obj_T *AdjList, dQueue_obj_T *queueAdded, dQueue_obj_T* visited_queue ) {

    uint32_t sizeOfAdjList = sList_size(AdjList);
    if(sizeOfAdjList == 0)
    {
        return;
    } else
    {
        for(uint32_t i = 0; i <sizeOfAdjList; i++)
        {
            sList_data_T tempData = sList_advance(AdjList,i)->data;
            if(!dQueue_find(visited_queue, tempData))
            {
                dQueue_push(queueAdded,tempData);
            }

        }
    }

}


