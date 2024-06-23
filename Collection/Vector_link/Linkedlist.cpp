#include "Linkedlist.h"
#include <iostream>
using namespace std;

void push(Linklist** list, int i)
{
    Linklist* newl = new Linklist;
    newl->value = i;
    newl->next = *list;
    *list = newl;
}

void pop(Linklist** list)
{
    Linklist *p = *list;
    if (p != nullptr){
        *list = p->next;
        delete p;
        return;
    }
}

void destroy(Linklist* list)
{
    while (list != nullptr){
        pop(&list);
    }
}

Linklist** get_ith(Linklist** list, int i)
{
    Linklist* current;
    Linklist** pcurrent = list;
    for (int j = 0;j < i;j++){
        current = *pcurrent;
        pcurrent = &(current->next);
    }
    return pcurrent;
}

void print(Linklist* list)
{
    while(list->next != nullptr){
        cout << list->value << " ";
        list = list->next;
    }
}

