/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> diagonal_elements;
    double trace_sum = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double value;
            std::cin >> value;
            if (i == j) {
                diagonal_elements.push_back(value);
                trace_sum += value;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "tr(A) = ";

    for (size_t i = 0; i < diagonal_elements.size(); ++i) {
        std::cout << "(" << diagonal_elements[i] << ")";
        if (i < diagonal_elements.size() - 1) {
            std::cout << " + ";
        }
    }

    std::cout << " = " << trace_sum << std::endl;

    return 0;
}
