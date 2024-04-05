#include "insertion_sort.h"
#include <list>

void insertion_sort(std::list<int>& list) {
    // Empty list to put sorted values
    std::list<int> sortedList;

    for (const int& value : list) {
        auto iter = sortedList.begin();
        while (iter != sortedList.end() && *iter < value) {
            ++iter;
        }

        // Add value into sorted list at the correct position
        sortedList.insert(iter, value);
    }

    // Update the original list from the sorted list
    list = sortedList;
}

