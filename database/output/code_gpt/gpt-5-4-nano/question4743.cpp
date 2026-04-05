/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long c;
    if (!(cin >> c)) return 0;
    double f = c * 9.0 / 5.0 + 32.0;
    cout << fixed << setprecision(1) << f;
    return 0;
}