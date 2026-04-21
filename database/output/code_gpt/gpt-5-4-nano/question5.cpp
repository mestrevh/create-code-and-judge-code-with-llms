/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> res;
    res.reserve(n + m);

    if (k == 1) {
        int i = 0, j = 0;
        bool takeA = true;
        res.push_back(a[i++]);
        takeA = false;
        while (i < n || j < m) {
            if (takeA) {
                if (i < n) res.push_back(a[i++]);
                takeA = false;
            } else {
                if (j < m) res.push_back(b[j++]);
                takeA = true;
            }
        }
    } else {
        int i = 0, j = 0;
        bool takeB = true;
        res.push_back(b[j++]);
        takeB = false;
        while (i < n || j < m) {
            if (!takeB) {
                if (i < n) res.push_back(a[i++]);
                takeB = true;
            } else {
                if (j < m) res.push_back(b[j++]);
                takeB = false;
            }
        }
    }

    for (int x : res) cout << x << "\n";
    return 0;
}