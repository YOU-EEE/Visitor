#include<iostream>
#include"Vector.h"
#include"Vector.cpp"
using namespace std;

void print(Vector& vec)
{
    for (int i = 0; i < vec.size();i++){
        cout << vec[i]<< " ";
    }
    cout << endl;
}
int main()
{
    Vector vec;
    for (int i = 0; i < 4; i++){
        vec.add(i);
    }
    print(vec);
    vec.add(6);
    print(vec);
    vec.insert(0,9);
    print(vec);
}
