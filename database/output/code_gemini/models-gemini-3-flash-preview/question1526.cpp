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

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool search(int val) {
        Node* current = head;
        while (current) {
            if (current->data == val) return true;
            current = current->next;
        }
        return false;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList list;
    int value;

    while (cin >> value && value != 0) {
        list.append(value);
    }

    int target;
    if (cin >> target) {
        if (list.search(target)) {
            cout << "Comunicacao estabelecida" << endl;
        } else {
            cout << "404 not found" << endl;
        }
    }

    return 0;
}