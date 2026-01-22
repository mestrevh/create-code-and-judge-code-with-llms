/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int max) {
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int A, B;
    cin >> A >> B;

    vector<bool> is_prime = sieve(B);
    vector<int> primes;

    for (int i = A; i < B; i++) {
        if (is_prime[i]) primes.push_back(i);
    }

    int max_sequence = 0;
    for (size_t i = 0; i < primes.size(); i++) {
        int count = 1; 
        for (size_t j = i + 1; j < primes.size() && primes[j] - primes[i] <= 6; j++) {
            if (primes[j] - primes[i] == 6) {
                count++;
                i = j - 1; 
                break; 
            }
        }
        max_sequence = max(max_sequence, count);
    }

    cout << max_sequence << endl;
    return 0;
}
