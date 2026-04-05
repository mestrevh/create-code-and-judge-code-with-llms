/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

size_t contarOcorrencias(int x, const vector<int>& L, size_t n) {
    size_t cnt = 0;
    for (size_t i = 0; i < n; ++i) {
        if (L[i] == x) ++cnt;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    if (!(cin >> x)) return 0;

    size_t n;
    cin >> n;

    vector<int> L(n);
    for (size_t i = 0; i < n; ++i) cin >> L[i];

    size_t ans = contarOcorrencias(x, L, n);
    cout << ans << "\n";
    return 0;
}