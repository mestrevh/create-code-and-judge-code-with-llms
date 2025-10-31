/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int sexo;
    double altura;

    std::cout << "Digite o sexo: (0 - M e 1 - F)" << std::endl;
    std::cin >> sexo;
    std::cout << "Digite a altura em metros:" << std::endl;
    std::cin >> altura;

    if (sexo != 0 && sexo != 1) {
        std::cout << "O sexo informado e invalido." << std::endl;
    } else if (altura <= 0) {
        std::cout << "Altura invalida." << std::endl;
    } else {
        double peso_ideal;
        if (sexo == 0) {
            peso_ideal = (72.7 * altura) - 58.0;
        } else {
            peso_ideal = (62.1 * altura) - 44.7;
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Peso ideal: " << peso_ideal << " kg" << std::endl;
    }

    return 0;
}
