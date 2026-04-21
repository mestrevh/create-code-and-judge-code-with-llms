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
    if (!(cin >> N)) return 0;
    while (N--) {
        int T;
        cin >> T;
        vector<long long> h(T), c(T);
        for (int i = 0; i < T; i++) cin >> h[i];
        for (int i = 0; i < T; i++) cin >> c[i];

        vector<pair<long long,long long>> a(T);
        for (int i = 0; i < T; i++) a[i] = {h[i], c[i]};
        sort(a.begin(), a.end());

        long long totalW = 0;
        for (auto &p : a) totalW += p.second;

        long long prefW = 0, prefCost = 0;
        vector<long long> xs(T), ws(T);
        for (int i = 0; i < T; i++) { xs[i] = a[i].first; ws[i] = a[i].second; }

        for (int i = 0; i < T; i++) {
            prefCost += ws[i] * xs[i];
            prefW += ws[i];
        }
        long long totalWeightedX = prefCost;

        long long best = LLONG_MAX;
        long long leftW = 0;
        long long leftWeightedX = 0;
        for (int i = 0; i < T; i++) {
            long long x = xs[i];
            long long w = ws[i];

            long long rightW = totalW - leftW - w;
            long long rightWeightedX = totalWeightedX - leftWeightedX - w * x;

            long long cost = 0;
            cost += (x * leftW - leftWeightedX);
            cost += (rightWeightedX - x * rightW);

            best = min(best, cost);

            leftW += w;
            leftWeightedX += w * x;
        }

        cout << best << "\n";
    }
    return 0;
}