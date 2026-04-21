/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;

    long double sum = 0.0L;
    for (long long k = 1; k <= n; k++) {
        long double denom = (long double)k * (long double)k;
        sum += 1.0L / denom;
    }

    cout.setf(std::ios::fixed); 
    cout << setprecision(6) << (double)sum << "\n";
    return 0;
}