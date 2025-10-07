/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) sum += i;
    }
    return sum;
}

int main() {
    int n;
    int max_prime = 0;
    int min_sum_divisors = numeric_limits<int>::max();
    bool prime_found = false;
    bool non_prime_found = false;

    while (cin >> n && n > 0) {
        if (is_prime(n)) {
            prime_found = true;
            max_prime = max(max_prime, n);
        } else {
            non_prime_found = true;
            min_sum_divisors = min(min_sum_divisors, sum_divisors(n));
        }
    }

    if (prime_found) {
        cout << "Maior numero primo: " << max_prime << endl;
    } else {
        cout << "Nenhum numero primo foi digitado" << endl;
    }

    if (non_prime_found) {
        cout << "A Menor soma dos divisores: " << min_sum_divisors << endl;
    } else {
        cout << "Nenhum numero nao primo foi digitado" << endl;
    }

    if (prime_found && non_prime_found && max_prime > 3 * min_sum_divisors) {
        cout << "Deu a logica, Computos campeao!" << endl;
    } else if (prime_found || non_prime_found){
        cout << "eh mafiaaaaa!" << endl;
    }

    return 0;
}
