/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> comb;
    function<void(int,int)> dfs = [&](int start, int remaining) {
        if (remaining == 0) {
            for (int i = 0; i < (int)comb.size(); i++) {
                if (i) cout << ' ';
                cout << comb[i];
            }
            cout << '\n';
            return;
        }
        for (int x = start; x <= n; x++) {
            if (n - x + 1 < remaining) break;
            comb.push_back(x);
            dfs(x + 1, remaining - 1);
            comb.pop_back();
        }
    };

    dfs(1, k);
    return 0;
}