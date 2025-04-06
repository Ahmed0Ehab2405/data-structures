#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublySortedList {
    DNode* head;

public:
    DoublySortedList() {
        head = nullptr;
    }

    void insert(int value) {
        DNode* newNode = new DNode;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (!head || value < head->data) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }

        DNode* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next) current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }

    void makenull() {
        DNode* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        DNode* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};