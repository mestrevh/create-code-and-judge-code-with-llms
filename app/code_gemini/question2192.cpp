/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long d_ll, r_ll, l_ll, p_ll, g_ll;
    std::cin >> d_ll >> r_ll >> l_ll >> p_ll >> g_ll;

    double d = static_cast<double>(d_ll);
    double r = static_cast<double>(r_ll);
    double l = static_cast<double>(l_ll);
    double p = static_cast<double>(p_ll);
    double g = static_cast<double>(g_ll);

    double max_range = l * 10.0;
    double segment_dist = d / (p + 1.0);

    if (segment_dist > max_range) {
        std::cout << "Nao pode viajar." << std::endl;
        return 0;
    }

    double total_fuel_needed = d / 10.0;
    double fuel_to_buy = 0.0;

    if (total_fuel_needed > l) {
        fuel_to_buy = total_fuel_needed - l;
    }

    double cost = fuel_to_buy * g;

    if (cost > r) {
        std::cout << "Nao pode viajar." << std::endl;
    } else {
        long long money_left = static_cast<long long>(r - cost);
        std::cout << "Pode viajar." << std::endl;
        std::cout << "R$: " << money_left << std::endl;
    }

    return 0;
}
