#include "units.h"
#include "visitor.h"
#include<string>

int Footman::getMovPts() const{
    return 3;
}

std::string Footman::getSymbol() const{
    return "FT_" + std::to_string(getID());
}

void Footman::accept(ActionVisitor& vis)
{
    vis.visitFootman(*this);
}