/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool validChar(unsigned char c) {
    if (c >= 'A' && c <= 'Z') return true;
    if (c == ' ') return true;
    if (c == '.') return true;
    if (c == '?') return true;
    if (c == '\'') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    string dummy;
    getline(cin, dummy);

    for (int tc = 0; tc < T; tc++) {
        string s;
        getline(cin, s);

        bool ok = true;
        for (unsigned char c : s) {
            if (!validChar(c)) { ok = false; break; }
        }

        if (!ok) {
            cout << "INVALIDO\n";
            continue;
        }

        int C = (int)s.size();
        int N = (int)llround(sqrt((double)C));
        if (N <= 0 || N * N != C) {
            cout << "INVALIDO\n";
            continue;
        }

        vector<vector<char>> a(N, vector<char>(N));
        int idx = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = s[idx++];
            }
        }

        string out;
        out.reserve(C);
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                out.push_back(a[i][j]);
            }
        }

        cout << out << "\n";
    }

    return 0;
}