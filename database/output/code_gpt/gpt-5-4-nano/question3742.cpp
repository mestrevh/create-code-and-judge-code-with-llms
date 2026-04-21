/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double f;
    if (!(cin >> f)) return 0;

    long double c = (f - 32.0L) * 5.0L / 9.0L;
    cout.setf(ios::fixed);
    cout << setprecision(10) << (double)c << "\n";
    return 0;
}