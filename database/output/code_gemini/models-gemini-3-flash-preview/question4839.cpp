/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertSorted(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr || val < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = nullptr;
    int value;
    for (int i = 0; i < 5; ++i) {
        if (cin >> value) {
            insertSorted(head, value);
        }
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << (current->next != nullptr ? " " : "");
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    cout << endl;

    return 0;
}