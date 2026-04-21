/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double D;
    if (!(cin >> D)) return 0;

    cout << fixed << setprecision(2);
    cout << D * 0.60 << "\n" << D * 0.30 << "\n" << D * 0.10;
    return 0;
}