/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k;
    if (!(cin >> n >> k)) return 0;
    
    if (k < 0 || k > n) {
        cout << 0;
        return 0;
    }
    k = min(k, n - k);
    
    __int128 res = 1;
    for (long long i = 1; i <= k; i++) {
        res = res * (n - k + i) / i;
    }
    
    auto printInt128 = [](__int128 x) {
        if (x == 0) { cout << 0; return; }
        if (x < 0) { cout << '-'; x = -x; }
        string s;
        while (x > 0) {
            int d = (int)(x % 10);
            s.push_back('0' + d);
            x /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s;
    };
    
    printInt128(res);
    return 0;
}