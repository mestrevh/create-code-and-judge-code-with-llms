/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int op;
    if (!(cin >> op)) return 0;

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> res;
    if (op == 1) {
        vector<int> uni;
        uni.reserve(n + m);
        set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(uni));
        res.swap(uni);
    } else {
        vector<int> inter;
        inter.reserve(min(n, m));
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(inter));
        res.swap(inter);
    }

    if (res.empty()) {
        cout << "empty";
    } else {
        for (size_t i = 0; i < res.size(); i++) {
            if (i) cout << ' ';
            cout << res[i];
        }
    }
    return 0;
}