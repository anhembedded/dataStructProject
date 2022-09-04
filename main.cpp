/**
 * @file main.cpp
 * @author TranHoangAnh (anh.embedded@gamil.com)
 * @brief
 * @version 0.1
 * @date 2022-08-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "main.h"
#include <iostream>
sList_obj_T* adjListOfPeople;


pair_T n1 [ 7 ] = { {1, 2}, // 0 1
                {1, 3}, // 0 2
                {2, 4}, // 1 3
                {4, 6}, // 3 5
                {2, 8}, // 1 7
                {6, 9}, // 5 8
                {7, 10} }; // 6 9
uint32_t  n1ArrayF0 [ ] = { 3, 8 , 5 };


void printAdjacentList( sList_obj_T* arrayList , uint32_t size )
{
    printf( "\n" );
    for ( uint32_t i = 0U; i < size; i++ )
    {
        printf( "person: %d: " , i );
        sList_obj_T temp = arrayList [ i ];
        sList_print( &temp );
        printf( "\n" );
    }
}
void f0Brand(sList_obj_T *group, dataCovid_T *dataCovid)
{
    dQueue_obj_T f1_queue;
    dQueue_constructor(&f1_queue);
    dGraph_s_getAdj(&adjListOfPeople[2],&f1_queue);


}

void makeGraph(dataCovid_T * dataCovid)
{
    sList_obj_T  nonGroupPeople;
    sList_obj_T thisGraph;
    sList_constructor(&thisGraph);

    sList_constructor(&nonGroupPeople);
    for(uint32_t i = 0; i < dataCovid->numbOfPeople; i++)
    {
        sList_pushBack(&nonGroupPeople,i);
    }
   thisGraph =  group_BFT(2, adjListOfPeople, 10);
    f0Brand(&thisGraph,dataCovid );
}





int main( ) {

    dataCovid_T data1;
    data1 = dataCovidInit( 10 , n1 , 7 , n1ArrayF0 , 3 );
    dataCovidPrint( &data1 );
    adjListOfPeople = peopleInit( &data1 );

    makeGraph(&data1);


    return 0;
}



dataCovid_T dataCovidInit( uint32_t numbOfPeople , pair_T* relationArray , uint32_t relationArraySize , uint32_t* f0Array ,
                          uint32_t f0ArraySize ) {
    dataCovid_T res;
    f0Type_T f0DataTemp;
    relationPair_T   relationPairTemp;
    f0DataTemp.size = f0ArraySize;
    f0DataTemp.dataPtr = f0Array;
    relationPairTemp.size = relationArraySize;
    relationPairTemp.data = relationArray;

    res.f0 = f0DataTemp;
    res.relation = relationPairTemp;
    res.numbOfPeople = numbOfPeople;
    for ( uint32_t i = 0U; i < res.numbOfPeople; i++ )
    {
        res.relation.data [ i ].pair [ 0 ] --;
        res.relation.data [ i ].pair [ 1 ] --;
    }
    return res;
}

void dataCovidPrint( dataCovid_T* data ) {
    for ( uint32_t i = 0; i < data->relation.size; i++ )
    {
        std::cout << ( ( data->relation.data ) + i )->pair [ 0 ] << "  ";
        std::cout << ( ( data->relation.data ) + i )->pair [ 1 ] << std::endl;
    }
    std::cout << std::endl;
    for ( uint32_t i = 0; i < data->f0.size; i++ )
    {
        std::cout << data->f0.dataPtr [ i ] << " ";
    }
}

sList_obj_T* peopleInit( dataCovid_T* dataCovid ) {

    sList_obj_T* arrayToListPeople = ( sList_obj_T* ) malloc( sizeof( sList_obj_T ) * dataCovid->numbOfPeople );

    if ( arrayToListPeople != NULL )
    {
        for ( uint32_t i = 0U; i < dataCovid->numbOfPeople; i++ )
        {
            sList_constructor( &arrayToListPeople [ i ] );
        }
        for ( uint32_t i = 0U; i < dataCovid->relation.size; i++ )
        {
            uint32_t relationIndex0 = ( dataCovid->relation.data + i )->pair [ 0 ];
            uint32_t relationIndex1 = ( dataCovid->relation.data + i )->pair [ 1 ];
            sList_pushFront( &arrayToListPeople [ relationIndex0 ] , relationIndex1 );
            sList_pushFront( &arrayToListPeople [ relationIndex1 ] , relationIndex0 );
        }
        // todo: sList_Unified
    }
    return arrayToListPeople;
}





