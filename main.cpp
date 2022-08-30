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
#include "dataStruct/u_stack/u_dStack.h"
}


sList_iterator_T  iter = nullptr;
sList_obj_T  myList;
sList_obj_T  myList2;
dStack_obj_T  myStack;
sList_data_T watchData;
int main() {

    sList_constructor(&myList);
    sList_contructorSize(&myList2,10U);
    dStack_constructor(&myStack,5U);
    for (uint32_t i = 0U; i < 10U; ++i) {
        dStack_push(&myStack,i );
    }

    dStack_destructor(&myStack);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
