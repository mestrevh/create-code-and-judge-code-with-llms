/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    if (!(cin >> c)) return 0;

    if (c == 'M' || c == 'm') cout << "Masculino";
    else if (c == 'F' || c == 'f') cout << "Feminino";
    else cout << "Genero nao especificado";

    return 0;
}