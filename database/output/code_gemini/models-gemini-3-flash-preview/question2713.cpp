/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(string name, int score) {
        Node* newNode = new Node(name, score);
        if (!head || score > head->score) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next && curr->next->score >= score) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        cout << name << " foi inserido no sistema! Sua nota e de " << score << ".\n";
    }

    void print() const {
        Node* curr = head;
        while (curr) {
            cout << curr->name << " " << curr->score << "\n";
            curr = curr->next;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LinkedList list;
    string command;

    while (cin >> command && command != "sair") {
        if (command == "inserir") {
            string name;
            int score;
            if (cin >> name >> score) {
                list.insert(name, score);
            }
        } else if (command == "imprimir") {
            list.print();
        }
    }

    return 0;
}