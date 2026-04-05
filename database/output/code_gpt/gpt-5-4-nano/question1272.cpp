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

    vector<long long> ans(N + 1, -1);
    ans[0] = 0;

    unordered_set<string> used;
    queue<pair<string,int>> q;
    used.insert("0");
    q.push({"0", 0});

    auto persistence = [&](const string& s) -> int {
        long long x = 0;
        for (char c : s) x = x * 10 + (c - '0');
        int steps = 0;
        while (x >= 10) {
            long long prod = 1;
            while (x > 0) {
                prod *= (x % 10);
                x /= 10;
            }
            x = prod;
            steps++;
        }
        return steps;
    };

    while (!q.empty()) {
        auto [s, p] = q.front();
        q.pop();

        for (int d = 0; d <= 9; d++) {
            if (s == "0" && d == 0) continue;
            string ns = s + char('0' + d);
            long long val = stoll(ns);
            int np = persistence(ns);

            if (np <= N && ans[np] == -1) {
                ans[np] = val;
            }
            if (np < N && ns.size() < 20) {
                if (!used.count(ns)) {
                    used.insert(ns);
                    q.push({ns, np});
                }
            }
        }
    }

    for (int p = 0; p <= N; p++) {
        cout << "O menor número com persistência " << p << " é " << ans[p] << ".";
        if (p < N) cout << "\n";
    }
    return 0;
}