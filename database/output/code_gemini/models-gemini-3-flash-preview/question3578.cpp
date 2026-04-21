/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double a, b;
    if (std::cin >> a >> b) {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << a + b << "\n";
        std::cout << a - b << "\n";
        std::cout << a * b << "\n";
        if (b != 0) {
            std::cout << a / b << "\n";
        } else {
            std::cout << "0.00" << "\n";
        }
    }

    return 0;
}