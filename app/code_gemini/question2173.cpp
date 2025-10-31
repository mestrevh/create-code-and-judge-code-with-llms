/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

struct Node {
    std::string name;
    Node* next;

    Node(const std::string& n) : name(n), next(nullptr) {}
};

void insert(Node*& head, const std::string& name) {
    Node* newNode = new Node(name);
    newNode->next = head;
    head = newNode;
}

void clearList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    Node* head = nullptr;
    std::string moleName;

    for (int i = 0; i < n; ++i) {
        std::cin >> moleName;
        insert(head, moleName);
    }

    std::string queryName;
    std::cin >> queryName;

    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        if (current->name == queryName) {
            count++;
        }
        current = current->next;
    }

    std::cout << count << std::endl;

    clearList(head);

    return 0;
}
