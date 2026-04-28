#ifndef MAIN_CPP_BASE_H
#define MAIN_CPP_BASE_H

class Base{//base class for all data structures with virtual methods
public:
    virtual void append(int i,int data)=0;
    virtual void push_back(int data)=0;
    virtual void del_back()=0;
    virtual void push_front(int data)=0;
    virtual void del_front()=0;
    virtual void del(int i)=0;
    virtual int search(int data)=0;
    virtual int get_size()=0;
    virtual void print()=0;
    virtual ~Base(){};
};


#endif
