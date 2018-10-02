
#include "./solver.h"

void Solver::pivot (int entering) {
    double min = DBL_MAX;

    // Find the leaving variable
    for (int i = 0; i < mBasic.size(); i++) {
        double bound = mBasic.at(i).getBounds(entering);

        // Replace current with the more stringent bound.
        if (min < bound) {
            min = bound;
        }
    }

    // If the smallest ratio is still unbounded, done.
    if (min == DBL_MAX) {
        Solver::printOptimal();
    }
}

double Solver::solve () {
    loop {
        try {
            int maxCoefficientIndex = mBasic.size() - 1;
            double maxCoefficient = -DBL_MAX;

            switch (mPivType) {
                case PivotRule::BLANDS:
                    // Choose a valid lowest index element
                    for(int i = 0; i < mBasic.size(); i++;) {
                        if (mObjective.at(i) > 0) {
                            maxCoefficientIndex = i;
                            break;
                        }
                    }
                break;
                case PivotRule::ANSTEES:
                    // Choose the highest coefficient, lowest index if tied
                    for (int i = mBasic.size() - 1; i--;) {
                        if (mObjective.at(i) <= mObjective.at(maxCoefficientIndex)) {
                            maxCoefficientIndex = i;
                        }
                    }
                break;
            }
            
            maxCoefficient = mObjective.at(maxCoefficientIndex);
            // If there are no more pivots we are done.
            if (maxCoefficient <= 0) {
                throw Error::UNBOUNDED;
            }

            pivot(maxCoefficientIndex);
        } catch (Error err) {
            switch (err) {
                case Error::UNBOUNDED:
                    std::cout << "This linear programming problem is unbounded" << std::endl;
                    break;
                break;
                case Error::INFEASIBLE:
                    std::cout << "This linear programming problem is infeasible" << std::endl;
                break;
            }   
        }
    }
}

void Solver::printOptimal () {

}