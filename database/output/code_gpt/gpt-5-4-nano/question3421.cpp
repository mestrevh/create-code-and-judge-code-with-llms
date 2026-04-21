/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double x;
    int n;
    if (!(cin >> x >> n)) return 0;
    
    long double term = 1.0L;
    long double sum = 1.0L;
    for (int k = 1; k <= n; k++) {
        term *= x / k;
        sum += term;
    }
    
    cout << fixed << setprecision(5) << (double)sum << "\n";
    return 0;
}