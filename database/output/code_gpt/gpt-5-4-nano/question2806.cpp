/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double massa, altura;
    if (!(cin >> massa)) return 0;
    if (!(cin >> altura)) return 0;

    double imc = massa / (altura * altura);
    long long n = llround(imc);

    cout << "Digite a massa em kg e altura em m:\n";
    cout << "IMC: " << n;
    return 0;
}