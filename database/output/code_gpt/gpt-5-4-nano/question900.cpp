/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long double sum = 0.0L;
    for (int i = 0; i < 100; i++) {
        long double x;
        if (!(cin >> x)) return 0;
        sum += x;
    }
    long double avg = sum / 100.0L;
    cout.setf(ios::fixed);
    cout << "Media dos numeros: " << setprecision(14) << (double)avg << "\n";
    return 0;
}