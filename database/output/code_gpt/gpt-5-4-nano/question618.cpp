/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick() : n(0) {}
    Fenwick(int n_) { init(n_); }
    void init(int n_) { n = n_; bit.assign(n + 1, 0); }
    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }
    int sumPrefix(int idx) const {
        int s = 0;
        for (; idx > 0; idx -= idx & -idx) s += bit[idx];
        return s;
    }
    int sumRange(int l, int r) const {
        if (l > r) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    string S;
    cin >> S;

    vector<Fenwick> fw(26);
    for (int c = 0; c < 26; c++) fw[c].init(N);

    for (int i = 0; i < N; i++) {
        int c = S[i] - 'a';
        fw[c].add(i + 1, 1);
    }

    int mask = 0;
    vector<int> parity(26, 0);
    for (int c = 0; c < 26; c++) {
        int cnt = fw[c].sumRange(1, N);
        parity[c] = cnt & 1;
        if (parity[c]) mask |= (1 << c);
    }

    auto rangeMask = [&](int l, int r) -> int {
        int m = 0;
        for (int c = 0; c < 26; c++) {
            int cnt = fw[c].sumRange(l, r);
            if (cnt & 1) m |= (1 << c);
        }
        return m;
    };

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int L;
            char x;
            cin >> L >> x;
            int idx = L - 1;
            int oldc = S[idx] - 'a';
            int newc = x - 'a';
            if (oldc != newc) {
                fw[oldc].add(L, -1);
                fw[newc].add(L, 1);
                S[idx] = x;
            }
        } else {
            int L, R;
            cin >> L >> R;
            int m = rangeMask(L, R);
            int oddCount = __builtin_popcount((unsigned)m);
            if (oddCount <= 1) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}