/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long p, m, g;
    if (!(cin >> p)) return 0;
    cin >> m >> g;
    
    long long total = p * 10 + m * 12 + g * 15;
    cout << "Total= R$ " << total;
    return 0;
}