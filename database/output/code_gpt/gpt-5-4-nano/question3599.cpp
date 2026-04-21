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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = 1;
    for (int i = 0; i < n; i++) {
        int mx = a[i];
        int mn = a[i];
        int cnt = 1;
        for (int j = i + 1; j < n; j++) {
            mx = max(mx, a[j]);
            mn = min(mn, a[j]);
            if (mx - mn <= 1) cnt++;
            else break;
        }
        best = max(best, cnt);
    }

    cout << best << "\n";
    return 0;
}