/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

long double approxExpRec(int n, long double x, long double term, long double sum) {
    if (n == 0) return sum;
    term *= x / n;
    sum += term;
    return approxExpRec(n - 1, x, term, sum);
}

long double partialSumRec(int n, long double x) {
    long double sum = 1.0L;
    long double term = 1.0L;
    return approxExpRec(n, x, term, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double x;
    if (!(cin >> x)) return 0;

    cout.setf(std::ios::fixed);
    cout << setprecision(5);

    long double exact = expl((double)x);

    int i = 0;
    long double term = 1.0L;
    long double sum = 1.0L;

    while (true) {
        cout << "e^" << (double)x << " com " << i << " iteracoes -> " << (double)sum << "\n";
        long double err = fabsl(exact - sum);
        if (err <= 1e-4L) break;
        i++;
        term *= x / (long double)i;
        sum += term;
    }

    cout << "\n\n";
    cout << "Numero de iteracoes -> " << i;
    return 0;
}