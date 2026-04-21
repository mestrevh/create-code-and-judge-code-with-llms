/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, C;
    cin >> L >> C;

    long long tipo1 = L * C + (L - 1) * (C - 1);
    long long tipo2 = 2 * (L - 1) + 2 * (C - 1);

    cout << tipo1 << '\n' << tipo2 << '\n';
    return 0;
}