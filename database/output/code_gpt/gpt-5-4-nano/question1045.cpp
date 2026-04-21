/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double QUANTL, QUANTF, TAMEQ, NUMB;
    if (!(cin >> QUANTL)) return 0;
    cin >> QUANTF >> TAMEQ >> NUMB;
    
    long double eficiencia = (QUANTL / QUANTF) / TAMEQ - 4.2L * NUMB;
    
    cout.setf(std::ios::fixed);
    cout << setprecision(1) << (double)eficiencia;
    return 0;
}