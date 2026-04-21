/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double dia0;
    if (!(cin >> dia0)) return 0;
    double prev = dia0;
    double total = prev;
    int cumpriu = 0;
    
    for (int i = 1; i < 7; i++) {
        double x;
        cin >> x;
        total += x;
        if (x >= prev + 0.5 - 1e-9) cumpriu++;
        prev = x;
    }
    
    cout << "R$ " << fixed << setprecision(2) << total << "\n" << cumpriu << "\n";
    return 0;
}