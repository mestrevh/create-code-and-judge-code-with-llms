/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Cliente {
    int codigo;
    char nome[30];
    float credito;
};

void preencher(Cliente& c) {
    cin >> c.codigo;
    string s;
    cin >> s;
    memset(c.nome, 0, sizeof(c.nome));
    strncpy(c.nome, s.c_str(), sizeof(c.nome) - 1);
    cin >> c.credito;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Cliente c;
    preencher(c);

    cout << c.codigo << "\n";
    cout << c.nome << "\n";
    cout << fixed << setprecision(2) << c.credito << "\n";
    return 0;
}