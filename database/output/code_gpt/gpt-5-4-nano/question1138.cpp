/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    auto divides = [](long long x, long long y) -> bool { // x divides y
        if (x == 0) return false;
        return y % x == 0;
    };

    vector<long long> candidates;

    if (C % A == 0 && D % A != 0 && B % A != 0) {
        long long n = A;
        if (divides(A, C) && divides(A, n) && n != 0) {}
    }

    for (int s = 0; s < 2; s++) {
        long long x = s ? B : C;
        // We'll use candidates: for n = lcm(A, k) where k|C and k|D? Not.
        // Proper method below.
    }

    long long g = std::gcd(C, B);
    long long l = std::lcm(A, g);

    if (l > 0) {
        if (C % l == 0) {
            if (l % A == 0) {
                if (l % B != 0) { // l not divisor of n: B does not divide n => n % B !=0
                    if (D % l != 0 && (D % l != 0)) {}
                }
            }
        }
    }

    // Derivation:
    // Need smallest n such that:
    // 1) A | n
    // 2) B does not divide n => n % B != 0
    // 3) n divides C => n | C
    // 4) D is not multiple of n => D % n != 0
    // Thus n must be a positive divisor of C that is also a multiple of A:
    // n = A * t where t | (C/A) if A|C.
    // Additionally: n % B != 0 and D % n != 0.

    if (C % A != 0) {
        cout << -1 << "\n";
        return 0;
    }

    long long M = C / A;

    vector<long long> divs;
    for (long long i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            divs.push_back(i);
            if (i * i != M) divs.push_back(M / i);
        }
    }

    long long ans = -1;
    for (long long t : divs) {
        long long n = A * t;
        if (n <= 0) continue;
        if (n % B == 0) continue;
        if (D % n == 0) continue;
        if (ans == -1 || n < ans) ans = n;
    }

    cout << ans << "\n";
    return 0;
}