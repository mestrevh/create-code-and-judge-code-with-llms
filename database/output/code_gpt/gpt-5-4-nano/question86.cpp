/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static int invCount(const string& s) {
    int j = (int)s.size();
    int pos[256];
    for (int i = 0; i < 256; i++) pos[i] = -1;
    pos[(unsigned char)'A'] = 0;
    pos[(unsigned char)'C'] = 1;
    pos[(unsigned char)'G'] = 2;
    pos[(unsigned char)'T'] = 3;

    array<int,4> cnt{};
    cnt.fill(0);
    long long inv = 0;

    for (int i = j - 1; i >= 0; --i) {
        int v = pos[(unsigned char)s[i]];
        for (int x = 0; x < v; ++x) inv += cnt[x];
        cnt[v]++;
    }
    return (int)inv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M)) return 0;

    for (int tc = 0; tc < M; ++tc) {
        int j, k;
        cin >> j >> k;

        vector<string> s(k);
        for (int i = 0; i < k; ++i) cin >> s[i];

        vector<int> inv(k);
        for (int i = 0; i < k; ++i) inv[i] = invCount(s[i]);

        vector<int> idx(k);
        iota(idx.begin(), idx.end(), 0);

        stable_sort(idx.begin(), idx.end(), [&](int a, int b){
            return inv[a] < inv[b];
        });

        for (int t = 0; t < k; ++t) {
            cout << s[idx[t]] << "\n";
        }
        if (tc + 1 < M) cout << "\n";
    }
    return 0;
}