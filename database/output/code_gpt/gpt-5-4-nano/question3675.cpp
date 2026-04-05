/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long fib(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return fib(k - 1) + fib(k - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) cout << ' ';
        cout << fib(i);
    }
    return 0;
}