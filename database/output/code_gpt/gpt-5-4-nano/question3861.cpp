/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int idade;
    while (cin >> idade) {
        if (idade == 0) break;

        if (idade < 0) {
            cout << "Pessoa ainda nao nasceu." << '\n';
        } else if (idade <= 11) {
            cout << "Você é uma criança." << '\n';
        } else if (idade <= 17) {
            cout << "Você é um adolescente." << '\n';
        } else if (idade <= 35) {
            cout << "Você é um jovem." << '\n';
        } else if (idade <= 64) {
            cout << "Você é um adulto." << '\n';
        } else {
            cout << "Você é um idoso." << '\n';
        }
    }
    return 0;
}