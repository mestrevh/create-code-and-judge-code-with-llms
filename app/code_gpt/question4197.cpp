/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string gerarSenha(string nome, string cpf) {
    string senha;
    for (int i = 0; i < nome.size(); i++) {
        char deslocado = (nome[i] - 'a' + (cpf[i] - '0')) % 26 + 'a';
        senha += deslocado;
    }
    senha += cpf.substr(9, 2);
    return senha;
}

int main() {
    int N;
    cin >> N;
    vector<pair<string, string>> alunos(N);
    
    for (int i = 0; i < N; i++) {
        cin >> alunos[i].first >> alunos[i].second;
        alunos[i].second = gerarSenha(alunos[i].first, alunos[i].second);
    }
    
    sort(alunos.begin(), alunos.end());
    
    for (const auto& aluno : alunos) {
        cout << aluno.first << " " << aluno.second << endl;
    }
    
    return 0;
}
