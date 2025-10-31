/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

int main() {
    std::string comida, bebida;
    std::getline(std::cin, comida);
    std::getline(std::cin, bebida);

    std::transform(comida.begin(), comida.end(), comida.begin(), ::tolower);
    std::transform(bebida.begin(), bebida.end(), bebida.begin(), ::tolower);

    double total = 0.0;

    if (comida == "lasanha") total += 8.0;
    else if (comida == "estrogonofe") total += 11.0;

    if (bebida == "refrigerante") total += 3.0;
    else if (bebida == "suco") total += 2.5;

    std::cout << std::fixed << std::setprecision(2) << total << std::endl;

    return 0;
}
