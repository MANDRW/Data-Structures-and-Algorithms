#include "SingleListHT.h"
#include "node_single.h"
#include <iostream>

using namespace std;

SingleListHT::SingleListHT(){
    size = 0;
}

void SingleListHT::push_front(int data)
{
    node_single* node = new node_single;
    node->value = data;
    node->next = head;
    head = node;
    if(tail == nullptr)
    {
        tail = node;   //warunek dla pustej listy
    }
    size++;
}

void SingleListHT::push_back(int data)
{
    node_single* node = new node_single;
    node->value = data;
    node->next = nullptr;
    if(tail != nullptr)
    {
        tail->next = node;
    }
    tail = node;
    if(head == nullptr)
    {
        head = node;  //warunek dla pustej listy
    }
    size++;
}

void SingleListHT::del_front()
{
    if(size == 0)
    {
        return;
    }
    if(head == tail)   //warunek przy jednym elemencie
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    node_single* temp = head;
    head = temp->next;
    delete temp;
    size--;
}

void SingleListHT::del_back()
{
    if(size == 0)
    {
        return;
    }
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    node_single* temp = head;
    for(int i = 0; i < size - 2; i++)
    {
        temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    tail->next = nullptr;
    delete temp;
    size--;
}

int SingleListHT::search(int data)
{
    if (head == nullptr)
    {
        cout<<"Pusta lista"<<endl;
        return 0;
    }
    node_single* node = head;
    for(int i = 1; i <= size; i++)
    {
        if(node->value == data)
        {
            return i;
        }
        node = node->next;
    }
    cout<<"Brak elementu"<<endl;
    return 0;
}

void SingleListHT::append(int i, int data)
{
    if(i > size)
    {
        return;
    }
    else if(i == 0)
    {
        push_front(data);
        return;
    }
    else if(i == size)
    {
        push_back(data);
        return;
    }
    node_single* node = head;
    for(int j = 0; j < i - 1; j++)
    {
        node = node->next;
    }
    node_single* new_node = new node_single;
    new_node->value = data;
    new_node->next = node->next;
    node->next = new_node;
    size++;
}

void SingleListHT::del(int i)
{
    if(i > size)
    {
        return;
    }
    else if(i == 0)
    {
        del_front();
        return;
    }
    else if(i == size-1)
    {
        del_back();
        return;
    }
    node_single* node = head;
    for(int j = 0; j < i-1; j++)   //wskazujemy na jeden przed nodem ktory chcemy usunąć
    {
        node = node->next;
    }
    node_single* temp = node->next;
    node->next = temp->next;
    delete temp;
    size--;
}
int SingleListHT::get_size()
{
    return size;
}
void SingleListHT::print()
{
    node_single* searched = head;
    {
        while(searched != nullptr)
        {
            std::cout << searched->value << "; ";
            searched = searched->next;
        }
    }
    cout<<endl;
}
SingleListHT::~SingleListHT() {
    while (head != nullptr) 
    {
        del_front();
    }
}