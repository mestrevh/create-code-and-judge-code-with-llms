/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    bool neg = false;
    if (!s.empty() && s[0] == '-') {
        neg = true;
        s = s.substr(1);
    }

    while (s.size() > 1 && s[0] == '0') s.erase(s.begin());

    reverse(s.begin(), s.end());

    if (neg) cout << "-" << s;
    else cout << s;

    return 0;
}