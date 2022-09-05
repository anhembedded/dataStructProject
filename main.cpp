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

    dataCovid_T dataCovid;
    dataCovid = dataCovidInit(data_numberPeople , data_pair ,
                              data_numberOfContactedPair , data_ArrayF0 , data_numberF0);

    adjListOfPeople = peopleInit( &dataCovid );
    creatGroupOfPeople(&dataCovid);

    return 0;
}




