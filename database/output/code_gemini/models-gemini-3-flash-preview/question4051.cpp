/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n1, n2;
    if (std::cin >> n1 >> n2) {
        std::cout << n1 << " + " << n2 << " = " << (n1 + n2) << "\n";
        std::cout << n1 << " - " << n2 << " = " << (n1 - n2) << "\n";
        std::cout << n1 << " * " << n2 << " = " << (n1 * n2) << "\n";
        if (n2 != 0) {
            std::cout << n1 << " / " << n2 << " = " << (n1 / n2) << "\n";
            std::cout << n1 << " % " << n2 << " = " << (n1 % n2) << "\n";
        }
    }

    return 0;
}