/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

string par_ou_impar(long long n) {
    return (n % 2 == 0) ? "Par" : "Ímpar";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    cout << par_ou_impar(n);
    return 0;
}