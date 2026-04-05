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
        string res;
        res.reserve(s.size());
        for (char c : s) {
            if (!res.empty() && res.back() == c) continue;
            res.push_back(c);
        }
        cout << res << "\n";
    }
    return 0;
}