#ifndef MAIN_CPP_SINGLELISTHEAD_H
#define MAIN_CPP_SINGLELISTHEAD_H
#include "node_single.h"
#include "base.h"
#include <iostream>
class SingleListHead:public Base{
private:
    node_single*head=NULL;
    int size=0;
public:
    SingleListHead();//constructor
    void append(int i,int data);
    void push_back(int data);
    void del_back();
    void push_front(int data);
    void del_front();
    void del(int i);
    int search(int data);//finding index of first element with data value
    int get(int i);
    int get_size();
    void print();//printing all elements in array list
    ~SingleListHead();

};
#endif
