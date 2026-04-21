/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, C;
    char X;
    if (!(cin >> L)) return 0;
    cin >> C;
    cin >> X;

    for (long long i = 0; i < L; i++) {
        for (long long j = 0; j < C; j++) cout << X;
        if (i + 1 < L) cout << "\n";
    }
    return 0;
}