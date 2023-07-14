#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    std::cout << "PmergeMe copy constructor called" << std::endl;
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    std::cout << "PmergeMe assignation operator called" << std::endl;
    if (this != &other)
    {
        this->list = other.list;
        this->deque = other.deque;
    }
    return (*this);
}

bool isNumber(std::string str)
{
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (!isdigit(*it))
            return false;
    }
    return true;
}

int stringToInt(std::string str)
{
    int result = 0;
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
        result = result * 10 + (*it - '0');
    return result;
}

void PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        if (!isNumber(str) || str.empty())
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
}

void PmergeMe::mainFunc(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        list.push_back(stringToInt(argv[i]));
    mergeSort(list);
    printContainer(list);
}