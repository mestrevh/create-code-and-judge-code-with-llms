/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, line;
    while (getline(cin, line)) {
        if (!line.empty()) {
            if (!s.empty()) s += line;
            else s = line;
        }
    }
    if (s.empty()) return 0;

    for (char &c : s) {
        if (!(isdigit((unsigned char)c) || c == '-' || c == '+')) c = ' ';
    }

    long long x;
    bool first = true;
    long long ans = 0;

    stringstream ss(s);
    while (ss >> x) {
        if (first) { ans = x; first = false; }
        else ans = max(ans, x);
    }

    if (!first) cout << ans;
    return 0;
}