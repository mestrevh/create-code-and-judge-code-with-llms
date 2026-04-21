/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int maxLista(const vector<int>& L) {
    int mx = L[0];
    for (int i = 1; i < (int)L.size(); i++) {
        if (L[i] > mx) mx = L[i];
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> L(n);
    for (int i = 0; i < n; i++) cin >> L[i];

    cout << maxLista(L) << "\n";
    return 0;
}