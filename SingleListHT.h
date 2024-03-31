#ifndef MAIN_CPP_SINGLELISTHT_H
#define MAIN_CPP_SINGLELISTHT_H
#include "base.h"
#include "node_single.h"
class SingleListHT:public Base{
private:
    node_single*head = nullptr;
    node_single*tail = nullptr;
    int size;
public:
    SingleListHT();
    void append(int i,int data);
    void push_back(int data); 
    void del_back(); 
    void push_front(int data);
    void del_front();
    void del(int i);
    int search(int data);
    int get_size();
    void print();
    ~SingleListHT();
};

#endif
