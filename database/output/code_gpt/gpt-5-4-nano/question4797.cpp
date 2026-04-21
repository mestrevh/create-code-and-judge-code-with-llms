/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char letra;
    long long inteiro;
    double d1, d2;
    if (!(cin >> letra >> inteiro >> d1 >> d2)) return 0;

    cout << fixed << setprecision(2) << d2 << ' ' << d1 << ' ' << inteiro << ' ' << letra << "\n";
    return 0;
}