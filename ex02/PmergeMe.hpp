#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>  

class PmergeMe
{
    private:
        std::list<int> list;
        std::vector<int> vector;  
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        int parse(int argc, char **argv);
        void mainFunc(int argc, char **argv);
};


template <typename T>
int checkSort(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator itNext = container.begin();
    itNext++;
    while (itNext != container.end())
    {
        if (*it > *itNext)
            return 0;
        it++;
        itNext++;
    }
    return 1; 
}

template <typename T>
void printContainer(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
}

template <typename T>
void    insertionAlgo(T &container)
{
    typename T::iterator it = container.begin();
    typename T::iterator itNext = container.begin();
    itNext++;
    while (itNext != container.end())
    {
        if (*it > *itNext)
        {
            typename T::iterator itPrev = it;
            itPrev--;
            while (itPrev != container.begin() && *itPrev > *itNext)
                itPrev--;
            itPrev++;
            container.insert(itPrev, *itNext);
            itNext = container.erase(itNext);
        }
        else
        {
            it++;
            itNext++;
        }
    }
}

template <typename T>
void    merge(T &container, T &left, T &right)
{
    typename T::iterator it = container.begin();
    typename T::iterator itLeft = left.begin();
    typename T::iterator itRight = right.begin();
    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft < *itRight)
            *it++ = *itLeft++;
        else
            *it++ = *itRight++;
    }
    while (itLeft != left.end())
        *it++ = *itLeft++;
    while (itRight != right.end())
        *it++ = *itRight++;
}

template <typename T>
void mergeInsertionSort(T &container)
{
    int size = container.size();
    if (size == 1)
        return;
    int middle = size / 2;
    T left;
    T right;
    typename T::iterator it = container.begin();
    for (int i = 0; i < middle; i++)
        left.push_back(*it++);
    for (int i = middle; i < size; i++)
        right.push_back(*it++);
    mergeInsertionSort(left);
    mergeInsertionSort(right);
    merge(container, left, right);
}

#endif