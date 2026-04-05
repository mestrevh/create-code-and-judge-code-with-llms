/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

static bool isPrime(int x) {
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int d = 3; 1LL * d * d <= x; d += 2) {
        if (x % d == 0) return false;
    }
    return true;
}

static int numDivisors(int x) {
    x = abs(x);
    if (x <= 1) return 0;
    int n = x;
    int divisors = 1;
    for (int p = 2; 1LL * p * p <= n; ++p) {
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            divisors *= (cnt + 1);
        }
    }
    if (n > 1) divisors *= 2;
    return divisors - 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    for (int tc = 0; tc < N; ++tc) {
        int M;
        cin >> M;
        long long conf = 0;
        for (int j = 0; j < M; ++j) {
            int i;
            cin >> i;
            int a = abs(i);
            if (isPrime(a)) {
                conf += 2LL * i;
            } else {
                int d = numDivisors(a);
                conf += (long long)i / 2 * d;
            }
        }

        if (conf > (1LL << 11)) {
            cout << "Anão Paulo. babado.\n";
        } else if (conf > (1LL << 9)) {
            cout << "Para pow.\n";
        } else if (conf > 0) {
            cout << "Se isso não é mentira eu sou uma brastemp 4 portas\n";
        } else {
            cout << "que mentirada\n";
        }
    }
    return 0;
}