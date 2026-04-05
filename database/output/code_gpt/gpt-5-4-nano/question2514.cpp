/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D;
    cout << "DIGITE O VALOR A: ";
    if (!(cin >> A)) return 0;
    cout << "DIGITE O VALOR B: ";
    cin >> B;
    cout << "DIGITE O VALOR C: ";
    cin >> C;
    cout << "DIGITE O VALOR D: ";
    cin >> D;

    long long diff = A * B - C * D;
    cout << "DIFERENCA = " << diff;
    return 0;
}