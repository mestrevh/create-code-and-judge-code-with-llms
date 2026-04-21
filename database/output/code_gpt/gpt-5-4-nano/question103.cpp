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
    while ( (cin >> n) ) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<bool> seen(max(0, n));
        bool ok = true;

        for (int i = 1; i < n; i++) {
            long long d = llabs(a[i] - a[i - 1]);
            if (d < 1 || d >= n) {
                ok = false;
                break;
            }
            if (seen[(size_t)d]) {
                ok = false;
                break;
            }
            seen[(size_t)d] = true;
        }

        if (ok) {
            for (int d = 1; d <= n - 1; d++) {
                if (!seen[(size_t)d]) {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}