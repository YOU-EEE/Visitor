#ifndef VECTOR_H_INLUDED
#define VECTOR_H_INLUDED
struct Linklist;

class Vector
{
public:
    Vector();
    Vector(const Vector& vec);
    ~Vector();

    int size();
    bool isEmpty();
    void clear();

    void insert(int i, int v);
    void add(int v);
    void remove(int i);

    int get(int i) ;
    void set(int i, int v);

    int& operator[](int i);
private:
    Linklist* list;
};



#endif