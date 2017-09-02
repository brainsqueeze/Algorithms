#include <iostream>
#include <vector>
#include "SortTools.h"
using namespace std;

std::vector<double> MergeSort(std::vector<double> list, bool reversed) {
    /**
    Sorts a list recursively with the merge-sort algorithm.

    @param list : vector to be sorted, size should be fixed at point
    of function call (std::vector).
    @param reversed : set to true to return a vector sorted descending (bool)
    @return a : sorted vector (std::vector)
    */

    std::vector<double> left;
    std::vector<double> right;

    if (list.size() == 1) {
        return list;
    }

    for (int i = 0; i < list.size(); i++) {
        if (i < (list.size() / 2)) {
            left.push_back(list.at(i));
        }
        else {
            right.push_back(list.at(i));
        }
    }

    left = MergeSort(left, reversed);
    right = MergeSort(right, reversed);
    if (reversed) {
        return mergeDescend(left, right);
    }
    return mergeAscend(left, right);
}

std::vector<double> mergeAscend(std::vector<double> a, std::vector<double> b) {
    /**
    Merges sorted vectors in ascending order

    @param a : left vector (std::vector).
    @param b : right vector (std::vector).
    @return merged results (std::vector)
    */

    int totalLength = a.size() + b.size();
    int i = 0;
    int j = 0;
    std::vector<double> mergedResult;

    for (int k = 0; k < totalLength; k++) {
        if (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                mergedResult.push_back(a[i]);
                i++;
            }
            else if (a[i] > b[j]) {
                mergedResult.push_back(b[j]);
                j++;
            }
            else {
                mergedResult.push_back(a[i]);
                i++;
                j++;
            }
        }
        else if (i < a.size()) {
            mergedResult.push_back(a[i]);
            i++;
        }
        else {
            mergedResult.push_back(b[j]);
            j++;
        }
    }
    return mergedResult;
}

std::vector<double> mergeDescend(std::vector<double> a, std::vector<double> b) {
    /**
    Merges sorted vectors in descending order

    @param a : left vector (std::vector).
    @param b : right vector (std::vector).
    @return merged results (std::vector)
    */

    int totalLength = a.size() + b.size();
    int i = 0;
    int j = 0;
    std::vector<double> mergedResult;

    for (int k = 0; k < totalLength; k++) {
        if (i < a.size() && j < b.size()) {
            if (a[i] > b[j]) {
                mergedResult.push_back(a[i]);
                i++;
            }
            else if (a[i] < b[j]) {
                mergedResult.push_back(b[j]);
                j++;
            }
            else {
                mergedResult.push_back(a[i]);
                i++;
                j++;
            }
        }
        else if (i < a.size()) {
            mergedResult.push_back(a[i]);
            i++;
        }
        else {
            mergedResult.push_back(b[j]);
            j++;
        }
    }
    return mergedResult;
}
