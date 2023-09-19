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
void	insertion(T& _container) {
	for (typename T::iterator it = ++_container.begin(); it != _container.end(); ++it) {
		int value = *it;
		typename T::iterator position = it;
		while (position != _container.begin() && *(--position) > value) {
			*it = *position;
			--it;
		}
		*it = value;
	}
}

template <typename T>
T	merge(T& first, T& second) {
	T merge;

	while (first.size() && second.size()) {
		if (*first.begin() > *second.begin()) {
			merge.insert(merge.end(), *second.begin());
			second.erase(second.begin());
		} else {
			merge.insert(merge.end(), *first.begin());
			first.erase(first.begin());
		}
	}
	while (first.size()) {
		merge.insert(merge.end(), *first.begin());
		first.erase(first.begin());
	}
	while (second.size()) {
		merge.insert(merge.end(), *second.begin());
		second.erase(second.begin());
	}
	return merge;
}

template <typename T>
void mergeInsertionSort(T& _container) {
    if (_container.size() <= 10) {
        insertion(_container);
        return;
    }
    typename T::iterator middle = _container.begin();
	//move iterator n position
    std::advance(middle, _container.size() / 2);

    T first(_container.begin(), middle);
    T second(middle, _container.end());

    mergeInsertionSort(first);
    mergeInsertionSort(second);

    _container = merge(first, second);
}

#endif