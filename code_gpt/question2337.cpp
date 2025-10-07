/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Node {
    string item;
    Node* next;
    Node(string s) : item(s), next(nullptr) {}
};

void removeItem(Node*& head, const string& item) {
    Node** current = &head;
    while (*current) {
        if ((*current)->item == item) {
            Node* toDelete = *current;
            *current = (*current)->next;
            delete toDelete;
            return;
        }
        current = &(*current)->next;
    }
}

void printList(Node* head) {
    if (!head) {
        cout << "U gotta null pointer ma man" << endl;
        return;
    }
    while (head) {
        cout << head->item << endl;
        head = head->next;
    }
}

int main() {
    string input;
    Node* head = nullptr;
    Node** tail = &head;

    while (getline(cin, input) && input != "The End") {
        *tail = new Node(input);
        tail = &(*tail)->next;
    }

    while (getline(cin, input)) {
        removeItem(head, input);
    }

    printList(head);

    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    return 0;
}
