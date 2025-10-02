#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

struct LinkedList {
    Node* head;

    LinkedList() : head(NULL) {}

    int get(int i) {
        Node* temp = head;
        int idx = 0;
        while (temp != NULL && idx < i) {
            temp = temp->next;
            idx++;
        }

        return temp->data;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void insertAt(int i, int val) {
        if (i == 0) { insertHead(val); return; }
        Node* temp = head;
        for (int idx = 0; idx < i-1 && temp != NULL; idx++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteHead() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail() {
        if (head == NULL) return;
        if (head->next == NULL) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAt(int i) {
        if (i == 0) { deleteHead(); return; }
        Node* temp = head;
        for (int idx = 0; idx < i-1 && temp != NULL; idx++) {
            temp = temp->next;
        }
        
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void printForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printBackwardHelper(Node* node) {
        if (node == NULL) return;
        printBackwardHelper(node->next);
        cout << node->data << " ";
    }
    void printBackward() {
        printBackwardHelper(head);
        cout << endl;
    }
};
