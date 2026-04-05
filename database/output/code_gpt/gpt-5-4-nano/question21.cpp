/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m;
    if (!(cin >> n >> m)) return 0;
    
    if (n > m) swap(n, m);
    
    long long start = (n % 2 != 0) ? n : n + 1;
    for (long long x = start; x <= m; x += 2) {
        cout << x << "\n";
    }
    return 0;
}