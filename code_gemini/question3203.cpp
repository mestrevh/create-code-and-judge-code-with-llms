/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_apartamentos;
    double valor_diaria_normal;

    std::cin >> num_apartamentos >> valor_diaria_normal;

    double valor_diaria_promocional = std::round((valor_diaria_normal * 0.75) * 100.0) / 100.0;

    double total_arrecadado_100 = valor_diaria_promocional * num_apartamentos * 2.0;
    
    double total_arrecadado_70 = valor_diaria_promocional * (num_apartamentos * 0.70) * 2.0;

    double valor_nao_arrecadado = (valor_diaria_normal - valor_diaria_promocional) * num_apartamentos * 2.0;

    std::cout << std::fixed;
    std::cout << std::setprecision(2) << valor_diaria_promocional << std::endl;
    std::cout << std::setprecision(1) << total_arrecadado_100 << std::endl;
    std::cout << std::setprecision(1) << total_arrecadado_70 << std::endl;
    std::cout << std::setprecision(1) << valor_nao_arrecadado << std::endl;

    return 0;
}
