/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long countDigit(long long n, int x) {
    if (n == 0) return x == 0 ? 1 : 0;
    long long cnt = 0;
    while (n > 0) {
        if (n % 10 == x) cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    int x;
    if (!(cin >> n >> x)) return 0;
    cout << countDigit(n, x) << "\n";
    return 0;
}