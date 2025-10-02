#include <iostream>
using namespace std;

struct Stack {
    int* arr;
    int capacity;
    int topIndex;

    Stack(int cap = 10) {
        capacity = cap;
        arr = new int[capacity];
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(int item) {
        if (topIndex + 1 >= capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i <= topIndex; i++) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
        arr[++topIndex] = item;
    }

    int pop() {
        return arr[topIndex--];
    }

    int top() {
        return arr[topIndex];
    }

    int size() {
        return topIndex + 1;
    }
};
