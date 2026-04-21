/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    string nome;
    int nota;
    Node* next;
    Node(const string& n, int t) : nome(n), nota(t), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;

    auto insertSortedDesc = [&](const string& nome, int nota) {
        Node* novo = new Node(nome, nota);
        if (!head || head->nota < nota) {
            novo->next = head;
            head = novo;
            return;
        }
        Node* cur = head;
        while (cur->next && cur->next->nota >= nota) cur = cur->next;
        novo->next = cur->next;
        cur->next = novo;
    };

    string cmd;
    while (cin >> cmd) {
        if (cmd == "sair") break;
        if (cmd == "inserir") {
            string nome;
            int nota;
            cin >> nome >> nota;
            insertSortedDesc(nome, nota);
            cout << nome << " foi inserido no sistema! Sua nota e de " << nota << ".\n";
        } else if (cmd == "imprimir") {
            Node* cur = head;
            while (cur) {
                cout << cur->nome << " " << cur->nota;
                if (cur->next) cout << "\n";
                cur = cur->next;
            }
        }
    }

    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    return 0;
}