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
    while ( (cin >> N) ) {
        if (N == 0) break;

        vector<long long> vals;
        vals.reserve(N * 2);

        for (int i = 0; i < N; i++) {
            long long C, V;
            cin >> C >> V;
            vals.push_back(C);
            vals.push_back(V);
        }

        vector<pair<long long,long long>> a;
        a.reserve(N);
        for (int i = 0; i < 2*N; i += 2) {
            a.push_back({vals[i], vals[i+1]});
        }
        sort(a.begin(), a.end());

        unordered_map<long long, long long> cnt;
        cnt.reserve(N * 2);
        for (auto &p : a) cnt[p.first] = p.second;

        int M = (int)a.size();
        vector<long long> C(M), V(M);
        for (int i = 0; i < M; i++) { C[i] = a[i].first; V[i] = a[i].second; }

        vector<long long> sides;
        sides.reserve(2000000);

        for (int i = 0; i < M; i++) {
            long long c = C[i], v = V[i];
            while (v--) sides.push_back(c);
        }

        sort(sides.begin(), sides.end());

        int m = (int)sides.size();
        long long ans = 0;

        multiset<long long> ms;
        for (int i = 0; i < m; i++) ms.insert(sides[i]);

        vector<long long> pairs;
        pairs.reserve(m/2);

        while (!ms.empty()) {
            auto it = ms.begin();
            long long x = *it;
            ms.erase(it);
            it = ms.begin();
            if (ms.empty()) break;
            auto it2 = ms.lower_bound(x);
            if (it2 == ms.end()) break;
            long long y = *it2;
            ms.erase(it2);
            pairs.push_back(y);
        }

        sort(pairs.begin(), pairs.end());

        vector<long long> pool;
        pool.reserve(pairs.size());
        for (auto &x : pairs) pool.push_back(x);

        int p = (int)pool.size();
        for (int i = 0; i + 1 < p; i += 2) {
            ans += 1;
        }

        cout << ans << "\n";
    }
    return 0;
}