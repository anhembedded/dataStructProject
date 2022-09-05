/**
 * @file u_dGraph.h
 * @author Tran Hoang Anh (anh.embedded@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-31
 *
 *
 */
#ifndef DATASTRUCTPROJECT_U_DGRAPH_H
#define DATASTRUCTPROJECT_U_DGRAPH_H
#include "u_linkedList/u_sLinkedList.h"
#include "u_queue/u_dQueue.h"

typedef node_data_T vertices_T;
typedef sList_obj_T dGraph_list_T;
typedef node_obj_T dGraph_node_T;
typedef node_obj_T* dGraph_iterator_T;

/*PUBLIC properties */
typedef struct pair
{
    uint32_t pair[2];
}pair_T;

typedef struct dGraph_obj
{
    sList_obj_T*  verticesArray;
    sList_obj_T *arrayOfAdjList;
    uint32_t u32_numberOfVertices;
    dQueue_obj_T queue_visitedVertices;

} dGraph_ogj_T;

/* Constructor and Destructor */

void dGraph_constructor(dGraph_ogj_T * this_);
void dGraph_destructor(dGraph_ogj_T * this_);

/* Public Methods */


/* static method */

sList_obj_T * dGraph_s_adjacentListInit (pair_T *arrayOfRelationPairs, uint32_t numberOfRelationPairs);
pdBool  dGraph_s_isVisited (dQueue_obj_T *visited_queue, vertices_T key);
void dGraph_s_getAdjIntoQueue(sList_obj_T *AdjList, dQueue_obj_T *queueAdded, dQueue_obj_T* visited_queue );
void dGraph_s_getAdj(sList_obj_T *AdjList, dQueue_obj_T *queueAdded);
sList_obj_T dGraph_s_groupBFT(vertices_T key, sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList );
pdBool dGraph_s_isHadAdj(sList_obj_T *vertices);

//Breadth First Search
sList_obj_T dGraph_s_groupAdjList(sList_data_T key, sList_obj_T *arrayOfAdjList, uint32_t sizeOfAdjList);

#endif //DATASTRUCTPROJECT_U_DGRAPH_H
