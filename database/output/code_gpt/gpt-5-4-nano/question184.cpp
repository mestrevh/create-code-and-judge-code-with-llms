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
    long long A, L, P;
    cin >> A >> L >> P;

    long double d = (long double)N;
    long double r = d / 2.0L;

    long double D = d * d;

    auto fits = [&](long long x, long long y) -> bool {
        long double X = (long double)x;
        long double Y = (long double)y;
        long double s2 = X*X + Y*Y;
        return s2 + 1e-12L >= D;
    };

    char ans = 'N';
    if (fits(A, L) || fits(A, P) || fits(L, P)) ans = 'S';

    cout << ans << "\n";
    return 0;
}