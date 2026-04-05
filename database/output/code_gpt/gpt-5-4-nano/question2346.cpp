/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void imprimir(int n) {
    for (int i = 0; i < n; i++) {
        int val = n - i;
        int count = n - i;
        for (int j = 0; j < count; j++) {
            if (j) cout << '-';
            cout << val;
        }
        if (i + 1 < n) cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    imprimir(n);
    return 0;
}