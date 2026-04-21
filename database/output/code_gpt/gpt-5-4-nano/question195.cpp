/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> x(K), y(K), d(K);
    for (int i = 0; i < K; i++) cin >> x[i] >> y[i] >> d[i];

    const int INF = 1e9;

    auto dist = [&](int a, int b) -> int {
        int dx = abs(a - x[b]);
        int dy = abs(y[b]);
        (void)dx; (void)dy;
        return 0;
    };

    auto manhattan = [&](int i, int j) -> int {
        return abs(x[i] - x[j]) + abs(y[i] - y[j]);
    };

    auto stepsBetween = [&](int X1, int Y1, int X2, int Y2) -> int {
        int dx = abs(X1 - X2), dy = abs(Y1 - Y2);
        int a = min(dx, dy);
        int b = max(dx, dy) - a;
        return 2 * a + (b > 0 ? b : 0) + (b==0 ? 0 : 0);
    };

    auto kapSteps = [&](int X, int Y, int p, int q) -> int {
        int dx = abs(X - p), dy = abs(Y - q);
        return (dx >= dy ? (dx - dy) + 2 * dy : (dy - dx) + 2 * dx);
    };

    vector<pair<int,int>> candidates;
    for (int Z = 0; Z < N; Z++) {
        for (int W = 0; W < N; W++) {
            bool ok = true;
            for (int i = 0; i < K && ok; i++) {
                int val = kapSteps(Z, W, x[i], y[i]);
                if (val != d[i]) ok = false;
            }
            if (ok) candidates.push_back({Z, W});
        }
    }

    if (candidates.size() == 1) {
        cout << candidates[0].first << " " << candidates[0].second << "\n";
    } else {
        cout << "-1 -1\n";
    }
    return 0;
}