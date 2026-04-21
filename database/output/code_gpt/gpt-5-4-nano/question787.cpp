/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long fastExp(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long half = fastExp(a, n / 2);
        return half * half;
    } else {
        long long half = fastExp(a, (n - 1) / 2);
        return a * half * half;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a, n;
    if (!(cin >> a)) return 0;
    if (!(cin >> n)) return 0;
    cout << fastExp(a, n);
    return 0;
}