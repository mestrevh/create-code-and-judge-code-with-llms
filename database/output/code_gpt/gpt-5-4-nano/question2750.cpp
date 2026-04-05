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

    while (N--) {
        long long X;
        cin >> X;

        long long sum = 0;
        if (X > 1) {
            long long r = (long long) sqrt((long double)X);
            for (long long d = 1; d <= r; d++) {
                if (X % d == 0) {
                    long long q = X / d;
                    if (d != X) sum += d;
                    if (q != d && q != X) sum += q;
                }
            }
        }

        if (sum == X) cout << X << " eh perfeito\n";
        else cout << X << " nao eh perfeito\n";
    }

    return 0;
}