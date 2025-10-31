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

    void print() {
        Symbol* temp = head;
        cout << "Symbol Table:" << endl;
        while (temp != nullptr) {
            cout << temp->name << " = " << temp->value << endl;
            temp = temp->next;
        }
    }
};