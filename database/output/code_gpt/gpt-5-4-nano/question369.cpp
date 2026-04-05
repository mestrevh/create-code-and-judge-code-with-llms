/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long dias;
    if (!(cin >> dias)) return 0;
    double multa = dias * 0.75;
    cout << fixed << setprecision(2) << multa;
    return 0;
}