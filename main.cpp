#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

typedef VariableToken unsigned long;

std::tuple<double, VariableToken> parseVariable (std::string var) {

    for (int i = var.length(); i--;) {
        boost::split(variables, constraint, [](char c) {
            return c == '+';
        });
    }

    return varPair;
}

std::string getConstraint () {
    std::string constraint = "";
    std::cout << "Enter A Constraint e.g. 10 + x3 + 4x2 + x1 < 10" << std::endl;
    std::cin >> constraint;

    // try to split the variables by a +
    std::vector<std::string> variables;
    boost::split(variables, constraint, [](char c) {
        return c == '+';
    });

    for(std::string const& value: variables) {
    }
}

int main () {
    int vars = 0, cons = 0;

    std::cout << "Enter number of variables: ";
    std::cin >> vars;

    std::cout << "Enter number of constraints: ";
    std::cin >> cons;

    getConstraint();
    return 0;
}


