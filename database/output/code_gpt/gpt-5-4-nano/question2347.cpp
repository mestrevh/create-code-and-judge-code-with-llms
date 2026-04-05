/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void exibirLinhas(int n) {
    int primeiro = 1;
    for (int i = 0; i < n; i++) {
        int val = primeiro + i;
        for (int j = 0; j < n - i; j++) {
            if (j) cout << '-';
            cout << val;
        }
        if (i < n - 1) cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    exibirLinhas(n);
    return 0;
}