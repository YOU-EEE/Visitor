#include "visitor.h"
#include "units.h"
#include "iostream"
#include <vector>
using namespace std;

void printUnit(Unit* u)
{
    cout << "Unit: " << u->getSymbol() << "  Movement: " << u->getMovPts() << endl;
}

void creation(vector<Unit*>& units)
{
    for (int i = 0;i < 3; i++){
        Unit* u = new Footman(i);
        units.push_back(u);
    }
}

void applyVisitor(vector<Unit*>& units, ActionVisitor& vis)
{
    for (Unit* u: units)
        u->accept(vis);
}


int main()
{
    vector<Unit*> units;
    creation(units);
    MoveVisitor mv(3,3);
    applyVisitor(units, mv);
    return 0;
}
