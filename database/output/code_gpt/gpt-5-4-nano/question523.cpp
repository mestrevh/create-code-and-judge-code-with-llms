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
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        unordered_map<string, long long> cost;
        cost.reserve(N * 2);

        for (int i = 0; i < N; i++) {
            string w;
            long long x;
            cin >> w >> x;
            cost[w] = x;
        }

        int M;
        cin >> M;
        long long total = 0;
        for (int i = 0; i < M; i++) {
            string s;
            cin >> s;
            auto it = cost.find(s);
            if (it != cost.end()) total += it->second;
        }

        cout << "Caso " << tc << ": " << total << "\n";
    }
    return 0;
}