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

    double F;
    int n;
    double t;

    std::cin >> F;
    std::cin >> n;
    std::cin >> t;

    double common_term = pow(1.0 + t, n);
    double a_n_t = (common_term - 1.0) / (t * common_term);
    double P = F / a_n_t;
    
    int installment_value = static_cast<int>(P);
    
    std::cout << installment_value << std::endl;

    return 0;
}
