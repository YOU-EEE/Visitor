#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

#include "units.h"

class ActionVisitor{
public:
    virtual bool visitFootman(Footman& ft) = 0 ;
};

class MoveVisitor: public ActionVisitor{
public: 
    MoveVisitor(int xx, int yy): x(xx),y(yy){}
    virtual bool visitFootman(Footman& ft);
private:
    int x, y;
};

#endif