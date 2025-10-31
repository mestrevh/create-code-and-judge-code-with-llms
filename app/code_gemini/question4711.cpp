/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

void converter_moeda(double reais) {
    const double taxa_cambio = 5.75;
    double dolares = reais / taxa_cambio;
    
    std::cout << std::fixed << std::setprecision(2);
    
    if (reais == static_cast<int>(reais)) {
        std::cout << "A cotação de R$" << std::fixed << std::setprecision(1) << reais << " para dólar é US$" << std::fixed << std::setprecision(2) << dolares << std::endl;
    } else {
        std::cout << "A cotação de R$" << reais << " para dólar é US$" << dolares << std::endl;
    }
}

int main() {
    double valor_em_reais;
    std::cin >> valor_em_reais;
    converter_moeda(valor_em_reais);
    return 0;
}
