#include <iostream>
using namespace std;


class Node{
    public:
        Node():next(nullptr){};
        Node(int n):len(0),num(n), next(head){};
    private:
        int num;
        int len;
        Node* next, *head;
};

int Joeserve(Node* head)
{

}