/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i;
    if (!(cin >> i)) return 0;
    vector<long long> a(i);
    for (int k = 0; k < i; k++) cin >> a[k];

    if (i <= 0) {
        cout << "[]";
        return 0;
    }

    long long last = a.back();
    vector<long long> res;
    for (int k = 0; k + 1 < i; k++) {
        if (a[k] != last) res.push_back(a[k]);
    }

    cout << "[";
    for (size_t k = 0; k < res.size(); k++) {
        if (k) cout << ", ";
        cout << res[k];
    }
    cout << "]";
    return 0;
}