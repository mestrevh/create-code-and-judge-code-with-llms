/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long ano, p;
    if (!(cin >> ano)) return 0;
    if (!(cin >> p)) return 0;

    for (int i = 1; i <= 3; i++) {
        long long y = ano + p * i;
        if (i > 1) cout << ' ';
        cout << y;
    }
    return 0;
}