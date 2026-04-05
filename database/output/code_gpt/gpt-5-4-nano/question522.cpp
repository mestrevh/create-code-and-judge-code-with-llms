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
        string X;
        cin >> X;

        vector<int> cnt(10, 0);
        for (char c : X) cnt[c - '0']++;

        int best = -1;
        for (int d = 9; d >= 0; d--) {
            if (cnt[d] > 0) { best = d; break; }
        }

        if (best == 0) {
            cout << "Caso " << tc << ": 0\n";
            continue;
        }

        string Y;
        Y.reserve(X.size());
        for (int d = 9; d >= 0; d--) {
            Y.append(cnt[d], char('0' + d));
        }

        size_t pos = Y.find_first_not_of('0');
        if (pos == string::npos) Y = "0";
        else Y = Y.substr(pos);

        cout << "Caso " << tc << ": " << Y << "\n";
    }
    return 0;
}