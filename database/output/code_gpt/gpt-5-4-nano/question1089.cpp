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

    if (N == 0) {
        cout.setf(std::ios::fixed);
        cout << setprecision(2) << 0.00;
        return 0;
    }

    double sum = 0.0;
    for (long long i = 1; i <= N; i++) {
        long long num = i;
        long long den = 3LL * i;
        if (i > 1) cout << " + ";
        cout << num << "/" << den;
        sum += (long double)num / (long double)den;
    }
    cout << "\n";
    cout.setf(std::ios::fixed);
    cout << setprecision(2) << sum;
    return 0;
}