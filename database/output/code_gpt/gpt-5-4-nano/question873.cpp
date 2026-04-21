/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int M;
    if (!(cin >> N >> M)) return 0;

    vector<long long> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    vector<long long> a = V;
    vector<long long> sorted = a;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    int K = (int)sorted.size();
    vector<int> comp(N);
    for (int i = 0; i < N; i++) {
        comp[i] = (int)(lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin());
    }

    vector<long long> bit(K + 1, 0);
    auto add = [&](int idx, long long val) {
        for (int i = idx + 1; i <= K; i += i & -i) bit[i] += val;
    };
    auto sum = [&](int idx) -> long long {
        long long r = 0;
        for (int i = idx + 1; i > 0; i -= i & -i) r += bit[i];
        return r;
    };

    long long I = 0;
    for (int i = 0; i < N; i++) {
        int x = comp[i];
        long long leq = sum(x);
        long long prev = i;
        I += (prev - leq);
        add(x, 1);
    }

    vector<char> used(M, 0);
    long long Imod = I % M;

    for (int i = 0; i < N; i++) {
        long long x = V[i] % M;
        long long cur = x;
        while (used[(int)cur]) {
            cur = (cur + Imod) % M;
        }
        used[(int)cur] = 1;
        cout << cur << "\n";
    }

    return 0;
}