/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int max_sum = -1;
    int result_number = 0;
    int current_number;

    for (int i = 0; i < 5; ++i) {
        std::cin >> current_number;
        int current_sum = sum_divisors(current_number);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            result_number = current_number;
        }
    }

    std::cout << result_number << std::endl;

    return 0;
}
