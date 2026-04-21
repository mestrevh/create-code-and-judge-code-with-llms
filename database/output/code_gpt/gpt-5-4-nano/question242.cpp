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

    for (int tc = 0; tc < N; tc++) {
        int M, C;
        cin >> M >> C;
        vector<vector<int>> buckets(M);

        for (int i = 0; i < C; i++) {
            int x;
            cin >> x;
            int idx = x % M;
            buckets[idx].push_back(x);
        }

        for (int i = 0; i < M; i++) {
            cout << i << " -> ";
            for (int j = 0; j < (int)buckets[i].size(); j++) {
                if (j) cout << " -> ";
                cout << buckets[i][j];
            }
            cout << " -> \\\n";
        }

        if (tc != N - 1) cout << "\n";
    }

    return 0;
}