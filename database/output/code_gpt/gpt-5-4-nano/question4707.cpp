/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void saudacoes(const string& nome) {
    cout << "Olá, " << nome << "! Seja bem-vindo";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nome;
    if (getline(cin, nome)) {
        if (!nome.empty() && nome.back() == '\r') nome.pop_back();
        saudacoes(nome);
    }
    return 0;
}