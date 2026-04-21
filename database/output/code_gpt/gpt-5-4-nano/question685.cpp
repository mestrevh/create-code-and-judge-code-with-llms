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
    vector<string> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];

    vector<int> order;
    vector<int> foodPrefix;
    int posCount = N * N;
    foodPrefix.assign(posCount + 1, 0);

    vector<int> hasGhost(posCount, 0), hasFood(posCount, 0);
    auto idx = [N](int r, int c) { return r * N + c; };

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            char ch = g[r][c];
            int p = idx(r, c);
            if (ch == 'A') hasGhost[p] = 1;
            if (ch == 'o') hasFood[p] = 1;
        }
    }

    int t = 0;
    for (int r = 0; r < N; r++) {
        if (r % 2 == 0) {
            for (int c = 0; c < N; c++) order.push_back(idx(r, c));
        } else {
            for (int c = N - 1; c >= 0; c--) order.push_back(idx(r, c));
        }
    }

    for (int i = 0; i < posCount; i++) {
        int p = order[i];
        foodPrefix[i + 1] = foodPrefix[i] + hasFood[p];
    }

    int maxFood = foodPrefix[posCount];
    for (int i = 0; i < posCount; i++) {
        int p = order[i];
        if (hasGhost[p]) {
            maxFood = max(maxFood, foodPrefix[i]);
        }
    }

    cout << maxFood << "\n";
    return 0;
}