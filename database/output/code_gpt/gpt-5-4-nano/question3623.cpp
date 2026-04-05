/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Vendedor {
    string nome;
    float vendas;
    int unidade;
    string gerente;
};

void buscarMelhorPior(Vendedor vetor[], int tamanho, Vendedor melhorpior[]) {
    int idxMelhor = 0, idxPior = 0;
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i].vendas > vetor[idxMelhor].vendas) idxMelhor = i;
        if (vetor[i].vendas < vetor[idxPior].vendas) idxPior = i;
    }
    melhorpior[0] = vetor[idxMelhor];
    melhorpior[1] = vetor[idxPior];
}

void buscarVendendor(char nome[], Vendedor vetor[], int tamanho) {
    string target = string(nome);
    bool encontrado = false;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i].nome == target) {
            encontrado = true;
            cout << "Nome: " << vetor[i].nome << "\n";
            cout << "Vendas: R$ " << fixed << setprecision(2) << vetor[i].vendas << "\n";
            cout << "Unidade: " << vetor[i].unidade << "\n";
            cout << "Gerente: " << vetor[i].gerente << "\n\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "NAO ENCONTRADO\n\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Vendedor> vendedores(n);
    for (int i = 0; i < n; i++) {
        getline(cin, vendedores[i].nome);
        string line;
        getline(cin, line);
        while (line.size() == 0 && !cin.eof()) getline(cin, line);
        vendedores[i].vendas = stof(line);

        getline(cin, line);
        while (line.size() == 0 && !cin.eof()) getline(cin, line);
        vendedores[i].unidade = stoi(line);

        getline(cin, vendedores[i].gerente);
    }

    Vendedor melhorpior[2];
    buscarMelhorPior(vendedores.data(), n, melhorpior);

    cout << "Melhor vendedor: " << melhorpior[0].nome << "\n";
    cout << "Vendas: R$ " << fixed << setprecision(2) << melhorpior[0].vendas << "\n";
    cout << "Unidade: " << melhorpior[0].unidade << "\n";
    cout << "Gerente: " << melhorpior[0].gerente << "\n\n";

    cout << "Pior vendedor: " << melhorpior[1].nome << "\n";
    cout << "Vendas: R$ " << fixed << setprecision(2) << melhorpior[1].vendas << "\n";
    cout << "Unidade: " << melhorpior[1].unidade << "\n";
    cout << "Gerente: " << melhorpior[1].gerente << "\n\n";

    vector<string> queries;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) continue;
        queries.push_back(s);
    }

    for (const string& q : queries) {
        char nome[60];
        memset(nome, 0, sizeof(nome));
        strncpy(nome, q.c_str(), sizeof(nome) - 1);
        if (q == "ok") break;
        buscarVendendor(nome, vendedores.data(), n);
    }

    return 0;
}