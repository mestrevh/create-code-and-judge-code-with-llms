/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long double termValue(long long n) {
    long double nn = (long double)n;
    if (nn == 0) return 0.0L;
    return (nn + 1.0L) / (nn * nn + 1.0L);
}

long double seriesSum(long long N) {
    long double s = 0.0L;
    for (long long n = 0; n < N; n++) s += termValue(n);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    long double s = seriesSum(N);
    cout << "S: " << fixed << setprecision(12) << (double)s << "\n";
    for (long long n = N - 1; n >= 0; n--) {
        long double t = termValue(n);
        cout << fixed << setprecision(12) << (double)t << "\n";
        if (n == 0) break;
    }
    return 0;
}