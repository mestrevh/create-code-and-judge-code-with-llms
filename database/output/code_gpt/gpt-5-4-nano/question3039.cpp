/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C[4];
    for (int i = 0; i < 4; i++) {
        if (!(cin >> C[i])) return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (C[i] == 1) {
            cout << (i + 1) << "\n";
            return 0;
        }
    }
    return 0;
}