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

    const std::vector<double> base_weights = {
        1674.00,
        23.14,
        52.65,
        60.00,
        22.78,
        151.84,
        64.29,
        52.04,
        66.12,
        36.00,
        10.22
    };
    
    double input_value;
    std::cin >> input_value;
    
    double ratio = input_value / 60.0;
    
    std::cout << std::fixed << std::setprecision(2);
    
    for (const double& base_weight : base_weights) {
        std::cout << base_weight * ratio << '\n';
    }
    
    return 0;
}
