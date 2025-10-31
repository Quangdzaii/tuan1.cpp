#include <iostream>
#include <string>
using namespace std;

struct Symbol {
    string name;
    string value;
};

struct SymbolTable {
    Symbol table[100];
    int size = 0;

    void insert(string name, string value) {
        for (int i = 0; i < size; i++) {
            if (table[i].name == name) {
                table[i].value = value;
                return;
            }
        }

        if(size >=100) {
            return;
        }

        table[size].name = name;
        table[size].value = value;
        size++;
    }

    int search(string name) {
        for (int i = 0; i < size; i++) {
            if (table[i].name == name)
                return i;
        }
        return -1;
    }

    void remove(string name) {
        int pos = search(name);
        if (pos == -1) return;
        for (int i = pos; i < size - 1; i++) {
            table[i] = table[i + 1];
        }
        size--;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << table[i].name << " = " << table[i].value << endl;
        }
    }
};