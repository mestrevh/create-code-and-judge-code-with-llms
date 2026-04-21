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

    vector<pair<int,int>> a;
    a.reserve(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    sort(a.begin(), a.end(), [](const auto& p1, const auto& p2){
        if (p1.second != p2.second) return p1.second < p2.second;
        return p1.first < p2.first;
    });

    int ans = 0;
    int lastEnd = 0;
    bool hasLast = false;

    for (auto &p : a) {
        int s = p.first, e = p.second;
        if (!hasLast || s >= lastEnd) {
            ans++;
            lastEnd = e;
            hasLast = true;
        }
    }

    cout << ans << "\n";
    return 0;
}