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

    unordered_map<char,int> val{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };

    int n = (int)s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = val[s[i]];
        int nxt = (i + 1 < n) ? val[s[i + 1]] : 0;
        if (cur < nxt) ans -= cur;
        else ans += cur;
    }

    cout << ans << "\n";
    return 0;
}