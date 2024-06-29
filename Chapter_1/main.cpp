#include <iostream>
#include "List.h"
#include "List.cpp"
using namespace std;


int main()
{
    /*SequenceList<int> seqlist(5);
    for (int i = 0; i < seqlist.length();i++){
        seqlist.set(i, i);
    }
    seqlist.insert(9,0);
    cout << seqlist.length();
    seqlist.traverse();*/
    /*LinkList<int> vec;
    vec.add(3);
    cout << vec.length() << endl;
    for (int i = 0; i < 5;i++){
        vec.add(i);
    }
    vec.insert(10, 2);
    vec.traverse();*/

    dLinkList<int> dvec;
    for (int i = 0; i < 5;i++){
        dvec.insert(i,0);
    }
    cout << dvec.search(9);
    dvec.traverse();
}