/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <climits>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int sum_proper_divisors(int n) {
    if (n <= 1) {
        return 0;
    }
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i * i != n) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num;
    int largest_prime = 0;
    int smallest_sum = INT_MAX;
    bool found_prime = false;
    bool found_non_prime = false;

    while (std::cin >> num && num > 0) {
        if (is_prime(num)) {
            found_prime = true;
            if (num > largest_prime) {
                largest_prime = num;
            }
        } else {
            found_non_prime = true;
            int current_sum = sum_proper_divisors(num);
            if (current_sum < smallest_sum) {
                smallest_sum = current_sum;
            }
        }
    }

    if (found_prime) {
        std::cout << "Maior numero primo: " << largest_prime << "\n";
    } else {
        std::cout << "Nenhum numero primo foi digitado\n";
    }

    if (found_non_prime) {
        std::cout << "A Menor soma dos divisores: " << smallest_sum << "\n";
    } else {
        std::cout << "Nenhum numero nao primo foi digitado\n";
    }

    if (found_prime && found_non_prime) {
        if (largest_prime > 3 * smallest_sum) {
            std::cout << "Deu a logica, computos campeao!\n";
        } else {
            std::cout << "eh mafiaaaaa!\n";
        }
    }

    return 0;
}
