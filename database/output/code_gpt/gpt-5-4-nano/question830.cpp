/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double altura;
    cout << "Informe sua altura:\n";
    if (!(cin >> altura)) return 0;

    double peso = (72.7 * altura) - 58.0;
    cout << "Peso ideal: " << peso;
    return 0;
}