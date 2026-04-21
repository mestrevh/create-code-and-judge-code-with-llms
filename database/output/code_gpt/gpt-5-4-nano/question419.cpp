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

    vector<int> subset;
    function<void(int)> dfs = [&](int start) {
        if (subset.empty()) {
            cout << "{ }";
            cout << "\n";
        } else {
            cout << "{";
            for (int x : subset) cout << " " << x;
            cout << " }";
            cout << "\n";
        }

        for (int i = start; i <= n; i++) {
            subset.push_back(i);
            dfs(i + 1);
            subset.pop_back();
        }
    };

    cout << fixed;
    subset.clear();
    dfs(1);
    return 0;
}