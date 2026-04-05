/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        string s;
        s.reserve(n);
        cin >> s;
        if ((int)s.size() < n) {
            string extra;
            extra.reserve(n - (int)s.size());
            while ((int)s.size() + (int)extra.size() < n && cin >> extra) {
                s += extra;
            }
        }
        for (int i = n - 1; i >= 0; --i) cout << s[i];
        if (!cin.eof()) cout << "\n";
    }
    return 0;
}