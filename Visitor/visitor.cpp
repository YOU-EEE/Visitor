#include "visitor.h"
#include "units.h"
#include <iostream>
using namespace std;

void moveAction(Unit& u, int x, int y)
{
    cout << "Move: " << u.getSymbol()
         << " to (" << x << "," << y << ")" << endl;
}

bool MoveVisitor::visitFootman(Footman& Ft)
{
    moveAction(Ft, x, y);
    return true;
}