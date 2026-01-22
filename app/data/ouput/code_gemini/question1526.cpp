/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

struct Node {
    int data;
    Node* next;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Node* head = nullptr;
    Node* tail = nullptr;
    int num;

    while (std::cin >> num && num != 0) {
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int target;
    std::cin >> target;

    bool found = false;
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        std::cout << "Comunicacao estabelecida\n";
    } else {
        std::cout << "404 not found\n";
    }

    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
