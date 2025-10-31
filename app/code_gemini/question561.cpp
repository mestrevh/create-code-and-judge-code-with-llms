/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    long long n;
    std::cin >> n;
    long long total_digits = 0;
    long long num_digits = 1;
    long long power_of_10 = 1;
    while (true) {
        long long upper_bound = power_of_10 * 10;
        if (n < upper_bound) {
            total_digits += (n - power_of_10 + 1) * num_digits;
            break;
        }
        total_digits += (power_of_10 * 9) * num_digits;
        power_of_10 *= 10;
        num_digits++;
    }
    std::cout << total_digits << std::endl;
    return 0;
}
