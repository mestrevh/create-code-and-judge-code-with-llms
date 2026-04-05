/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long dias;
    if (!(cin >> dias)) return 0;
    
    double reais = static_cast<double>(dias) * 20.0 * 3.20;
    cout << fixed << setprecision(2) << reais << "\n";
    return 0;
}