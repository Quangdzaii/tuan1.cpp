struct Queue {
    int* arr;
    int capacity;
    int frontIndex, rearIndex, count;

    Queue(int cap = 10) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isEmpty() { return count == 0; }

    void enqueue(int item) {
        if (count == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < count; i++) {
                newArr[i] = arr[(frontIndex + i) % (count)];
            }
            delete[] arr;
            arr = newArr;
            frontIndex = 0;
            rearIndex = count - 1;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        count++;
    }

    int dequeue() {
        int val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return val;
    }

    int front() {
        return arr[frontIndex];
    }

    int size() { return count; }
};
