/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>
using namespace std;

struct Vendedor {
    char nome[51];
    float vendas;
    int unidade;
    char gerente[51];
};

struct VendedorMelhorPior {
    char nome[51];
    float vendas;
    int unidade;
    char gerente[51];
};

void buscarMelhorPior(Vendedor vetor[], int tamanho, VendedorMelhorPior melhorpior[]) {
    int melhorIndex = 0, piorIndex = 0;
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i].vendas > vetor[melhorIndex].vendas) {
            melhorIndex = i;
        }
        if (vetor[i].vendas < vetor[piorIndex].vendas) {
            piorIndex = i;
        }
    }
    strcpy(melhorpior[0].nome, vetor[melhorIndex].nome);
    melhorpior[0].vendas = vetor[melhorIndex].vendas;
    melhorpior[0].unidade = vetor[melhorIndex].unidade;
    strcpy(melhorpior[0].gerente, vetor[melhorIndex].gerente);
    
    strcpy(melhorpior[1].nome, vetor[piorIndex].nome);
    melhorpior[1].vendas = vetor[piorIndex].vendas;
    melhorpior[1].unidade = vetor[piorIndex].unidade;
    strcpy(melhorpior[1].gerente, vetor[piorIndex].gerente);
}

void buscarVendedor(char nome[], Vendedor vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(vetor[i].nome, nome) == 0) {
            cout << "Nome: " << vetor[i].nome << endl;
            cout << "Vendas: R$ " << vetor[i].vendas << endl;
            cout << "Unidade: " << vetor[i].unidade << endl;
            cout << "Gerente: " << vetor[i].gerente << endl;
            return;
        }
    }
    cout << "NAO ENCONTRADO" << endl;
}

int main() {
    int n;
    cout << "Quantidade de vendedores cadastrados: ";
    cin >> n;
    Vendedor vendedores[n];
    
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(vendedores[i].nome, 51);
        cin >> vendedores[i].vendas;
        cin >> vendedores[i].unidade;
        cin.ignore();
        cin.getline(vendedores[i].gerente, 51);
    }
    
    VendedorMelhorPior melhorPior[2];
    buscarMelhorPior(vendedores, n, melhorPior);
    
    cout << "Melhor vendedor: " << melhorPior[0].nome << endl;
    cout << "Vendas: R$ " << melhorPior[0].vendas << endl;
    cout << "Unidade: " << melhorPior[0].unidade << endl;
    cout << "Gerente: " << melhorPior[0].gerente << endl << endl;

    cout << "Pior vendedor: " << melhorPior[1].nome << endl;
    cout << "Vendas: R$ " << melhorPior[1].vendas << endl;
    cout << "Unidade: " << melhorPior[1].unidade << endl;
    cout << "Gerente: " << melhorPior[1].gerente << endl << endl;

    char nomeBusca[51];
    while (true) {
        cin.getline(nomeBusca, 51);
        if (strcmp(nomeBusca, "ok") == 0) {
            break;
        }
        buscarVendedor(nomeBusca, vendedores, n);
        cout << endl;
    }

    return 0;
}
