/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    long double S = 0.0L;

    for (int k = 1; k <= N; k++) {
        long double term;
        if (k == 1) {
            term = 1.0L;
        } else {
            int a = (k % 2 == 1) ? k : (int)pow(2.0L, k - 1);
            int b = (k % 2 == 1) ? (int)pow(2.0L, k - 1) : k;
            int c = (k + 1) / 2;
            int d = (k % 2 == 1) ? (long long)1 : (long long)0;
            long double num, den;
            if (k % 2 == 1) {
                num = (long double)k;
                den = (long double) ( (long long)2 * (k-1)/2 + 1 );
                long double twoPow = pow((long double)2.0L, (k-1)/2);
                den = den * (long double)twoPow;
                term = num / den * (long double)twoPow;
            } else {
                num = (long double) ( (long long)1 << (k/2) );
                long double twoPow = pow((long double)2.0L, k/2);
                den = (long double)k * twoPow;
                term = num / den;
            }
        }
        S += term;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(2) << "S: " << (double)S << "\n";
    return 0;
}