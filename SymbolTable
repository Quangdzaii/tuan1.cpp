#include <iostream>
#include <string>

using namespace std;

struct Symbol {
    string name;
    string value;
    Symbol* next;
};

struct SymbolTable {
    Symbol* head = nullptr;

    void insert(string name, string value) {
        Symbol* newNode = new Symbol{name, value, head};
        head = newNode;
    }

    Symbol* search(string name) {
        Symbol* temp = head;
        while (temp != nullptr) {
            if (temp->name == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void remove(string name) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) head = temp->next;
    else prev->next = temp->next;

    delete temp;
}

    void print() {
        Symbol* temp = head;
        cout << "Symbol Table:" << endl;
        while (temp != nullptr) {
            cout << temp->name << " = " << temp->value << endl;
            temp = temp->next;
        }
    }
};