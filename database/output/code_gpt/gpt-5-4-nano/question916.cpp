/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    while (true) {
        cout << "Digite um numero (negativo para parar o programa):" << "\n";
        if (!(cin >> x)) return 0;
        if (x < 0) break;
        cout << "Numero: " << x << "\n";
    }
    return 0;
}