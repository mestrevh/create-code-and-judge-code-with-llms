/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

class ListaNomes {
    struct No {
        string nome;
        No* prox;
        No(const string& n) : nome(n), prox(nullptr) {}
    };
    No* head;
    No* tail;
    int sz;

public:
    ListaNomes() : head(nullptr), tail(nullptr), sz(0) {}

    ~ListaNomes() {
        No* cur = head;
        while (cur) {
            No* nxt = cur->prox;
            delete cur;
            cur = nxt;
        }
    }

    void inserir(const string& nome) {
        No* novo = new No(nome);
        if (!head) {
            head = tail = novo;
        } else {
            tail->prox = novo;
            tail = novo;
        }
        sz++;
    }

    bool remover(const string& nome) {
        No* cur = head;
        No* prev = nullptr;
        while (cur) {
            if (cur->nome == nome) {
                if (prev) prev->prox = cur->prox;
                else head = cur->prox;
                if (cur == tail) tail = prev;
                delete cur;
                sz--;
                return true;
            }
            prev = cur;
            cur = cur->prox;
        }
        return false;
    }

    bool existe(const string& nome) const {
        No* cur = head;
        while (cur) {
            if (cur->nome == nome) return true;
            cur = cur->prox;
        }
        return false;
    }

    void imprimirFinal() const {
        No* cur = head;
        while (cur) {
            cout << cur->nome;
            cur = cur->prox;
            if (cur) cout << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    if (!(cin >> X)) return 0;

    ListaNomes lista;
    string instr, nome;
    for (int i = 0; i < X; i++) {
        cin >> instr >> nome;
        if (instr == "ENTRA") {
            lista.inserir(nome);
        } else if (instr == "SAI") {
            lista.remover(nome);
        } else if (instr == "PRESENTE") {
            if (lista.existe(nome)) cout << nome << " esta no time.\n";
            else cout << nome << " nao esta no time.\n";
        }
    }

    if (X > 0) lista.imprimirFinal();
    return 0;
}