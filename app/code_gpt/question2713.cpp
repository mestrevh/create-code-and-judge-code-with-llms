/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    void insert(string name, int score) {
        Node* newNode = new Node{name, score, nullptr};
        if (!head || head->score < score) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->score >= score) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        cout << name << " foi inserido no sistema! Sua nota e de " << score << "." << endl;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->name << " " << current->score << endl;
            current = current->next;
        }
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
    LinkedList list;
    string command;
    
    while (true) {
        cin >> command;
        if (command == "sair") break;
        else if (command == "inserir") {
            string name;
            int score;
            cin >> name >> score;
            list.insert(name, score);
        } else if (command == "imprimir") {
            list.print();
        }
    }
    return 0;
}
