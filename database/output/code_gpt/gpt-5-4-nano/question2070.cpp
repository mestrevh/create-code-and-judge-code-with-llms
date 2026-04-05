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
    while (cin >> s) {
        if (s == "0") break;
        long long pos = 1;
        long long ans = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i, ++pos) {
            int d = s[i] - '0';
            int mult = (d % 2 == 0) ? 2 : 3;
            ans += 1LL * d * mult * pos;
        }
        cout << ans << "\n";
    }
    return 0;
}