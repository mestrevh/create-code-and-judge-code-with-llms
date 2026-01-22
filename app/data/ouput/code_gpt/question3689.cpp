/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

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

long long ceil_division(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    long long signals[3];
    cin >> signals[0] >> signals[1] >> signals[2];
    bool password_found = false;

    for (int i = 0; i < 3; ++i) {
        if (password_found) {
            cout << "SINAL OFF" << endl;
            continue;
        }

        vector<long long> factors = prime_factors(signals[i]);
        long long sum = 0;

        for (size_t j = 0; j < factors.size(); ++j) {
            sum += ceil_division(factors[j], j + 1);
        }

        if (is_prime(sum)) {
            cout << "SHERLIRO SALVOU MULITTLE" << endl;
            password_found = true;
        } else {
            cout << "ERRO" << endl;
        }
    }

    return 0;
}
