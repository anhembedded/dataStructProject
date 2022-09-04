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

void dGraph_BFT(vertices_T key,sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList ) {

    dQueue_obj_T visited_queue;
    dQueue_obj_T tempQueue;
    dQueue_obj_T thisGraph;
    dQueue_constructor(&visited_queue);
    dQueue_constructor(&tempQueue);
    dQueue_constructor(&thisGraph);

    dQueue_push(&tempQueue, key);
    dQueue_push(&visited_queue,key);

    while (!dQueue_isEmpty(&tempQueue))
    {
        dQueue_data_T temp = dQueue_pop(&tempQueue);
        dQueue_push(&thisGraph,temp);

       // if(dGraph_s_isHadAdj())

        for(uint32_t i = 0; i<sizeOfAdjList; i++)
        {

        }
    }

    dQueue_destructor(&visited_queue);
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


void dGraph_s_getAdjIntoQueue(vertices_T key, sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList, dQueue_obj_T *adjQueue)
{

}

pdBool dGraph_s_isHadAdj(sList_obj_T *vertices) {
    pdBool res = 0;
    if(sList_size(vertices) > 1)
    {
        res = 1;
    }
    return res;
}

void dGraph_s_groupAdjList(sList_data_T key, sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList)
{
    sList_obj_T graph;
    sList_constructor(&graph);

    for(uint32_t i = 0; i < sizeOfAdjList; i++ )
    {
        if(sList_find(&arrayOfAdjList[i], key))
        {
            sList_pushFront(&graph,i);
        }
    }
    sList_print(&graph);
}

