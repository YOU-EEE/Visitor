#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template <class Type>

class List{
    public:
        virtual void clear() = 0;
        virtual int length() const = 0;
        virtual void insert(Type x, int i) = 0;
        virtual void remove(int i) = 0;
        virtual int search(Type x) = 0;
        virtual Type visit(int i) = 0;
};

template <class Type>
class SequenceList:public List<Type>{
    public:
        SequenceList(int len):
        maxSize(len) {
            array = new Type[len];
            currentlen = len;
        }

        ~SequenceList(){delete [] array;};

        void clear(){ currentlen = 0;}
        int length() const {return currentlen;}

        void traverse() const;
        void set(int i, Type x) {array[i] = x;}
        void insert(Type x, int i);
        void remove(int i);
        int search(Type x);
        Type visit(int i);

    private:
        Type *array;
        int currentlen;
        int maxSize;
        void resize();
};

template <class Type>
class LinkList:public List<Type>
{
    public:
        LinkList();
        ~LinkList(){clear(); delete head;}

        void clear();
        int length() const {return currentlen;}
        void insert(Type x, int i);
        void remove(int i);
        int search(Type x);
        Type visit(int i);
        void traverse() const;
        void add(Type x)
        {
            currentlen += 1;
            node* p = new node(x, head->next);
            head->next = p;
        }

    private:
        struct node{
            Type value;
            node* next;
            node(Type v, node* n = nullptr):
            value(v), next(n){};
            node(): next(nullptr) {};
        };
        node* head;
        int currentlen;
        node* move(int i)
        {
            node* p = head;
            for (int j = 0; j < i;j++)
                p = p->next;
            return p;
        }
};

template <class Type>

class dLinkList:public List<Type>
{
    public:
        dLinkList(){
            head = new node;
            tail = new node;
            head->rep = tail;
            tail->prp = head;
            currentlen = 0;
        };
        ~dLinkList(){clear(); delete head; delete tail;}
        void clear();
        int length() const {return currentlen;}

        void insert(Type x, int i);
        void remove(int i);
        int search(Type x);
        Type visit(int i);
        void traverse() const;
    private:
        struct node{
            Type value;
            node* prp, * rep;
            node(Type v, node* p = nullptr, node* r = nullptr):
            value(v), prp(p), rep(r){};
            node(): prp(nullptr), rep(nullptr) {};
        };
        int currentlen;
        node *head, *tail;
        node* move(int i)
        {
            node* p = head;
            for (int j = 0; j < i;j++)
                p = p->rep;
            return p;
        }
};
#endif