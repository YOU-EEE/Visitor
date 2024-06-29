#include "List.h"
#include <iostream>

using namespace std;


template<class Type>

void SequenceList<Type>::resize()
{
    maxSize *= 2;
    Type *newa = new Type[currentlen];
    for (int i = 0; i < currentlen/2;i++){
        newa[i] = array[i];
    }
    array = newa;
}

template<class Type>
void SequenceList<Type>::insert(Type x, int i)
{
    if (i >= maxSize) resize();
    for (int j = currentlen; j > i; j--){
        array[j] = array[j-1];
    }
    array[i] = x;
    currentlen += 1;
}

template<class Type>
void SequenceList<Type>::remove(int i)
{
    for(int j = i;j < currentlen-1;j++){
        array[j] = array[j+1];
    }
    currentlen -=1;
}

template<class Type>
int SequenceList<Type>::search(Type x)
{
    for (int i = 0; i < currentlen;i++){
        if (array[i] == x)
            return i;
    }
    return -1;
}

template<class Type>
Type SequenceList<Type>::visit(int i)
{ return array[i]; }

template<class Type>
void SequenceList<Type>::traverse() const
{
    for (int i = 0; i < currentlen;i++){
        cout << array[i] << " ";
    }
}

template <class Type>

LinkList<Type>::LinkList()
{
    head = new node;
    currentlen = 0;
}


template<class Type>
void LinkList<Type>::clear()
{
    currentlen = 0;
    node *tmp,*p = head->next;
    while(p != nullptr){
        tmp = p;
        p = tmp->next;
        delete tmp;
    }
    head->next = nullptr;
}

template <class Type>
void LinkList<Type>::insert(Type x, int i)
{
    node* p = move(i);
    node* newn = new node(x, p->next);
    p->next = newn;
}

template <class Type>

void LinkList<Type>::remove(int i)
{
    node *p = move(i-1);
    node* tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

template <class Type> 
int LinkList<Type>::search(Type x)
{
    int i = 0;
    node *q, *p = head;
    while(p != nullptr && (q = p->next)->value != x){
        i++;
        p = q;
    }
    if (p == nullptr) return -1;
    return i;
}

template <class Type>
Type LinkList<Type>::visit(int i)
{
    node* p = move(i);
    return p->value;
}

template <class Type>
void LinkList<Type>::traverse() const
{
    node* p = head->next;
    while(p != nullptr){
        cout << p->value << " ";  
        p = p->next;
    }
}

template<class Type>

void dLinkList<Type>::clear()
{
    currentlen = 0;
    node *tmp,*p = head->rep;
    while(p != tail){
        tmp = p;
        p = tmp->rep;
        delete tmp;
    }
    head->prp = tail;
    tail->rep = head;
}

template<class Type>

void dLinkList<Type>::insert(Type x, int i)
{
    if (i == 0){
        node* newn = new node(x, head, head->rep);
        currentlen ++;
        head->rep->prp = newn;
        head->rep = newn;
        return;
    }
    node* p = move(i);
    node* newn = new node(x, p->prp, p);
    p->prp->rep = newn;
    p->prp = newn;
    currentlen++;
}

template <class Type>

void dLinkList<Type>::remove(int i)
{
    node* p = move(i);
    p->prp->rep = p->rep;
    p->rep->prp = p->prp;
    delete p;
    currentlen -= 1;
}

template<class Type>

int dLinkList<Type>::search(Type x)
{
    node* p = head->rep;
    int i = 0;
    while(p != tail && p->value != x){
        p = p->rep;
        i++;
    }
    if (p == tail) return -1;
    return i;
}

template <class Type>
Type dLinkList<Type>::visit(int i)
{
    node* p = move(i);
    return p->value;
}

template <class Type>
void dLinkList<Type>::traverse() const
{
    node* p = head->rep;
    while(p != tail){
        cout << p->value << " ";
        p = p->rep;
    }
}
