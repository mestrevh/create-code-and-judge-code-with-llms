/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    if (!(cin >> A >> B)) return 0;

    if (A == B) return 0;

    vector<long long> ans;
    while (A > B) {
        long long x = A - B;
        long long p = 1;
        while ((p << 1) > 0 && (p << 1) <= x) p <<= 1;
        if ((A - p) < B) break;
        ans.push_back(p);
        A -= p;
    }

    for (size_t i = 0; i < ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    return 0;
}