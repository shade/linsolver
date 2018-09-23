#include <iostream>
#include <cstdio>
#include <string>

double getInput()
{
    std::string word;
    char c = getchar();

    // Get the next integer and publish it.
    while (!std::isspace(c)) {
        word.push_back(c);
        c = getchar();
    }
    // Return the actual number.
    return std::stod(word);
}

int main () {
    int vars = 0, cons = 0;

    std::cout << "Enter number of variables: ";
    std::cin >> vars;

    std::cout << "Enter number of constraints: ";
    std::cin >> cons;

    return 0;
}