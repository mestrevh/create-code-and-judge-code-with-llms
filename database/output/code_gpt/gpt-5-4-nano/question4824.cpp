/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    if (!(cin >> n >> b)) return 0;

    vector<int> seq(n, 0);

    function<void(int)> backtrack = [&](int pos) {
        if (pos == n) {
            for (int i = 0; i < n; i++) cout << seq[i];
            cout << '\n';
            return;
        }
        for (int d = 0; d < b; d++) {
            seq[pos] = d;
            backtrack(pos + 1);
        }
    };

    backtrack(0);
    return 0;
}