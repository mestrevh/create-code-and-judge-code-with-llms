/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

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

    int N, M;
    std::cin >> N >> M;

    if (N <= 0 || N > 10 || M <= 0 || M > 10) {
        std::cout << "Han??" << std::endl;
        return 0;
    }

    int prime_participants_count = 0;

    for (int i = 0; i < N; ++i) {
        int total_fights = 0;
        for (int j = 0; j < M; ++j) {
            int fights_in_year;
            std::cin >> fights_in_year;
            total_fights += fights_in_year;
        }
        if (isPrime(total_fights)) {
            prime_participants_count++;
        }
    }

    if (prime_participants_count * 2 > N) {
        std::cout << "Chama" << std::endl;
    } else {
        std::cout << "Não chama" << std::endl;
    }

    return 0;
}
