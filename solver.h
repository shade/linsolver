#include <cfloat>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>

#include "./basic.h"

#define loop for(;;)

enum Error {
    UNBOUNDED,
    UNFEASIBLE
};

class Solver {
public:
    std::vector<Basic> mBasic;
    std::vector<Basic> mSolution; // where the final solution is stored.
    std::vector<double> mObjective; // The objective function for the problem.

    double solve(); // Returns an optimal z value.
    void pivot(int entering); // Pivos
}
