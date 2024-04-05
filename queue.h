#pragma once

#include <iostream>
#include <vector> // Include vector for the search function
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int qSize;

public:
    Queue();
    ~Queue();

    void push(const T& item);
    void pop();
    T getFront() const;
    int size() const;
    bool empty() const;
    void moverear();
    void display() const;

    // Search function
    int recursiveLinearSearchLast(vector<int>& vec, int target, int index) ;
};

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr), qSize(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& item) {
    Node* newNode = new Node(item);
    if (empty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    qSize++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty. Cannot use pop." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    qSize--;
}

template <typename T>
T Queue<T>::getFront() const {
    if (empty()) {
        cerr << "Queue is empty. No element in front" << endl;
        exit(1);
    }
    return front->data;
}

template <typename T>
int Queue<T>::size() const {
    return qSize;
}

template <typename T>
bool Queue<T>::empty() const {
    return qSize == 0;
}

template <typename T>
void Queue<T>::moverear() {
    if (empty() || qSize == 1) {
        cout << "Queue is empty or has only one element";
        return;
    }

    T frontData = front->data;
    pop();
    push(frontData);
}

template <typename T>
void Queue<T>::display() const {
    if (empty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
int recursiveLinearSearchLast(vector<T> vec, T target, int index) {
    if (index == 0) {
        return -1; // Target not found
    }
    if (vec[index] == target) {
        return index; // Found target at current index
    }
    return recursiveLinearSearchLast(vec, target, index - 1); // Recursive call for the previous index
}
