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

    for (int i = 1; i <= n; i++) {
        int val = i;
        for (int j = 1; j <= n; j++) {
            int x = max(i, j);
            if (j > 1) cout << ' ';
            cout << x;
        }
        cout << '\n';
    }
    return 0;
}