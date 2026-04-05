/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < N; i++) cin >> b[i];

        vector<pair<int,int>> events;
        events.reserve(2 * N);
        for (int i = 0; i < N; i++) {
            events.push_back({a[i], 1});
            events.push_back({b[i], -1});
        }
        sort(events.begin(), events.end(), [](const auto& x, const auto& y){
            if (x.first != y.first) return x.first < y.first;
            return x.second > y.second;
        });

        int cur = 0, best = 0;
        for (auto &e : events) {
            cur += e.second;
            best = max(best, cur);
        }
        cout << best << "\n";
    }
    return 0;
}