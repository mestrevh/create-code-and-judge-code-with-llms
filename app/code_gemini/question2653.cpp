/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

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
    int n;
    std::cin >> n;
    bool first_output = true;
    for (int i = 1; i <= n; ++i) {
        if (!is_prime(i)) {
            if (!first_output) {
                std::cout << " ";
            }
            std::cout << i;
            first_output = false;
        }
    }
    std::cout << '\n';
    return 0;
}
