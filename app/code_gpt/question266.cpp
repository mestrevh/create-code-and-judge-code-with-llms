/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void sortList(Node*& head) {
    Node* sorted = nullptr;
    Node* current = head;
    while (current) {
        Node* next = current->next;
        insert(sorted, current->data);
        current = next;
    }
    head = sorted;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int value;
    while (cin >> value) {
        insert(head, value);
    }
    sortList(head);
    printList(head);
    return 0;
}
