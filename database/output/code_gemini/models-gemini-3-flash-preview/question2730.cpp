/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

/**
 * @brief Prints a line composed of n asterisks.
 * @param n Number of asterisks to print.
 */
void print_asterisks(int n) {
    if (n > 0) {
        std::string line(n, '*');
        std::cout << line << "\n";
    }
}

int main() {
    // Fast I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        print_asterisks(n);
    }

    return 0;
}