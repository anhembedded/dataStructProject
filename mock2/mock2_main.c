//
// Created by pcx on 9/5/2022.
//

#include "mock2_main.h"
#include <stdio.h>
sList_obj_T* adjListOfPeople;


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

/*void dataCovidPrint( dataCovid_T* data ) {
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
}*/

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


void creatGroupOfPeople(dataCovid_T *dataCovid) {
    uint32_t *nonGroupPeople = (uint32_t *)(malloc(sizeof(uint32_t) * dataCovid->numbOfPeople));
    uint32_t sizeGroup =0;
    sList_obj_T *groupOfContractedPeople = malloc(sizeof(sList_obj_T)*100);

    for(uint32_t i = 0; i < dataCovid->numbOfPeople; i++)
    {
        nonGroupPeople[i] = 0;
    }
    while(!isAllPeopleBeGrouped(nonGroupPeople,dataCovid->numbOfPeople))
    {
        uint32_t personIsNotGrouped;
        sList_constructor(&groupOfContractedPeople[sizeGroup]);
        personIsNotGrouped = whichPersonIsNotGrouped(nonGroupPeople, dataCovid->numbOfPeople);
        groupOfContractedPeople[sizeGroup] =  group_BFT(personIsNotGrouped, adjListOfPeople, 10);
        updatePersonIsGrouped(&groupOfContractedPeople[sizeGroup], nonGroupPeople, dataCovid->numbOfPeople);
        sizeGroup++;
    }
    printGroupOfContractedPeople(sizeGroup, groupOfContractedPeople);
    free(groupOfContractedPeople);
}


void printGroupOfContractedPeople(uint32_t numberOfGroup, sList_obj_T *arrayOfListOfContractedPeople) {
    const uint32_t  ofSetAmount = 1;
    printf("Having %d group(s) \n", numberOfGroup);
    for(uint32_t i = 0U; i <numberOfGroup; i++)
    {
        printf("group [%d]: ", i);

        for (uint32_t j = 0U; j < sList_size(&arrayOfListOfContractedPeople[i]); ++j) {
            printf(" %d ", sList_advance(&arrayOfListOfContractedPeople[i],j)->data+ofSetAmount);
        }
        printf("\n");
    }
}


pdBool isAllPeopleBeGrouped(const uint32_t *peopleArray, uint32_t numbOfPeople)
{
    pdBool result = 1U;
    for (int i = 0; i < numbOfPeople; i++)
    {
        if(peopleArray[i] == 0U)
        {
            result = 0U;
        }
    }
    return (result);
}

uint32_t whichPersonIsNotGrouped(const uint32_t *peopleArray, uint32_t numbOfPeople)
{
    uint32_t  personIsNotGrouped = UINT32_MAX;
    for (int i = 0; i < numbOfPeople; i++)
    {
        if(peopleArray[i] == 0U)
        {
            personIsNotGrouped = i;
            break;
        }
    }
    return personIsNotGrouped;
}
void updatePersonIsGrouped(sList_obj_T *groupList, uint32_t *nonGroupPeopleArray, uint32_t numbOfPeople)
{
    uint32_t sizeOfThisGraph = sList_size(groupList);
    for(uint32_t i = 0; i < sizeOfThisGraph; i++)
    {
        uint32_t temp = sList_advance(groupList,i)->data;
        nonGroupPeopleArray[temp]  = 1;
    }
}

