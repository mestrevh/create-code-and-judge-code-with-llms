/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    while (true) {
        cout << "Insira o numero de linhas da matriz:\n";
        if (!(cin >> n)) return 0;
        cout << "Insira o numero de colunas da matriz:\n";
        if (!(cin >> m)) return 0;
        if (n == 0 && m == 0) break;

        long long N = n, M = m;
        long long totalCells = N * M;
        long long t = totalCells * (totalCells + 1) / 2;

        long long x = 0;
        if (N > 0 && M > 0) {
            long long kMax = min(N, M);
            for (long long i = 0; i < kMax; i++) {
                long long idx = i * M + i + 1;
                x += idx;
            }
        }

        long long a = 0, b = 0;
        if (N > 0 && M > 0) {
            for (long long i = 0; i < N; i++) {
                a += i * M + 1;
                b += i * M + M;
            }
        }

        long long c = 0, d = 0;
        if (N > 0 && M > 0) {
            for (long long j = 0; j < M; j++) c += j + 1;
            for (long long j = 0; j < M; j++) d += (N - 1) * M + (j + 1);
        }

        long long numerator = t - x + (a * b) - (c * d);
        double result = 0.0;
        if (totalCells != 0) result = (double)numerator / (double)totalCells;

        cout << fixed << setprecision(2);
        cout << "Valor da expressao: " << result << "\n";
    }

    return 0;
}