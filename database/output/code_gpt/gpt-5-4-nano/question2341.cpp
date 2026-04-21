/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long processa(long long n) {
    if (n < 10) {
        int d = (int)n;
        if (d % 2 != 0) return n - 3;
        return n - 4;
    }
    long long resto = n;
    while (resto >= 10) resto /= 10;
    int d = (int)resto;
    if (d % 2 != 0) return n - 3;
    return n - 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    cout << processa(n);
    return 0;
}