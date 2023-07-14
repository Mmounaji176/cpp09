#include "PmergeMe.hpp" 

int main(int argc, char **argv) {
    PmergeMe pmergeMe;
    pmergeMe.parse(argc, argv);
    pmergeMe.mainFunc(argc, argv);
    return 0;
}