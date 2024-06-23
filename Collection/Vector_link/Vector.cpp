#include"Linkedlist.h"
#include"Linkedlist.cpp"
#include"Vector.h"
#include<iostream>
using namespace std;

Vector::Vector():list(nullptr){}
Vector::~Vector(){
    clear();
}
int Vector::size()
{
    int sz = 0;
    Linklist* l = list;
    while(l != nullptr){
        sz += 1;
        l = l->next;
    }
    return sz;
}
bool Vector::isEmpty()
{
    if (list != nullptr)
        return true;
    return false;
}

void Vector::clear()
{
    destroy(list);
    list = nullptr;
}

void Vector::add(int v)
{
    int sz = size();
    Linklist** pcurrent = get_ith(&list, sz);
    Linklist* newl = new Linklist;
    newl->value = v;
    *pcurrent = newl; 
}

void Vector::insert(int i, int v)
{
    Linklist** p = get_ith(&list, i-1);
    Linklist* newl = new Linklist;
    newl->value = v;
    if (i == 0){
        newl->next = *p;
        *p = newl;
        return;
    }
    newl->next = (*p)->next;
    (*p)->next = newl;
}

void Vector::remove(int i)
{
    Linklist **p = get_ith(&list, i);
    Linklist* l = (*p)->next;
    delete *p;
    *p = l;
}

int Vector::get(int i)
{
    Linklist** p = get_ith(&list,i);
    return (*p)->value;
}

void Vector::set(int i, int v)
{
    Linklist** p = get_ith(&list, i);
    (*p)->value = v;
}

int& Vector::operator[](int i)
{
    Linklist**p = get_ith(&list, i);
    return (*p)->value;
}
