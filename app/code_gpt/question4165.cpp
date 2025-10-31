/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return n % 2 != 0; // somente números ímpares
}

int main() {
    int N, num, total = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        if (is_prime(num)) total -= num;
        else total += num;
    }
    if (total > 0) {
        std::cout << "Ele ainda tem " << total << " dias de vida" << std::endl;
    } else {
        std::cout << "Foi de base" << std::endl;
    }
    return 0;
}
