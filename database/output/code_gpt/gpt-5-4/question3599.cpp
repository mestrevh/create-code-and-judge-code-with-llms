/*
Código criado pelo gpt-5.4
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long best = 0, cur = 0;
    int prev = -1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0 || x != prev) cur++;
        else cur = 1;
        best = max(best, cur);
        prev = x;
    }

    cout << best << '\n';
    return 0;
}