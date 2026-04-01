/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (!(cin >> N)) return 0;

    long long P, Q, R, S, X, Y;
    if (!(cin >> P >> Q >> R >> S >> X >> Y)) return 0;

    long long I, J;
    if (!(cin >> I >> J)) return 0;

    long long total_cost = 0;
    for (long long k = 1; k <= N; ++k) {
        long long a_ik = (P * I + Q * k) % X;
        long long b_kj = (R * k + S * J) % Y;
        total_cost += a_ik * b_kj;
    }

    cout << total_cost << "\n";

    return 0;
}