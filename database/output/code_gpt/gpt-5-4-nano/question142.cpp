/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string token;
    while (true) {
        int M, T;
        if (!(cin >> M >> T)) return 0;
        if (M == 0 && T == 0) break;

        vector<int> music(M), pat(T);

        auto parseNote = [&](const string& s) -> int {
            char n = s[0];
            int base = 0;
            if (n == 'C') base = 0;
            else if (n == 'D') base = 2;
            else if (n == 'E') base = 4;
            else if (n == 'F') base = 5;
            else if (n == 'G') base = 7;
            else if (n == 'A') base = 9;
            else if (n == 'B') base = 11;
            int acc = 0;
            if (s.size() > 1) {
                if (s[1] == '#') acc = 1;
                else if (s[1] == 'b') acc = -1;
            }
            int v = (base + acc) % 12;
            if (v < 0) v += 12;
            return v;
        };

        for (int i = 0; i < M; i++) {
            cin >> token;
            music[i] = parseNote(token);
        }
        for (int i = 0; i < T; i++) {
            cin >> token;
            pat[i] = parseNote(token);
        }

        if (T == 1) {
            cout << 'S' << "\n";
            continue;
        }

        vector<int> a(M - 1), b(T - 1);
        for (int i = 0; i < M - 1; i++) a[i] = (music[i + 1] - music[i] + 12) % 12;
        for (int i = 0; i < T - 1; i++) b[i] = (pat[i + 1] - pat[i] + 12) % 12;

        int N = (int)a.size(), K = (int)b.size();

        vector<int> lps(K, 0);
        for (int i = 1, len = 0; i < K; ) {
            if (b[i] == b[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }

        bool ok = false;
        for (int i = 0, j = 0; i < N; ) {
            if (a[i] == b[j]) {
                i++; j++;
                if (j == K) {
                    int start = i - K;
                    ok = true;
                    break;
                }
            } else {
                if (j) j = lps[j - 1];
                else i++;
            }
        }

        cout << (ok ? 'S' : 'N') << "\n";
    }

    return 0;
}