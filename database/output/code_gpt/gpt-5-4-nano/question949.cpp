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

    vector<int> val(N), leftc(N), rightc(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i] >> leftc[i] >> rightc[i];
    }

    vector<int> levelMin, levelMax;
    queue<pair<int,int>> q;
    q.push({0, 1});

    while (!q.empty()) {
        auto [u, lv] = q.front();
        q.pop();

        if ((int)levelMin.size() < lv) {
            levelMin.push_back(val[u]);
            levelMax.push_back(val[u]);
        } else {
            levelMin[lv - 1] = min(levelMin[lv - 1], val[u]);
            levelMax[lv - 1] = max(levelMax[lv - 1], val[u]);
        }

        int l = leftc[u], r = rightc[u];
        if (l != -1) q.push({l, lv + 1});
        if (r != -1) q.push({r, lv + 1});
    }

    for (int i = 0; i < (int)levelMin.size(); i++) {
        cout << "Nivel " << (i + 1) << ": Maior = " << levelMax[i] << ", Menor = " << levelMin[i] << "\n";
    }
    return 0;
}