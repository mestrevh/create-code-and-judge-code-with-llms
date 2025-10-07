/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<double> block_diagonals;

    for (int i = 0; i < n; ++i) {
        std::string shape;
        std::cin >> shape;

        if (shape == "CIRCULAR") {
            double r;
            std::cin >> r;
        } else if (shape == "RETANGULAR") {
            double b, l;
            std::cin >> b >> l;
            double diagonal = std::sqrt(b * b + l * l);
            block_diagonals.push_back(diagonal);
        }
    }

    double compartment_diameter;
    std::cin >> compartment_diameter;

    bool found_fit = false;
    std::cout << std::fixed << std::setprecision(2);

    for (double d : block_diagonals) {
        if (d <= compartment_diameter) {
            std::cout << d << std::endl;
            found_fit = true;
        }
    }

    if (!found_fit) {
        std::cout << -1 << std::endl;
    }

    return 0;
}
