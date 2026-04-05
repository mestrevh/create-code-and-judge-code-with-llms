/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    long long fd;
    Node* next;
    Node(const string& n, long long d) : name(n), fd(d), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string first;
    if (!(cin >> first)) return 0;

    while (true) {
        long long FI = stoll(first);
        string Ni;
        if (!(cin >> Ni)) return 0;
        if (Ni == "Fim") return 0;

        long long FD;
        cin >> FD;

        Node* head = new Node(Ni, FD);
        Node* tail = head;

        while (true) {
            string name;
            if (!(cin >> name)) break;
            if (name == "Fim") break;
            long long def;
            cin >> def;
            tail->next = new Node(name, def);
            tail = tail->next;
        }

        bool allPrisoned = true;
        Node* cur = head;

        while (cur && cur->next) {
            if (FI >= cur->fd) {
                cout << "Conseguimos interrogar " << cur->name << ", que nos entregou " << cur->next->name << ".\n";
                cur = cur->next;
            } else {
                allPrisoned = false;
                cout << "Droga, a busca acabou em " << cur->name << ".\n";
                break;
            }
        }

        if (allPrisoned) {
            if (cur) {
                if (cur->next == nullptr) {
                    if (FI >= cur->fd) {
                        cout << "Agora sim, com a confissao de " << cur->name << " prendemos todos os canalhas.\n";
                    } else {
                        cout << "Droga, a busca acabou em " << cur->name << ".\n";
                    }
                } else {
                    cout << "Agora sim, com a confissao de " << cur->name << " prendemos todos os canalhas.\n";
                }
            }
        }

        Node* del = head;
        while (del) {
            Node* nx = del->next;
            delete del;
            del = nx;
        }

        if (!(cin >> first)) break;
    }

    return 0;
}