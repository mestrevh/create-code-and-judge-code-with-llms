/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double gasto;
    if (!(cin >> gasto)) return 0;
    double total = gasto * 1.10;
    cout << fixed << setprecision(2) << total;
    return 0;
}