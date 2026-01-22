/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

std::string formatar_dinheiro(double valor) {
    std::stringstream ss;
    ss.imbue(std::locale("pt_BR.UTF-8"));
    ss << std::fixed << std::setprecision(2) << valor;

    std::string resultado = "R$ " + ss.str();
    return resultado;
}

int main() {
    double valor;
    std::cin >> valor;

    std::cout << formatar_dinheiro(valor) << std::endl;

    return 0;
}
