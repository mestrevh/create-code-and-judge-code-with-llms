/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double salary;
    if (std::cin >> salary) {
        double result = salary * 1.075;
        std::cout << std::fixed << std::setprecision(2) << result << "\n";
    }
    return 0;
}