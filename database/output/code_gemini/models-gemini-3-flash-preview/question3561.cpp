/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double fahrenheit;
    if (std::cin >> fahrenheit) {
        double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        std::cout << std::fixed << std::setprecision(2) << celsius << "\n";
    }

    return 0;
}