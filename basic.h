
#include <vector>
#include <cfloat>

class Constraint {
public:
    int num;
    double constant;
    std::vector<double> vars;

    double getBound(int i);
}