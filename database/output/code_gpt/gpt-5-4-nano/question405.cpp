/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int ContaDigitosPares(long long n) {
    if (n == 0) return 1 % 2 == 0 ? 1 : 0;
    n = llabs(n);
    if (n < 10) return (n % 2 == 0) ? 1 : 0;
    return (n % 10 % 2 == 0 ? 1 : 0) + ContaDigitosPares(n / 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    cout << ContaDigitosPares(n) << "\n";
    return 0;
}