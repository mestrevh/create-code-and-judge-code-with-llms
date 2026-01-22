/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    char sexo;
    double altura;

    std::cin >> sexo >> altura;

    if (altura <= 0) {
        std::cout << "Altura invalida." << std::endl;
    } else if (sexo == 'm') {
        double peso_ideal = (72.7 * altura) - 58;
        std::cout << std::fixed << std::setprecision(2) << peso_ideal << std::endl;
    } else if (sexo == 'f') {
        double peso_ideal = (62.1 * altura) - 44.7;
        std::cout << std::fixed << std::setprecision(2) << peso_ideal << std::endl;
    } else {
        std::cout << "O sexo informado eh invalido." << std::endl;
    }

    return 0;
}
