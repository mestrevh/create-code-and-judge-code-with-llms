/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<bool> reachable(n + 1, false);
    set<pair<int, int>> seen;

    for (int i = 0; i < m; ++i) {
        int p, d;
        if (!(cin >> p >> d)) break;

        if (p < 1 || p > n) continue;

        if (d <= 0) {
            reachable[p] = true;
            continue;
        }

        int rem = p % d;
        if (seen.find({d, rem}) != seen.end()) continue;
        seen.insert({d, rem});

        for (int pos = p; pos <= n; pos += d) {
            reachable[pos] = true;
        }
        for (int pos = p - d; pos >= 1; pos -= d) {
            reachable[pos] = true;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (reachable[i]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}