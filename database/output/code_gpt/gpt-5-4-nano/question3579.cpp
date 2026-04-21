/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x1, x2;
    if (!(cin >> x1)) return 0;
    if (!(cin >> x2)) return 0;
    
    long long p = x1 * x2;
    cout << "O produto entre " << x1 << " e " << x2 << " é dado por: " << p;
    return 0;
}