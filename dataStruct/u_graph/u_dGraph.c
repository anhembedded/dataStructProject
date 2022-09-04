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
    dQueue_obj_T queue;
    dQueue_obj_T thisGraph;
    dQueue_constructor(&visited_queue);
    dQueue_constructor(&queue);
    dQueue_constructor(&thisGraph);

    dQueue_push(&queue,key);
    dQueue_push(&visited_queue,key);

    while (!dQueue_isEmpty(&queue))
    {
        dQueue_data_T temp = dQueue_pop(&queue);
        dQueue_push(&thisGraph,temp);

        //while()

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

