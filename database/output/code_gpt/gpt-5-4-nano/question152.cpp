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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) cout << ' ';
        cout << a[i];
    }
    cout << "\n";

    if (n > 1) {
        for (int i = 1; i < n; i++) {
            if (i != 1) cout << ' ';
            cout << a[i];
        }
        cout << ' ' << a[0];
    } else {
        cout << a[0];
    }
    cout << "\n";

    vector<long long> b = a;
    sort(b.begin(), b.end(), greater<long long>());
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << b[i];
    }
    cout << "\n";

    return 0;
}