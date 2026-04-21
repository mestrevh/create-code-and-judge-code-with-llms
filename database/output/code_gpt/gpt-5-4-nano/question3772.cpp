/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long long Fatorial(int n) {
    long long resp = 1;
    for (int i = 2; i <= n; i++) resp *= i;
    return resp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    cout << Fatorial(n);
    return 0;
}