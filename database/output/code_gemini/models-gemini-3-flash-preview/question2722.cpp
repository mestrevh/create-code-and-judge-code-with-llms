/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int fd;
    Node* next;
    Node(string n, int f) : name(n), fd(f), next(NULL) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int fi;
    if (!(cin >> fi)) return 0;

    string name;
    Node* head = NULL;
    Node* tail = NULL;

    while (cin >> name && name != "Fim") {
        int fd;
        if (!(cin >> fd)) break;
        Node* newNode = new Node(name, fd);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* curr = head;
    while (curr) {
        if (fi >= curr->fd) {
            if (curr->next) {
                cout << "Conseguimos interrogar " << curr->name << ", que nos entregou " << curr->next->name << "." << endl;
            } else {
                cout << "Agora sim, com a confissao de " << curr->name << ", prendemos todos os canalhas." << endl;
            }
        } else {
            cout << "Droga, a busca acabou em " << curr->name << "." << endl;
            break;
        }
        curr = curr->next;
    }

    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}