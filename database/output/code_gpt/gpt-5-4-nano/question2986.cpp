/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long year;
    string name;
    Node* next;
    Node(long long y, const string& n) : year(y), name(n), next(nullptr) {}
};

struct ListaEncadeada {
    Node* head = nullptr;
    Node* tail = nullptr;

    void inserirOrdenado(long long year, const string& name) {
        Node* novo = new Node(year, name);

        if (!head) {
            head = tail = novo;
            return;
        }

        Node* prev = nullptr;
        Node* cur = head;

        while (cur) {
            if (year < cur->year || (year == cur->year && name.compare(cur->name) < 0)) break;
            prev = cur;
            cur = cur->next;
        }

        if (!prev) {
            novo->next = head;
            head = novo;
        } else {
            prev->next = novo;
            novo->next = cur;
            if (!cur) tail = novo;
        }
    }

    void imprimir() const {
        Node* cur = head;
        while (cur) {
            cout << cur->year << " - " << cur->name << "\n";
            cur = cur->next;
        }
    }

    ~ListaEncadeada() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ListaEncadeada lista;

    string name;
    while (getline(cin, name)) {
        if (!cin) break;
        if (name.size() == 0) continue;

        string yearLine;
        if (!getline(cin, yearLine)) break;

        while (yearLine.size() == 0) {
            if (!getline(cin, yearLine)) break;
        }
        if (yearLine.size() == 0) break;

        long long year = 0;
        try {
            year = stoll(yearLine);
        } catch (...) {
            continue;
        }

        lista.inserirOrdenado(year, name);
    }

    lista.imprimir();
    return 0;
}