#include <iostream>
#include <vector>
#include <queue>
#include "queue.h"
#include "insertion_sort.h"

using namespace std;

int main(){
    // make object of queue
    Queue<int> theQueue;

    for (int i = 1; i <= 10; ++i){
        theQueue.push(i);
    }

    cout << "Queue elements: ";
    theQueue.display();
    cout << endl;

    theQueue.moverear();
    cout << "Queue after moving front element to rear: ";
    theQueue.display();
    cout << endl;

    // recursive function 
    vector<int> myVec;
    myVec.push_back(4);
    myVec.push_back(6);
    myVec.push_back(2);
    myVec.push_back(7);
    myVec.push_back(2);
    int target = 2;

    int lastIndex = recursiveLinearSearchLast(myVec, target, myVec.size() - 1);
    if (lastIndex != -1) {
        cout << "Last occurrence of " << target << " is at index " << lastIndex << endl;
    } else {
        cout << "Target not found in vector." << endl;
    }
    cout << endl;

    std::list<int> myList = {100, 289, 4, 1, 67};

    cout << "Original list: ";
    for (const int& val : myList) {
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    insertion_sort(myList);

    cout << "Sorted list: ";
    for (const int& val : myList) {
        cout << val << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}