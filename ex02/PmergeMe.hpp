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
void insertionSort(std::vector<T>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeInsertionSort(std::vector<T>& arr, int left, int right, int insertion_threshold) {
    if (left < right) {
        if (right - left + 1 <= insertion_threshold) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(arr, left, mid, insertion_threshold);
            mergeInsertionSort(arr, mid + 1, right, insertion_threshold);
            merge(arr, left, mid, right);
        }
    }
}

template <typename T>
void mergeInsertionSort(std::vector<T>& arr, int insertion_threshold = 10) {
    int n = arr.size();
    mergeInsertionSort(arr, 0, n - 1, insertion_threshold);
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeInsertionSort(arr);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
#endif