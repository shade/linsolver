
#include "./solver.h"

void Solver::pivot () {
    double min = DBL_MAX;

    // Set up the basic variables.
    for (int i = 0; i < mBasic.size(); i++) {
        double bound = mBasic.getBounds(i);

        // Replace current with the more stringent bound.
        if (min < bound) {
            min = bound;
        }
    }

    // If the smallest ratio is still unbounded, done.
    if (min == DBL_MAX) {
        throw Error::UNBOUNDED;
    }
}


double Solver::solve () {
    loop {
        try {
            pivot();
        } catch (Error err) {
            switch (err) {
                case Error::UNBOUNDED:

                break;
                case Error::UNFEASIBLE:
                
                break;
            }   
        }
    }
}

