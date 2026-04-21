/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double f;
    if (!(cin >> f)) return 0;
    double c = (f - 32.0) * 5.0 / 9.0;
    cout << fixed << setprecision(2) << c << "\n";
    return 0;
}