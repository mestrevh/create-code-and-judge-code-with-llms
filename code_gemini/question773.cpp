/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

class HuxleyCode {
public:
    int dado;
    HuxleyCode* proximo;

    HuxleyCode(int val) : dado(val), proximo(nullptr) {}

    void inserir(int valor) {
        if (proximo == nullptr || valor <= proximo->dado) {
            HuxleyCode* novoNo = new HuxleyCode(valor);
            novoNo->proximo = proximo;
            proximo = novoNo;
        } else {
            proximo->inserir(valor);
        }
    }

    void imprimir() {
        std::cout << dado << std::endl;
        if (proximo != nullptr) {
            proximo->imprimir();
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    HuxleyCode* lista = new HuxleyCode(0); 

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int valor;
        std::cin >> valor;
        lista->inserir(valor);
    }

    if (lista->proximo != nullptr) {
        lista->proximo->imprimir();
    }

    return 0;
}
