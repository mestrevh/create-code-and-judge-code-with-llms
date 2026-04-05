/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double A, B;
    if (!(cin >> A >> B)) return 0;

    long double m1 = (A + B) / 2.0L;
    long double m2 = (m1 + A) / 2.0L;
    long double m3 = (m2 + A) / 2.0L;

    cout.setf(ios::fixed);
    cout << setprecision(2) << (double)m3;
    return 0;
}