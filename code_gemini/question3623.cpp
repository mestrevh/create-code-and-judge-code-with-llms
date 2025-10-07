/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Vendedor {
    char nome[51];
    float vendas;
    int unidade;
    char gerente[51];
};

void buscarMelhorPior(Vendedor vetor[], int tamanho, Vendedor melhorpior[]) {
    if (tamanho <= 0) {
        return;
    }

    int indiceMelhor = 0;
    int indicePior = 0;

    for (int i = 1; i < tamanho; ++i) {
        if (vetor[i].vendas > vetor[indiceMelhor].vendas) {
            indiceMelhor = i;
        }
        if (vetor[i].vendas < vetor[indicePior].vendas) {
            indicePior = i;
        }
    }

    melhorpior[0] = vetor[indiceMelhor];
    melhorpior[1] = vetor[indicePior];
}

void buscarVendedor(char nome[], Vendedor vetor[], int tamanho) {
    bool encontrado = false;
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(vetor[i].nome, nome) == 0) {
            cout << "Nome: " << vetor[i].nome << endl;
            cout << "Vendas: R$ " << fixed << setprecision(2) << vetor[i].vendas << endl;
            cout << "Unidade: " << vetor[i].unidade << endl;
            cout << "Gerente: " << vetor[i].gerente << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "NAO ENCONTRADO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    Vendedor vendedores[50];
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        cin.getline(vendedores[i].nome, 51);
        cin >> vendedores[i].vendas;
        cin >> vendedores[i].unidade;
        cin.ignore(); 
        cin.getline(vendedores[i].gerente, 51);
    }

    Vendedor melhorpior[2];
    buscarMelhorPior(vendedores, n, melhorpior);

    cout << "Melhor vendedor: " << melhorpior[0].nome << endl;
    cout << "Vendas: R$ " << fixed << setprecision(2) << melhorpior[0].vendas << endl;
    cout << "Unidade: " << melhorpior[0].unidade << endl;
    cout << "Gerente: " << melhorpior[0].gerente << endl;
    cout << endl;

    cout << "Pior vendedor: " << melhorpior[1].nome << endl;
    cout << "Vendas: R$ " << fixed << setprecision(2) << melhorpior[1].vendas << endl;
    cout << "Unidade: " << melhorpior[1].unidade << endl;
    cout << "Gerente: " << melhorpior[1].gerente << endl;

    char nomeBusca[51];
    while (cin.getline(nomeBusca, 51) && strcmp(nomeBusca, "ok") != 0) {
        cout << endl;
        buscarVendedor(nomeBusca, vendedores, n);
    }

    return 0;
}
