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
    string a = s, b, c, ans;

    {
        int n = (int)s.size();
        if (n % 2 == 1) {
            b = s + s.substr(0, n / 2 + 1);
        } else {
            b = s + s.substr(0, n / 2);
        }
    }

    {
        string r = b;
        reverse(r.begin(), r.end());
        ans = b + r.substr(0, max(0, (int)b.size() - 1));
    }

    cout << ans;
    return 0;
}