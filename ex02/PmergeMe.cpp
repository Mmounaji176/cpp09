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
        this->vector = other.vector;
    }
    return (*this);
}

bool isNumber(std::string str)
{
    long long int number = atoll(str.c_str());
    if (number > INT_MAX || number < INT_MIN)
        return false;
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

int PmergeMe::parse(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        if (!isNumber(str) || str.empty())
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }
    return 0;
}

void PmergeMe::mainFunc(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        list.push_back(stringToInt(argv[i]));
    for (int i = 1; i < argc; i++)
        vector.push_back(stringToInt(argv[i]));
    std::cout << "before :" ;
    printContainer(list);
    std::cout << std::endl;
    double start1 = clock();
    list = mergeInsertionSort(list);
    double end1 = clock();
    double start2 = clock();
    vector = mergeInsertionSort(vector);
    double end2 = clock();
    std::cout << "after :" ;
    printContainer(list);
    std::cout << std::endl;
    std::cout << "Merge sort time for std::list with a " << list.size() << " element is : " << std::fixed << std::setprecision(5) <<  (end1 - start1) / CLOCKS_PER_SEC * 1000000<< " us" << std::endl;
    std::cout << "Merge sort time for std::vector with a " << vector.size() << " element is : " << std::fixed << std::setprecision(5) << (end2 - start2) / CLOCKS_PER_SEC * 1000000<< " us" << std::endl;
}

