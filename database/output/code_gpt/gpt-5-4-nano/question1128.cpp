/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k)) return 0;

    string s(k, '0');

    function<void(int)> dfs = [&](int pos) {
        if (pos == k) {
            cout << s << "\n";
            return;
        }
        s[pos] = '0';
        dfs(pos + 1);
        if (pos == 0 || s[pos - 1] == '0') {
            s[pos] = '1';
            dfs(pos + 1);
        }
    };

    dfs(0);
    return 0;
}