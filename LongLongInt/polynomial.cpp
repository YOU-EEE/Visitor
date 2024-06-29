#include "polynomial.h"
#include <iostream>
using namespace std;

void polynomial::add_item(int c, int p)
{
    node* newn = new node(c,p);
    newn->next = head->next;
    head->next = newn;
    len++;
}

void polynomial::clear()
{
    node* p = head->next;
    for (int i = 0; i < len;i++){
        node* tmp = p;
        p = p->next;
        delete tmp;
    }
}

void polynomial::result()
{
    node* p = head->next;
    for (int i = 0;i < len-1;i++){
        cout << p->coef << "x^" << p->power << "+"; 
        p = p->next;
    }
    cout << p->coef << "x^" << p->power << endl;
}

polynomial add_p(polynomial& exp1, polynomial& exp2)
{
    polynomial ans;
    polynomial::node *p1 = exp1.head->next, *p2 = exp2.head->next;
    while(p1 != nullptr && p2 != nullptr){
        int pow1 = p1->power, pow2 = p2->power;
        if (pow1 == pow2) {
            int coefe = p1->coef + p2->coef;
            if(coefe != 0) ans.add_item(coefe, pow1);
            p1 = p1->next;
            p2 = p2->next;
        }
        else {
            if (pow1 > pow2) {
                ans.add_item(p2->coef, p2->power);
                p2 = p2->next;
            }
            else {
                ans.add_item(p1->coef, p1->power);
                p1 = p1->next;
            }
        }
    }
    while(p1 != nullptr){
        ans.add_item(p1->coef, p1->power);
        p1 = p1->next;
    }
    while(p2 != nullptr){
        ans.add_item(p2->coef, p2->power);
        p2 = p2->next;
    }
    //ans.result();
    return ans;
}

polynomial polynomial::operator+(polynomial& exp2)
{
    return add_p(*this, exp2);
}

