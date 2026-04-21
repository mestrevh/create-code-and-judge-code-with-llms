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

    long long sumNum = 0;
    long long sumDen = 1;

    for (long long i = 1; i <= N; i++) {
        long long a = 2 * i - 1;
        long long b = 2 * i;
        long long termNum = a;
        long long termDen = 4 * b;

        long long g = std::gcd(termNum, termDen);
        termNum /= g;
        termDen /= g;

        sumNum = sumNum * termDen + termNum * sumDen;
        sumDen = sumDen * termDen;
        long long gg = std::gcd(llabs(sumNum), sumDen);
        sumNum /= gg;
        sumDen /= gg;

        if (i > 1) cout << " + ";
        cout << termNum << "/" << termDen;
    }

    long double value = (long double)sumNum / (long double)sumDen;
    cout << "\n" << fixed << setprecision(2) << (double)value;

    return 0;
}