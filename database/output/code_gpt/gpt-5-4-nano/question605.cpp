/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    if (!getline(cin, s)) return 0;
    if (!getline(cin, p)) return 0;

    int n = (int)s.size();
    int m = (int)p.size();

    if (m == 0 || m > n) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (p[i] == p[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }

    bool found = false;
    for (int i = 0, j = 0; i < n; ) {
        if (s[i] == p[j]) {
            ++i; ++j;
            if (j == m) {
                cout << (i - j) << "\n";
                found = true;
                j = lps[j - 1];
            }
        } else {
            if (j) j = lps[j - 1];
            else ++i;
        }
    }

    if (!found) cout << -1 << "\n";
    return 0;
}