

#include "u_node.h"
#include <stdlib.h>

const node_data_T node_dataInit = 0;



void node_constructor(node_obj_T* this_)
{
    this_->data = node_dataInit;
    this_->next = NULL;
}

void node_constructorInitData(node_obj_T* this_, node_data_T newData)
{
    node_constructor(this_);
    this_->data = newData;
}

void node_destructor(node_obj_T* this_)
{
    //Do nothings
}

pdBool node_compare(node_obj_T* this_, node_obj_T* otherNode)
{
    pdBool res = 0;
    if (this_->data == otherNode->data)
    {
        res = 1;
    }
    return res;
}
