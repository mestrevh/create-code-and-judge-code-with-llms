/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

bool is_odd_prime(int n) {
    if (n <= 2 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
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
    long long x = 0;
    int num;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        if (is_odd_prime(num)) {
            x -= num;
        } else {
            x += num;
        }
    }
    if (x > 0) {
        std::cout << "Ele ainda tem " << x << " dias de vida\n";
    } else {
        std::cout << "Foi de base\n";
    }
    return 0;
}
