#ifndef _polynomial_h
#define _polynomial_h

class polynomial{
    friend polynomial add_p(polynomial& exp1, polynomial& exp2);
    
    public:
        polynomial(){
            len = 0;
            head = new node;
        }
        ~polynomial(){
            clear();
            delete head;
        }

        void clear();
        void add_item(int c, int p);
        polynomial operator+(polynomial& exp2);
        void result();
    private:
        struct node{
            int coef, power;
            node* next;
            node():next(nullptr){};
            node(int c, int p):coef(c),power(p),next(nullptr){};
        };
        node* head;
        int len;
};

#endif