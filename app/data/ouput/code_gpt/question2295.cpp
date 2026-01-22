/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TPilhaDupla {
private:
    vector<int> pilha;
    int topoEsquerda;
    int topoDireita;

public:
    TPilhaDupla(int tamanho) {
        pilha.resize(tamanho);
        topoEsquerda = -1;
        topoDireita = tamanho;
    }

    void empilhar(char lado, int valor) {
        if (lado == 'e') {
            if (topoEsquerda + 1 < topoDireita) {
                pilha[++topoEsquerda] = valor;
            }
        } else if (lado == 'd') {
            if (topoEsquerda + 1 < topoDireita) {
                pilha[--topoDireita] = valor;
            }
        }
    }

    int desempilhar(char lado) {
        if (lado == 'e') {
            if (topoEsquerda >= 0) {
                return pilha[topoEsquerda--];
            }
        } else if (lado == 'd') {
            if (topoDireita < pilha.size()) {
                return pilha[topoDireita++];
            }
        }
        return -1; // Para quando a pilha está vazia
    }
};

int main() {
    int n;
    cin >> n;
    TPilhaDupla pilhaDupla(n);
    
    for (int i = 0; i < n; i++) {
        char operacao;
        cin >> operacao;

        if (operacao == 'E') {
            char lado;
            int valor;
            cin >> lado >> valor;
            pilhaDupla.empilhar(lado, valor);
        } else if (operacao == 'D') {
            char lado;
            cin >> lado;
            cout << pilhaDupla.desempilhar(lado) << endl;
        }
    }

    return 0;
}
