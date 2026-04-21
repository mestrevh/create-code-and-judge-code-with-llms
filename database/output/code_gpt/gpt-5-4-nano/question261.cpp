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
    if (!(cin >> n)) return 0;
    unordered_set<long long> s;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s.insert(x);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        if (s.find(x) == s.end()) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}