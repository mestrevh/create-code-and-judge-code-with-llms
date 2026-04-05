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
    if (!(cin >> n)) return 0;

    vector<pair<long double, int>> events;
    events.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        long double a, b;
        cin >> a >> b;
        events.push_back({a, +1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end(), [](const auto& x, const auto& y) {
        if (x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    int cur = 0, ans = 0;
    for (auto &e : events) {
        cur += e.second;
        if (cur > ans) ans = cur;
    }

    cout << ans << "\n";
    return 0;
}