#ifndef Linkedlist
#define Linkedlist

struct Linklist{
    int value;
    Linklist* next;
    Linklist():
        value(0), next(nullptr){}
};
void print(Linklist* list);

void push(Linklist** list, int i);

void pop(Linklist** list);

void destroy(Linklist* list);

Linklist** get_ith(Linklist** list, int i);

#endif