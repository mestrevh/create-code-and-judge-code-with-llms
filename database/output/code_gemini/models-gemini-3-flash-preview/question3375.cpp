/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double h, r, cost_per_can, liters_per_can, coverage_per_liter;

    if (!(std::cin >> h >> r >> cost_per_can >> liters_per_can >> coverage_per_liter)) {
        return 0;
    }

    const double PI = std::acos(-1.0);
    
    // Area = 2 * PI * r^2 + 2 * PI * r * h
    // Area = 2 * PI * r * (r + h)
    double area = 2.0 * PI * r * (r + h);
    
    // Total liters needed for the calculated area
    double total_liters = area / coverage_per_liter;
    
    // Number of cans is the total liters needed divided by liters per can, rounded up
    double cans_needed = std::ceil(total_liters / liters_per_can);
    
    // Total cost
    double total_cost = cans_needed * cost_per_can;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Quantidade de latas: " << cans_needed << "\n";
    std::cout << "Custo: R$" << total_cost << "\n";

    return 0;
}