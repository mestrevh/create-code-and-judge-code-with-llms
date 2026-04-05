/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (std::cin >> n) {
        // Condition 1: Number does not end in zero.
        // Condition 2: If the rightmost digit is removed, remaining is a divisor.
        // For 10 <= n <= 100, removing the rightmost digit is integer division by 10.
        if (n % 10 != 0 && (n / 10) > 0 && n % (n / 10) == 0) {
            std::cout << "SIM" << std::endl;
        } else {
            std::cout << "NAO" << std::endl;
        }
    }
    return 0;
}