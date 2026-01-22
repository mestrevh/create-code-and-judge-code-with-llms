/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> generate_primes(int limit) {
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

int count_zeca_primes(int a, int b) {
    vector<int> primes = generate_primes(2000);
    int count = 0;
    for (int i = 1; i < primes.size() - 1; i++) {
        int zeca_prime = (primes[i - 1] + primes[i + 1]) / 2;
        if (zeca_prime >= a && zeca_prime <= b) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << count_zeca_primes(a, b) << endl;
    return 0;
}
