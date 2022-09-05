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
 extern "C"
 {
#include "main.h"
 }

#include <iostream>




int main( ) {

    dataCovid_T data1;
    data1 = dataCovidInit(data_numberPeople , data_pair ,
                          data_numberOfContactedPair , data_ArrayF0 , data_numberF0);


    adjListOfPeople = peopleInit( &data1 );
    creatGroupOfPeople(&data1);

    return 0;
}




