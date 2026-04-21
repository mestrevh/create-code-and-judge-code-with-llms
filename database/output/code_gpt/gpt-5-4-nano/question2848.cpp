/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double d;
    if (!(cin >> d)) return 0;
    
    long double t = d * 2.0L;
    if (fabsl(t - llround(t)) < 1e-9) {
        cout << llround(t) << " minutos";
    } else {
        cout << fixed << setprecision(10) << t;
        while (!cout.fail() && !cin.eof()) {}
        return 0;
    }
    return 0;
}