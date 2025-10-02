#include <iostream>
using namespace std;

struct ArrayList {
    int* arr;
    int capacity;
    int size;

    ArrayList(int cap = 10) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    void ensureCapacity() {
        if (size >= capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < size; i++) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
    }

    int get(int i) {
        return arr[i];
    }

    void insertHead(int val) {
        ensureCapacity();
        for (int i = size; i > 0; i--) arr[i] = arr[i-1];
        arr[0] = val;
        size++;
    }

    void insertTail(int val) {
        ensureCapacity();
        arr[size++] = val;
    }

    void insertAt(int i, int val) {
        ensureCapacity();
        for (int j = size; j > i; j--) arr[j] = arr[j-1];
        arr[i] = val;
        size++;
    }

    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size-1; i++) arr[i] = arr[i+1];
        size--;
    }

    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    void deleteAt(int i) {
        for (int j = i; j < size-1; j++) arr[j] = arr[j+1];
        size--;
    }

    void printForward() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void printBackward() {
        for (int i = size-1; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};
