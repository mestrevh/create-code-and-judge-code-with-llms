/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

class HuxleyCode {
public:
    int dado;
    HuxleyCode* proximo;

    HuxleyCode() : proximo(nullptr) {}

    void inserir(int valor) {
        if (!proximo || proximo->dado > valor) {
            HuxleyCode* novo = new HuxleyCode();
            novo->dado = valor;
            novo->proximo = proximo;
            proximo = novo;
        } else {
            proximo->inserir(valor);
        }
    }

    void imprimir() {
        if (proximo) {
            cout << proximo->dado << endl;
            proximo->imprimir();
        }
    }
};

int main() {
    HuxleyCode lista;
    int n, valor;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> valor;
        lista.inserir(valor);
    }
    lista.imprimir();
    return 0;
}
