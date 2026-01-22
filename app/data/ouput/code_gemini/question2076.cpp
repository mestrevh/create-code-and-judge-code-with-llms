/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> a >> b;
    int best_number = 0;
    int max_divisors = -1;
    for (int i = a; i <= b; ++i) {
        int current_divisors = 0;
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                if (i / j == j) {
                    current_divisors++;
                } else {
                    current_divisors += 2;
                }
            }
        }
        if (current_divisors > max_divisors) {
            max_divisors = current_divisors;
            best_number = i;
        }
    }
    std::cout << best_number << " " << max_divisors << std::endl;
    return 0;
}
