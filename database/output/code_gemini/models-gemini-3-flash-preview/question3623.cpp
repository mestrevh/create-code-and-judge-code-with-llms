/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Vendedor {
    char nome[101];
    float vendas;
    int unidade;
    char gerente[101];
};

void buscarMelhorPior(Vendedor vetor[], int tamanho, Vendedor melhorpior[]) {
    if (tamanho <= 0) return;
    int melhorIdx = 0;
    int piorIdx = 0;
    for (int i = 1; i < tamanho; ++i) {
        if (vetor[i].vendas > vetor[melhorIdx].vendas) {
            melhorIdx = i;
        }
        if (vetor[i].vendas < vetor[piorIdx].vendas) {
            piorIdx = i;
        }
    }
    melhorpior[0] = vetor[melhorIdx];
    melhorpior[1] = vetor[piorIdx];
}

void buscarVendendor(char nome[], Vendedor vetor[], int tamanho) {
    bool encontrado = false;
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(vetor[i].nome, nome) == 0) {
            cout << "Nome: " << vetor[i].nome << "\n";
            cout << "Vendas: R$ " << fixed << setprecision(2) << vetor[i].vendas << "\n";
            cout << "Unidade: " << vetor[i].unidade << "\n";
            cout << "Gerente: " << vetor[i].gerente << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "NAO ENCONTRADO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    cin.ignore();

    Vendedor v[55];
    for (int i = 0; i < n; ++i) {
        cin.getline(v[i].nome, 101);
        cin >> v[i].vendas;
        cin >> v[i].unidade;
        cin.ignore();
        cin.getline(v[i].gerente, 101);
    }

    Vendedor mp[2];
    buscarMelhorPior(v, n, mp);

    cout << "Melhor vendedor: " << mp[0].nome << "\n";
    cout << "Vendas: R$ " << fixed << setprecision(2) << mp[0].vendas << "\n";
    cout << "Unidade: " << mp[0].unidade << "\n";
    cout << "Gerente: " << mp[0].gerente << "\n\n";

    cout << "Pior vendedor: " << mp[1].nome << "\n";
    cout << "Vendas: R$ " << fixed << setprecision(2) << mp[1].vendas << "\n";
    cout << "Unidade: " << mp[1].unidade << "\n";
    cout << "Gerente: " << mp[1].gerente << "\n";

    char busca[101];
    while (cin.getline(busca, 101) && strcmp(busca, "ok") != 0) {
        if (strlen(busca) == 0) continue;
        cout << "\n";
        buscarVendendor(busca, v, n);
    }

    return 0;
}