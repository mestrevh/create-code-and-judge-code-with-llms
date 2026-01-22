/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int p, m, g;

    std::cin >> n;
    std::cin >> p >> m >> g;

    double base_price_p = p * 25.0;
    double base_price_m = m * 40.0;
    double base_price_g = g * 70.0;
    
    double total_base_price = base_price_p + base_price_m + base_price_g;
    double total_fees = 0.0;
    double final_total = total_base_price;

    if (is_prime(n)) {
        double final_price_p = base_price_p * pow(1.125, n);
        double final_price_m = base_price_m * pow(1.29, n);
        double final_price_g = base_price_g * pow(1.22, n);
        
        final_total = final_price_p + final_price_m + final_price_g;
        total_fees = final_total - total_base_price;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << total_fees << std::endl;
    std::cout << final_total << std::endl;

    return 0;
}
