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
#include <iostream>
extern "C"
{
#include "dataStruct/u_linkedList/u_sLinkedList.h"
}


sList_iterator_T  iter = nullptr;
sList_obj_T  myList;
sList_data_T watchData;
int main() {

    sList_constructor(&myList);

    for (uint32_t i = 0U; i < 10U; ++i) {
        sList_pushBack(&myList,i);
        iter = sList_advance(&myList,i);
    }
    sList_erase(&myList,9U);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
