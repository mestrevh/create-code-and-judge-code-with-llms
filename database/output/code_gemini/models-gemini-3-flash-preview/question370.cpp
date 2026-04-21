/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long dias;
    if (std::cin >> dias) {
        double total = static_cast<double>(dias) * 20.0 * 3.20;
        std::cout << std::fixed << std::setprecision(2) << total << std::endl;
    }

    return 0;
}