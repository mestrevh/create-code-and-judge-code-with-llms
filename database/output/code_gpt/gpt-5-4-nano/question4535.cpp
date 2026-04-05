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

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int l = i;
            int m = min(i + width, n);
            int r = min(i + 2 * width, n);

            int p = l, q = m, k = l;
            while (p < m && q < r) {
                if (a[p] <= a[q]) b[k++] = a[p++];
                else b[k++] = a[q++];
            }
            while (p < m) b[k++] = a[p++];
            while (q < r) b[k++] = a[q++];
        }
        a.swap(b);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}