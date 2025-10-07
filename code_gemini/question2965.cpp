/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    double area;
    std::cin >> area;

    const double coverage_per_liter = 7.0;
    const double large_can_liters = 24.0;
    const double small_can_liters = 5.4;
    const double large_can_price = 91.00;
    const double small_can_price = 23.00;

    double total_liters_needed = area / coverage_per_liter;

    std::cout << std::fixed << std::setprecision(2);

    // a) Only large cans
    int num_cans_a = static_cast<int>(ceil(total_liters_needed / large_can_liters));
    double cost_a = num_cans_a * large_can_price;
    std::cout << "a) " << num_cans_a << " lata(s) de 24 litros: R$ " << cost_a << std::endl;

    // b) Only small cans
    int num_cans_b = static_cast<int>(ceil(total_liters_needed / small_can_liters));
    double cost_b = num_cans_b * small_can_price;
    std::cout << "b) " << num_cans_b << " lata(s) de 5.4 litros: R$ " << cost_b << std::endl;

    // c) Mixed cans
    int num_large_cans_c = static_cast<int>(floor(total_liters_needed / large_can_liters));
    double liters_remaining = total_liters_needed - (num_large_cans_c * large_can_liters);
    int num_small_cans_c = 0;
    if (liters_remaining > 0) {
        num_small_cans_c = static_cast<int>(ceil(liters_remaining / small_can_liters));
    }
    double cost_c = (num_large_cans_c * large_can_price) + (num_small_cans_c * small_can_price);
    std::cout << "c) " << num_large_cans_c << " lata(s) de 24 litros e " << num_small_cans_c << " lata(s) de 5.4 litros: R$ " << cost_c << std::endl;

    return 0;
}
