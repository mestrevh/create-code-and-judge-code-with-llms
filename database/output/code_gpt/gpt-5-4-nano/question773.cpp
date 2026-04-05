/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

class HuxleyCode {
public:
    int dado;
    HuxleyCode* proximo;

    HuxleyCode(int v) : dado(v), proximo(nullptr) {}

    void inserir(int v) {
        if (v <= dado) {
            HuxleyCode* n = new HuxleyCode(v);
            n->proximo = this;
            dado = this->dado;
            proximo = this->proximo;
        }
    }

    void inserirOrdenado(int v) {
        if (v <= dado) {
            if (v == dado) {
                HuxleyCode* n = new HuxleyCode(v);
                n->proximo = proximo;
                proximo = n;
            } else {
                HuxleyCode* n = new HuxleyCode(dado);
                n->proximo = proximo;
                proximo = n;
                dado = v;
            }
            return;
        }
        if (!proximo) {
            proximo = new HuxleyCode(v);
            return;
        }
        if (v <= proximo->dado) {
            HuxleyCode* n = new HuxleyCode(v);
            n->proximo = proximo;
            proximo = n;
            return;
        }
        proximo->inserirOrdenado(v);
    }

    void imprimir() const {
        cout << dado << "\n";
        if (proximo) proximo->imprimir();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int x;
    cin >> x;
    HuxleyCode* head = new HuxleyCode(x);

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x <= head->dado) {
            if (x == head->dado) {
                HuxleyCode* node = new HuxleyCode(x);
                node->proximo = head->proximo;
                head->proximo = node;
            } else {
                HuxleyCode* nnode = new HuxleyCode(head->dado);
                nnode->proximo = head->proximo;
                head->proximo = nnode;
                head->dado = x;
            }
        } else {
            head->inserirOrdenado(x);
        }
    }

    head->imprimir();
    return 0;
}