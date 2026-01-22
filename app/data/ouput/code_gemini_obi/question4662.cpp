/*
Código criado pelo modelo gemini-2.5-pro
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, C;
    cin >> N >> M >> C;
    vector<int> mask(N, 0);
    vector<pair<int, int>> segs(M);
    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        segs[i] = {l, r};
        for (int j = l; j <= r; ++j) {
            mask[j] |= (1 << i);
        }
    }
    // Troque para unordered_set para desempenho
    unordered_set<int> uniq;
    for (int i = 0; i < N; ++i) uniq.insert(mask[i]);
    vector<int> vec;
    for (int m : uniq) if (m) vec.push_back(m);
    int k = vec.size();
    map<int, int> rep;
    for (int i = 0; i < k; ++i) rep[vec[i]] = i;
    vector<vector<int>> pos(k);
    for (int i = 0; i < N; ++i) {
        if (mask[i]) pos[rep[mask[i]]].push_back(i);
    }
    // O problema se resume em colorir k blocos independentes de segmentos em C cores
    cout << (long long)pow(C, k) % MOD << '\n';
    return 0;
}
