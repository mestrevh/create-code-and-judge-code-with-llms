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
    
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= i; j++) {
            if (j > 1) cout << ' ';
            cout << j;
        }
        if (i < n) cout << '\n';
    }
    return 0;
}