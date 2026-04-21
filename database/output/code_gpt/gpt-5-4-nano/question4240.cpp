/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    double a1, a2;
    if (!(cin >> a1 >> a2)) return 0;
    
    double a3 = 180.0 - (a1 + a2);
    cout.setf(ios::fixed);
    cout << "O terceiro angulo = " << setprecision(3) << a3;
    return 0;
}