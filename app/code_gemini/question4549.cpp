/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double fatura_marco;
    std::cin >> fatura_marco;

    double pagamento_marco = fatura_marco / 2.0;
    double restante = fatura_marco / 2.0;
    double pagamento_abril = restante * 1.065;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Valor total da fatura: R$ " << fatura_marco << std::endl;
    std::cout << "Valor a pagar em Marco: R$ " << pagamento_marco << std::endl;
    std::cout << "Valor a pagar em Abril: R$ " << pagamento_abril << std::endl;

    return 0;
}
