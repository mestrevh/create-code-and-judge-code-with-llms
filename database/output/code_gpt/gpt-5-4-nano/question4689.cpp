/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);
    int n = (int)a.size();

    for (int pass = 0; pass < n - 1; pass++) {
        bool swapped = false;
        for (int i = 0; i < n - 1 - pass; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << "\n";
        if (!swapped) break;
    }

    if (n == 0) return 0;
    if (n == 1) {
        cout << a[0] << "\n";
    } else {
        bool all_sorted = true;
        for (int i = 1; i < n; i++) if (a[i-1] > a[i]) { all_sorted = false; break; }
        if (all_sorted) {
            // output already produced during passes; nothing else
        }
    }

    return 0;
}