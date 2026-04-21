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

    // The equation for the total number of trees N is:
    // N = (R * C) + (R - 1) * (C - 1)
    // N = RC + RC - R - C + 1
    // N = 2RC - R - C + 1
    // 2N = 4RC - 2R - 2C + 2
    // 2N - 1 = 4RC - 2R - 2C + 1
    // 2N - 1 = (2R - 1)(2C - 1)
    // Let X = 2R - 1 and Y = 2C - 1.
    // We need to find the number of pairs (X, Y) such that X * Y = 2N - 1.
    // Since at least one tree of each species must be planted:
    // Carvalho: R * C >= 1
    // Eucalipto: (R - 1) * (C - 1) >= 1 => R >= 2 and C >= 2.
    // Thus X = 2R - 1 >= 3 and Y = 2C - 1 >= 3.
    // We count distinct arrangements (unordered pairs {R, C}), so we assume R <= C, which means X <= Y.
    // This is equivalent to finding divisors X of M = 2N - 1 such that 3 <= X <= sqrt(M).

    long long M = 2 * N - 1;
    int count = 0;
    for (long long x = 3; x * x <= M; ++x) {
        if (M % x == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}