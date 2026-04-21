/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, C;
    if (!(cin >> L >> C)) return 0;
    int N = L * C;

    vector<int> rowMap(L + 1, 0), colMap(C + 1, 0);

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= C; j++) {
            int x;
            cin >> x;
            int r = (x - 1) / C + 1;
            int k = (x - 1) % C + 1;
            if (k == 1) rowMap[i] = r;
            if (r == 1) colMap[j] = k;
        }
    }

    auto minSwapsToTransform = [&](const vector<int>& target, int n) -> int {
        vector<int> p(n + 1), pos(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = target[i];
            pos[p[i]] = i;
        }
        vector<int> vis(n + 1, 0);
        int cycles = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                cycles++;
                int cur = i;
                while (!vis[cur]) {
                    vis[cur] = 1;
                    cur = p[cur];
                }
            }
        }
        return n - cycles;
    };

    int K = minSwapsToTransform(rowMap, L) + minSwapsToTransform(colMap, C);
    cout << K << "\n";
    return 0;
}