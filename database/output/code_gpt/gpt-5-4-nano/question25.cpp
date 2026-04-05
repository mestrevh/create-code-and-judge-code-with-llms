/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x, y;
    if (!(cin >> x >> y)) return 0;
    
    if (x > y) swap(x, y);
    
    for (long long n = x; n <= y; n++) {
        if (n % 10 == 0) continue;
        long long rest = n / 10;
        if (rest != 0 && n % rest == 0) cout << n << "\n";
    }
    return 0;
}