/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    while (std::cin >> n && n != -1) {
        long long original_n = n;
        int count = 0;

        while (n % 2 == 0) {
            count++;
            n /= 2;
        }

        for (long long i = 3; i * i <= n; i = i + 2) {
            while (n % i == 0) {
                count++;
                n /= i;
            }
        }

        if (n > 1) {
            count++;
        }

        if (count == 4) {
            std::cout << original_n << " eh um primo de 4\n";
        } else {
            std::cout << original_n << ", eu nunca duvidei\n";
        }
    }

    return 0;
}
