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
    
    long long l = min(a, b), r = max(a, b);
    long long start = max(0LL, l);
    if (start > r) {
        cout << 0 << "\n";
        return 0;
    }
    
    long long n = r - start + 1;
    long long sum = n * (start + r) / 2;
    cout << sum << "\n";
    return 0;
}