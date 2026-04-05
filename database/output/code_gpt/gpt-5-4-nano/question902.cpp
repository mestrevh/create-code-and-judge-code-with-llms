/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long base, expoente;
    cout << "Informe a base:";
    if (!(cin >> base)) return 0;
    cout << "Informe o expoente:";
    if (!(cin >> expoente)) return 0;

    long long resultado = 1;
    for (long long i = 0; i < expoente; i++) resultado *= base;

    cout << "Resultado: " << resultado;
    return 0;
}