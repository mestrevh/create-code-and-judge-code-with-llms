/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n;
    while (std::cin >> n) {
        // The formula for the n-th incomplete hexagonal number 
        // based on the provided sequence 1, 6, 13, 24 is:
        // If n is even: (3 * n^2) / 2
        // If n is odd: (3 * n^2 - 1) / 2
        // Both can be computed using integer division: (3 * n * n) / 2
        std::cout << (3LL * n * n) / 2 << "\n";
    }

    return 0;
}