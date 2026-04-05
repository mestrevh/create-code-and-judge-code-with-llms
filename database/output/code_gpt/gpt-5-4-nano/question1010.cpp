/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long double sum = 0.0L;
    for (long long i = 0; i < N; i++) {
        long long denom = 2 * i + 1;
        long double term = 1.0L / (long double)denom;
        if (i % 2 == 1) sum -= term;
        else sum += term;
    }
    long double pi = sum * 4.0L;

    cout.setf(std::ios::fixed);
    cout << setprecision(5) << (double)pi << "\n";
    return 0;
}