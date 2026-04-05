/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long sumDivisors(long long n) {
    if (n == 0) return 0;
    n = llabs(n);
    long long s = 0;
    for (long long d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            s += d;
            long long other = n / d;
            if (other != d) s += other;
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> a(5);
    for (int i = 0; i < 5; ++i) cin >> a[i];
    
    long long bestVal = a[0];
    long long bestSum = sumDivisors(a[0]);
    
    for (int i = 1; i < 5; ++i) {
        long long curSum = sumDivisors(a[i]);
        if (curSum > bestSum) {
            bestSum = curSum;
            bestVal = a[i];
        }
    }
    
    cout << bestVal << "\n";
    return 0;
}