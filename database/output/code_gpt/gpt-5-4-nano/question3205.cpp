/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    if (!(cin >> x)) return 0;

    long double base = floor(x / 3.0L);
    long double c = base;
    long double a = base;
    long double f = x - c - a;

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << (double)c << "\n";
    cout << setprecision(2) << (double)a << "\n";
    cout << setprecision(2) << (double)f << "\n";
    return 0;
}