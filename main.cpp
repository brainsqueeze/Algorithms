#include <iostream>
#include <vector>
#include "Sort/SortTools.h"
using namespace std;

int main() {
    double v[] = {4, 6, 9, 7, 3};
    std::vector<double> sortedList;
    std::vector<double> x(v, v + sizeof v / sizeof v[0]);

    sortedList = MergeSort(x, true);
    for (std::vector<double>::const_iterator i = sortedList.begin(); i != sortedList.end(); ++i)
        std::cout << *i << ' ';
    return 0;
}
