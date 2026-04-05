/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> diag;
    diag.reserve(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long val;
            cin >> val;
            if (i == j) diag.push_back(val);
        }
    }

    vector<long long> B;
    for (long long v : diag) {
        if (x == 0) {
            if (v == 0) B.push_back(v);
        } else {
            if (v % x == 0) B.push_back(v);
        }
    }

    if (B.empty()) {
        cout << "NMDX";
        return 0;
    }

    for (size_t i = 0; i < B.size(); i++) {
        if (i) cout << ' ';
        cout << B[i];
    }
    return 0;
}