#include <cfloat>
#include <vector>
#include <cstring>
#include <string>

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

    double solve(); // Returns an optimal z value.
    void pivot();
}