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

    auto sumMultiples = [&](long long k) -> long long {
        long long m = (n - 1) / k;
        return k * m * (m + 1) / 2;
    };

    long long ans = sumMultiples(3) + sumMultiples(5) - sumMultiples(15);
    cout << ans << "\n";
    return 0;
}