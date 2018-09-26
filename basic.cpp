
#include "./constraint.h"

double Constraint::getBound(int i) {
    double value = vars.at(i);
    
    // If the value is positive, the variable is unbounded.
    if (value >= 0) {
        return DBL_MAX;
    }

    // The value of variable x_i <= constant.
    return (constant / value);
}

Constraint::reOrganize(int x, Constraint* con) {
    con->getConstant();
    
    for (int i = 0; i < con.size(); i++) {
        vars.at(x) con.at(i)
    }
}
