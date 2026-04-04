/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Aluno {
    string nome;
    string senha;
};

bool compararAlunos(const Aluno& a, const Aluno& b) {
    return a.nome < b.nome;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Aluno> lista(N);
    for (int i = 0; i < N; ++i) {
        string nome, cpf;
        cin >> nome >> cpf;
        lista[i].nome = nome;
        
        string s = "";
        int len = nome.length();
        for (int j = 0; j < len; ++j) {
            int p = cpf[j] - '0';
            char c = (char)(((nome[j] - 'a') + p) % 26 + 'a');
            s += c;
        }
        s += cpf[9];
        s += cpf[10];
        lista[i].senha = s;
    }

    sort(lista.begin(), lista.end(), compararAlunos);

    for (int i = 0; i < N; ++i) {
        cout << lista[i].nome << " " << lista[i].senha << "\n";
    }

    return 0;
}

