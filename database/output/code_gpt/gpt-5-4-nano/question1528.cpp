/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double R;
    if (!(cin >> R)) return 0;
    
    const double pi = 3.1416;
    double V = (4.0 * pi * R * R * R) / 3.0;
    
    cout << fixed << setprecision(2) << V << "\n";
    return 0;
}