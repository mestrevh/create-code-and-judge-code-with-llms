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
    long long k;
    if (!(cin >> n >> k)) return 0;

    long long m = n / k;
    long long t = (m + 1) * (2 * n - k * m);
    long long ans = t / 2;

    cout << ans;
    return 0;
}