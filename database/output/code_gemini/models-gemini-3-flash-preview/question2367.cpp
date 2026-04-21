/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
    Node(string n) : name(n), next(nullptr) {}
};

class PlayerList {
public:
    Node* head;

    PlayerList() : head(nullptr) {}

    void inserir(string name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remover(string name) {
        if (head == nullptr) return;
        if (head->name == name) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    bool existe(string name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) return true;
            temp = temp->next;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    if (!(cin >> x)) return 0;

    PlayerList team;
    string instruction, playerName;

    for (int i = 0; i < x; ++i) {
        cin >> instruction >> playerName;
        if (instruction == "ENTRA") {
            team.inserir(playerName);
        } else if (instruction == "SAI") {
            team.remover(playerName);
        } else if (instruction == "PRESENTE") {
            if (team.existe(playerName)) {
                cout << playerName << " esta no time.\n";
            } else {
                cout << playerName << " nao esta no time.\n";
            }
        }
    }

    Node* current = team.head;
    while (current != nullptr) {
        cout << current->name << "\n";
        current = current->next;
    }

    return 0;
}