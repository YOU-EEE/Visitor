#ifndef UNITS_H_INCLUDED
#define UNITS_H_INCLUDED

#include<string>

class ActionVisitor;

class Unit {
public:
    Unit(int uid): id(uid){}
    virtual int getMovPts() const = 0;
    virtual std::string getSymbol() const = 0;
    virtual void accept(ActionVisitor& vis) = 0;

    int getID() const { return id;}
private:
    int id;
};

class Footman: public Unit{
public:
    Footman(int uid): Unit(uid){}
    virtual int getMovPts() const;
    virtual std::string getSymbol() const;
    virtual void accept(ActionVisitor& vis);
};

#endif