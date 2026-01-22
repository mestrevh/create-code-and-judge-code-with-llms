/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int count_distinct_prime_factors(long long n) {
    if (n <= 1) return 0;
    int count = 0;
    if (n % 2 == 0) {
        count++;
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 2) {
        count++;
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string word;
    std::cin >> word;

    long long word_value = 0;
    for (char c : word) {
        word_value += c;
    }

    if (word_value % 17 == 0) {
        std::cout << "Agora estou Putin, Bonxai!\n";
        return 0;
    }

    if (count_distinct_prime_factors(word_value) >= 3) {
        word_value *= 3;
    }

    long long chutes_sum = 0;
    int chute;
    int attempts = 0;

    while (attempts < 6 && std::cin >> chute) {
        chutes_sum += chute;
        attempts++;
        if (chutes_sum > word_value) {
            break;
        }
    }

    if (chutes_sum > word_value) {
        std::cout << "Agora voce passou dos limites!\n";
    } else if (chutes_sum == word_value) {
        std::cout << "Parabueins! Voce ajudou Bonxai a escapar.\n";
    } else {
        std::cout << "Bonxai foi de base.\n";
    }

    return 0;
}
