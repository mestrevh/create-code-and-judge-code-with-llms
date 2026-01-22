/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<double> fx_values;
    for (int i = 0; i <= 20; ++i) {
        double x = -5.0 + i * 0.5;
        fx_values.push_back(sin(x + 0.5));
    }

    std::cout << "fx =" << std::endl << std::endl;
    std::cout << std::fixed << std::setprecision(5);

    for (size_t i = 0; i < fx_values.size(); i += 8) {
        size_t end = std::min(static_cast<size_t>(i + 8), fx_values.size());

        std::cout << " Columns " << i + 1 << " through " << end << ":" << std::endl << std::endl;

        std::cout << "  ";
        for (size_t j = i; j < end; ++j) {
            std::cout << std::right << std::setw(10) << fx_values[j];
        }
        std::cout << std::endl;

        if (end < fx_values.size()) {
            std::cout << std::endl;
        }
    }

    return 0;
}
