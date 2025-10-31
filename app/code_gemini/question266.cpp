/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void sortList(Node* head) {
    if (head == nullptr) {
        return;
    }

    for (Node* current = head; current != nullptr; current = current->next) {
        for (Node* index = current->next; index != nullptr; index = index->next) {
            if (current->data > index->data) {
                std::swap(current->data, index->data);
            }
        }
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* head = nullptr;
    Node* tail = nullptr;
    int value;

    while (std::cin >> value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    sortList(head);

    printList(head);

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
