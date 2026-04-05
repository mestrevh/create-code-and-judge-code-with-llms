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
    long long c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    while (true) {
        cout << "Digite um numero inteiro:";
        if (!(cin >> x)) break;
        if (x < 0) break;

        if (0 <= x && x <= 25) c1++;
        else if (26 <= x && x <= 50) c2++;
        else if (51 <= x && x <= 75) c3++;
        else if (76 <= x && x <= 100) c4++;
    }

    cout << "Quantidade de numeros no intervalo 1: " << c1 << "\n";
    cout << "Quantidade de numeros no intervalo 2: " << c2 << "\n";
    cout << "Quantidade de numeros no intervalo 3: " << c3 << "\n";
    cout << "Quantidade de numeros no intervalo 4: " << c4 << "\n";
    return 0;
}