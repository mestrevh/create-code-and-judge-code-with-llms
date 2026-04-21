/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double largura, comprimento, altura;
    cout << "Digite a largura da bagagem: ";
    if (!(cin >> largura)) return 0;
    cout << "Digite o comprimento da bagagem: ";
    cin >> comprimento;
    cout << "Digite a altura da bagagem: ";
    cin >> altura;

    if (largura <= 45.0 && comprimento <= 56.0 && altura <= 25.0) {
        cout << "BAGAGEM PERMITIDA";
    } else {
        cout << "BAGAGEM PROIBIDA";
    }
    return 0;
}