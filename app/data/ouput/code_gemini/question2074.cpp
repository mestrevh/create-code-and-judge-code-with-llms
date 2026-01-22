/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int original_n = n;
    int sum_of_factorials = 0;
    if (n == 0) {
        sum_of_factorials = 1;
    } else {
        while (n > 0) {
            int digit = n % 10;
            sum_of_factorials += factorials[digit];
            n /= 10;
        }
    }
    if (sum_of_factorials == original_n) {
        std::cout << "S" << std::endl;
    } else {
        std::cout << "N" << std::endl;
        std::cout << sum_of_factorials << std::endl;
    }
    return 0;
}
