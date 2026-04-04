/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAX_SQRT = 1000000;
vector<int> primes;
bool is_prime[MAX_SQRT + 1];

void sieve() {
    for (int i = 0; i <= MAX_SQRT; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; 1LL * p * p <= MAX_SQRT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_SQRT; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= MAX_SQRT; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    long long n;
    while (cin >> n && n != -1) {
        long long tempN = n;
        int count = 0;
        
        if (tempN > 1) {
            for (int p : primes) {
                if (1LL * p * p > tempN) break;
                while (tempN % p == 0) {
                    count++;
                    tempN /= p;
                    if (count > 4) break;
                }
                if (count > 4) break;
            }
            if (tempN > 1) {
                count++;
            }
        }

        if (count == 4) {
            cout << n << " eh um primo de 4\n";
        } else {
            cout << n << ", eu nunca duvidei\n";
        }
    }

    return 0;
}