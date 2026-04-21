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

    vector<double> I(N), P(N);
    for (int i = 0; i < N; i++) cin >> I[i];
    for (int i = 0; i < N; i++) cin >> P[i];

    double num = 0.0, den = 0.0;
    for (int i = 0; i < N; i++) {
        num += I[i] * P[i];
        den += P[i];
    }

    double Q = (den == 0.0 ? 0.0 : num / den);
    cout << fixed << setprecision(2) << Q << "\n";
    return 0;
}