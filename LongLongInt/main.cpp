#include <iostream>
#include <string>
#include "polynomial.h"
using namespace std;

int main()
{
    polynomial exp1, exp2;
    exp1.add_item(5,6);
    exp1.add_item(1,5);
    exp1.add_item(2,4);
    exp1.add_item(5,2);
    exp1.add_item(1,0);
    exp1.result();
    exp2.add_item(1,5);
    exp2.add_item(2,4);
    exp2.add_item(5,2);
    exp2.add_item(1,0);
    exp2.result();
    polynomial expp = add_p(exp1, exp2);
    expp.result();
}