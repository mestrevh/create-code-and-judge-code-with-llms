/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c)) return 0;

    long double avg = ( (long double)a + (long double)b + (long double)c ) / 3.0L;
    cout.setf(ios::scientific);
    cout << fixed << setprecision(2) << (double)avg << "\n";
    return 0;
}