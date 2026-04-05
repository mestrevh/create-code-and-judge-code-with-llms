/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a >> b)) return 0;
    long long L = min(a, b), R = max(a, b);
    
    long long sum = 0;
    for (long long x = L; x <= R; ++x) {
        if (x % 4 == 0 && 1000 % x == 0) sum += x;
    }
    cout << sum << "\n";
    return 0;
}