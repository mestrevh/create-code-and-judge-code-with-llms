/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string senha;
    cout << "Digite a senha numerica: ";
    if (!(cin >> senha)) return 0;

    if (senha == "1234") cout << "ACESSO PERMITIDO";
    else cout << "ACESSO NEGADO";

    return 0;
}