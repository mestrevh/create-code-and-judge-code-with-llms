/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> prime_factors(long long n) {
    vector<long long> factors;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

bool is_prime_of_4(long long n) {
    vector<long long> factors = prime_factors(n);
    if (factors.size() < 4) return false;

    long long product = 1;
    for (long long factor : factors) product *= factor;
    
    return product == n && factors.size() == 4;
}

int main() {
    long long N;
    while (true) {
        cin >> N;
        if (N == -1) break;
        if (is_prime_of_4(N)) {
            cout << N << " eh um primo de 4" << endl;
        } else {
            cout << N << ", eu nunca duvidei" << endl;
        }
    }
    return 0;
}
