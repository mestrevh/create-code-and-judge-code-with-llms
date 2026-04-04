/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double x;
    if (cin >> x) {
        long long exp = 0;
        if (x > 0.0L) {
            // Normalize x to be in the range [1, 10) by dividing or multiplying by 10.
            // The number of divisions/multiplications gives the order of magnitude (exponent).
            // A small epsilon is used to handle precision for values very close to powers of 10.
            while (x >= 10.0L - 1e-15L) {
                x /= 10.0L;
                exp++;
            }
            while (x < 1.0L - 1e-15L) {
                x *= 10.0L;
                exp--;
            }
        }
        cout << exp << "\n";
    }

    return 0;
}