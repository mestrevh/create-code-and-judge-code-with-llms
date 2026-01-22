/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseLinkedList(Node* head) {
    std::stack<int> s;
    Node* current = head;
    while (current) {
        s.push(current->data);
        current = current->next;
    }
    current = head;
    while (current) {
        current->data = s.top();
        s.pop();
        current = current->next;
    }
    return head;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int val;
    Node* head = nullptr;
    Node* tail = nullptr;

    while (iss >> val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    head = reverseLinkedList(head);
    Node* current = head;
    while (current) {
        std::cout << current->data << (current->next ? " " : "");
        current = current->next;
    }

    return 0;
}
