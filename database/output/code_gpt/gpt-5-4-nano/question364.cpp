/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long X, Y;
    if (!(cin >> X >> Y)) return 0;

    if (X >= 0 && X <= 432 && Y >= 0 && Y <= 468) cout << "dentro\n";
    else cout << "fora\n";
    return 0;
}