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
    if (!(cin >> n)) return 0;
    if (n <= 0) { 
        cout << 0;
        return 0;
    }
    
    long long a = 0, b = 1;
    for (long long i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << (n == 1 ? 1 : b);
    return 0;
}