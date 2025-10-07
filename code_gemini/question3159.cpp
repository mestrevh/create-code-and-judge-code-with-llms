/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_prime(int n) {
    if (n < 2) {
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
    int a, b, c;
    std::cin >> a >> b >> c;
    
    int prime_count = 0;
    if (is_prime(a)) {
        prime_count++;
    }
    if (is_prime(b)) {
        prime_count++;
    }
    if (is_prime(c)) {
        prime_count++;
    }
    
    if (prime_count == 0) {
        std::cout << "Seguro\n";
    } else if (prime_count == 1) {
        std::cout << "Possível Risco\n";
    } else {
        std::cout << "Perigo\n";
    }
    
    return 0;
}
