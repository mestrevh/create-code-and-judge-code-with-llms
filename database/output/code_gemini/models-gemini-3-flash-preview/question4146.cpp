/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    // The sum of the first N natural numbers is given by the formula N * (N + 1) / 2.
    // We need to exclude multiples of A and multiples of B from this sum.
    // Using the Principle of Inclusion-Exclusion:
    // Sum = TotalSum - (Sum of Multiples of A + Sum of Multiples of B - Sum of Multiples of LCM(A, B))

    long long total = n * (n + 1) / 2;

    // Sum of multiples of A: A, 2A, 3A, ..., kA where k = floor(N/A)
    // Sum = A * (1 + 2 + ... + k) = A * [k * (k + 1) / 2]
    long long ca = n / a;
    long long sa = a * (ca * (ca + 1) / 2);

    // Sum of multiples of B: B, 2B, 3B, ..., mB where m = floor(N/B)
    long long cb = n / b;
    long long sb = b * (cb * (cb + 1) / 2);

    // Sum of multiples of both A and B (LCM)
    // Since A and B are prime numbers:
    // If A != B, LCM(A, B) = A * B.
    // If A == B, LCM(A, B) = A.
    long long lcm;
    if (a == b) {
        lcm = a;
    } else {
        lcm = a * b;
    }

    long long clcm = n / lcm;
    long long slcm = lcm * (clcm * (clcm + 1) / 2);

    // Final sum calculation
    long long ans = total - (sa + sb - slcm);

    // Output the sum
    cout << ans << "\n";

    // Parity check for the special message
    if (ans % 2 == 0) {
        cout << "Lá ele!!!" << "\n";
    } else {
        cout << "Opa xupenio AULAS..." << "\n";
    }

    return 0;
}