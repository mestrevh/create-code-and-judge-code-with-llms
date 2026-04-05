/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    if (!(cin >> Q)) return 0;
    vector<int> v(Q);
    for (int i = 0; i < Q; i++) cin >> v[i];

    if (Q == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int best = 1, cur = 1;
    for (int i = 1; i < Q; i++) {
        if (v[i] > v[i - 1]) {
            cur++;
        } else {
            best = max(best, cur);
            cur = 1;
        }
    }
    best = max(best, cur);

    cout << best << "\n";
    return 0;
}