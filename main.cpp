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
#include "dataStruct/u_queue/u_dQueue.h"
}


sList_iterator_T  iter = nullptr;
sList_obj_T  myList;
sList_obj_T  myList2;
dStack_obj_T  myStack;
dQueue_obj_T myQueue;
sList_data_T watchData;
sList_data_T size;
int main() {

    sList_constructor(&myList);
    sList_contructorSize(&myList2,10U);
    dStack_constructor(&myStack,5U);
    dQueue_constructor(&myQueue);

    for (uint32_t i = 0U; i < 3U; ++i) {
        dQueue_push(&myQueue,i);
    }
    size = dQueue_size(&myQueue);
    watchData = dQueue_pop(&myQueue);
    size = dQueue_size(&myQueue);
    watchData = dQueue_pop(&myQueue);
    size = dQueue_size(&myQueue);
    watchData = dQueue_pop(&myQueue);
    size = dQueue_size(&myQueue);
    watchData = dQueue_pop(&myQueue);
    size = dQueue_size(&myQueue);
    watchData = dQueue_pop(&myQueue);
    size = dQueue_size(&myQueue);
    watchData = dQueue_pop(&myQueue);
    size = dQueue_size(&myQueue);

    dQueue_destructor(&myQueue);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
