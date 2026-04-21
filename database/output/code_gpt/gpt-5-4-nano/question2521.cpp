/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double peso, altura;
    if (!(cin >> peso >> altura)) {
        return 0;
    }

    double imc = peso / (altura * altura);

    cout.setf(ios::fixed);
    cout << setprecision(1) << imc;

    return 0;
}