/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

void reduzirParaDez(vector<int>& V, int n) {
    for (int i = 0; i < n; i++) {
        if (V[i] > 10) V[i] = 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> V(n);
    for (int i = 0; i < n; i++) cin >> V[i];

    reduzirParaDez(V, n);

    for (int i = 0; i < n; i++) {
        if (i) cout << "\n";
        cout << V[i];
    }
    return 0;
}