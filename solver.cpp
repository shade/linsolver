
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

            // This is Anstee's rule.
            for (int i = mBasic.size() - 1; i--;) {
                if (mObjective.at(i) <= mObjective.at(maxCoefficientIndex)) {
                    maxCoefficientIndex = i;
                }
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
                case Error::UNFEASIBLE:

                    std::cout << "This linear programming problem is infeasible" << std::endl;
                    std::cout << "" << std::endl;
                break;
            }   
        }
    }
}

void Solver::printOptimal () {

}