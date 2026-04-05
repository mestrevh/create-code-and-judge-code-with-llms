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
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        if (n == 0) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> prev(n, 0), cur(n, 0);
        for (int i = 0; i < n; i++) prev[i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int inside = 0;
                    if (i + 1 <= j - 1) inside = (len == 2) ? 0 : prev[i + 1];
                    cur[i] = 2 + inside;
                } else {
                    int a = prev[i];
                    int b = prev[i + 1];
                    cur[i] = max(a, b);
                }
            }
            prev.swap(cur);
        }

        int ans;
        if (n == 1) ans = 1;
        else ans = prev[0];
        if (n == 0) ans = 0;

        cout << ans << "\n";
    }
    return 0;
}