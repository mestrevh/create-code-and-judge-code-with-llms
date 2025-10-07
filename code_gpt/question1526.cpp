/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int model;
    Node* next;
};

void insert(Node*& head, int model) {
    Node* newNode = new Node{model, head};
    head = newNode;
}

bool search(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->model == target) return true;
        current = current->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    int model;
    
    while (true) {
        cin >> model;
        if (model == 0) break;
        insert(head, model);
    }

    int searchModel;
    cin >> searchModel;

    if (search(head, searchModel)) {
        cout << "Comunicacao estabelecida\n";
    } else {
        cout << "404 not found\n";
    }

    return 0;
}
