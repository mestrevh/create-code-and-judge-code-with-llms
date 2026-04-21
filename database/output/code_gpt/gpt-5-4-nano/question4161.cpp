/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double A, B, N;
    long double C;
    if (!(cin >> A >> B >> N)) return 0;
    if (!(cin >> C)) return 0;

    long double width = (B - A) / N;
    long double sum = 0.0L;
    for (long long i = 1; i <= (long long)N; i++) {
        long double x = A + (long double)i * width;
        sum += x * x * width;
    }

    const long double EPS = 1e-9L;
    long double diff = sum - C;

    if (diff > EPS) cout << "Maior";
    else if (diff < -EPS) cout << "Menor";
    else cout << "Igual";

    return 0;
}