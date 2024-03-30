#include "SingleListHead.h"
#include "node_single.h"
#include <iostream>

using namespace std;

SingleListHead::SingleListHead(){};

void SingleListHead::append(int i, int data) {
    if(i==0){
        push_front(data);
        return;
    }
    if(i==size-1) push_back(data);
    else{
        node_single*old=head;
        for(int j=0;j<i-1;j++) old=old->next;
        node_single*node=new node_single;
        node->value=data;
        node->next=old->next;
        old->next=node;
        size++;
    }
}

void SingleListHead::push_front(int data) {
    node_single*node=new node_single;
    node->value=data;
    node->next=head;
    head=node;
    size++;
}

void SingleListHead::push_back(int data) {
    if(head==NULL) push_front(data);
    else{
        node_single*old=head;
        for(int j=0;j<size-1;j++) old=old->next;
        node_single*node=new node_single;
        node->value=data;
        node->next=NULL;
        old->next=node;
        size++;
    }

}
void SingleListHead::del_front() {
    if(head==NULL) return;
    node_single*temp=head;
    head=temp->next;
    size--;
    delete temp;

}

void SingleListHead::del_back() {
    if(head==NULL) return;
    node_single*old=head;
    for(int j=0;j<size-2;j++) old=old->next;//searching pre last node
    node_single*temp=old->next;
    old->next=old->next->next;
    size--;
    delete temp;
}

void SingleListHead::del(int i) {
    if(head==NULL) return;
    if(i==0) {
        del_front();
        return;
    }
    if(i==size-1) del_back();
    else{
        node_single*old=head;
        for(int j=0;j<i-1;j++) old=old->next;
        node_single*temp=old->next;
        old->next=old->next->next;
        size--;
        delete temp;
    }
}

 int SingleListHead::get(int i) {
    if(i>size or head==NULL) return 0;
     node_single *old=head;
     for(int j=0;j<i;j++) old=old->next;
     return old->value;
}

int SingleListHead::search(int data) {
    if(head==NULL) {
        cout<<"Pusta lista"<<endl;
        return 0;
    }
    node_single*searched=head;
    for(int j=0;j<size;j++){
        if(searched->value==data) return j+1;
        searched=searched->next;
    }
    cout<<"Brak elementu"<<endl;
    return 0;
}

int SingleListHead::get_size() {
    return size;
}

void SingleListHead::print() {
    if(head==NULL) {
        cout<<"Pusta lista"<<endl;
        return;
    }
    node_single *old=head;
    for(int j=0;j<size;j++) {
        cout<<old->value<<endl;
        old=old->next;
    }
}

SingleListHead::~SingleListHead() {
    while (head!=NULL) del_front();
}