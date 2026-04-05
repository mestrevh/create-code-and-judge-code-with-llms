/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double a1, a2;
    if (!(cin >> a1)) return 0;
    if (!(cin >> a2)) return 0;
    
    long double a3 = 180.0L - a1 - a2;
    cout << fixed << setprecision(6) << "3o angulo=" << (double)a3;
    return 0;
}