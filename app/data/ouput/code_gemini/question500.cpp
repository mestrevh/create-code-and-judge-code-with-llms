/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num1, num2;
    std::cin >> num1 >> num2;

    int upper_bound = std::max(num1, num2);
    int lower_bound = std::min(num1, num2);

    for (int i = upper_bound; i >= lower_bound; --i) {
        if (is_prime(i)) {
            std::cout << i << '\n';
        }
    }

    return 0;
}
