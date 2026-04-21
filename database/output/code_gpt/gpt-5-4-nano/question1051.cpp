/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double r;
    if (!(cin >> r)) return 0;
    const double pi = 3.14;
    double volume = (4.0 / 3.0) * pi * r * r * r;
    cout << fixed << setprecision(2) << volume;
    return 0;
}