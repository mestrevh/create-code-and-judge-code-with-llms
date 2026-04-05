/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x;
    long long best = LLONG_MIN;
    while (cin >> x) {
        if (x == 0) break;
        best = max(best, x);
    }
    if (best == LLONG_MIN) best = 0;
    cout << best << "\n";
    return 0;
}