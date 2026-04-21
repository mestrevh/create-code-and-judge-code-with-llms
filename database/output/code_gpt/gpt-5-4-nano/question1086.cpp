/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dias;
    int km;
    if (!(cin >> dias)) return 0;
    if (!(cin >> km)) return 0;

    double total = dias * 30.0 + km * 0.01;
    total *= 0.9;

    cout.setf(ios::fixed);
    cout << setprecision(2) << total << "\n";
    return 0;
}