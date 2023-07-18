#include "PmergeMe.hpp" 

int main(int argc, char **argv) {
    PmergeMe pmergeMe;
    if (argc == 1)
        return 0;
    if (pmergeMe.parse(argc, argv) == -1)
        return 0;
    pmergeMe.mainFunc(argc, argv);
    return 0;
}