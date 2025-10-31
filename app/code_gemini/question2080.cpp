/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

bool isPrime(int n) {
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string n_str;
    std::cin >> n_str;

    int holes_per_digit[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
    int total_holes = 0;

    for (char digit_char : n_str) {
        total_holes += holes_per_digit[digit_char - '0'];
    }

    if (isPrime(total_holes)) {
        std::cout << 'S' << std::endl;
    } else {
        std::cout << 'N' << std::endl;
    }

    return 0;
}
