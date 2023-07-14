#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>

class PmergeMe
{
    private:
        std::list<int> list;
        std::deque<int> deque;  
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        void parse(int argc, char **argv);
        void mainFunc(int argc, char **argv);
};

template <typename T>
void printContainer(T &container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << std::endl;
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
void mergeSort(T &container)
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
    mergeSort(left);
    mergeSort(right);
    merge(container, left, right);
}

#endif