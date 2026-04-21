/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double Ri, Re;
    if (!(cin >> Ri >> Re)) return 0;
    
    long double area = M_PI * (Re * Re - Ri * Ri);
    cout << fixed << setprecision(2) << (double)area << "\n";
    return 0;
}