/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    long long n, m, h, X, Y, Z, P, Q, R;
    cin >> n >> m >> h;
    cin >> X >> Y >> Z;
    cin >> P >> Q >> R;

    long long sumC = 0;
    long long sumA = ((n * Y * m + m * (m - 1) / 2 * X + n * Z) % MOD) * m % MOD) % MOD;
    long long sumB = ((h * Q * m + m * (m - 1) / 2 * P + h * R) % MOD) * n % MOD) % MOD;

    sumC = (sumA * sumB) % MOD;
    cout << sumC << endl;

    return 0;
}
