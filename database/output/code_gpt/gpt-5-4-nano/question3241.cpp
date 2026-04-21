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
    vector<int> a(n + 1);
    int ones = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ones += a[i];
    }
    
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) b[i] = (a[i] == 0) ? 1 : -1;
    
    int best = INT_MIN;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cur = b[i];
        } else {
            cur = max(b[i], cur + b[i]);
        }
        best = max(best, cur);
    }
    
    cout << ones + best << "\n";
    return 0;
}