/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main() {
    std::string nomes[5];
    int idades[5], soma = 0;
    double mediaAritmetica, mediaGeometrica = 1.0;

    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin, nomes[i]);
        double idade;
        std::cin >> idade;
        idade = fabs(idade);
        idades[i] = static_cast<int>(idade);
        soma += idades[i];
        mediaGeometrica *= idades[i];
        std::cin.ignore(); 
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << "Pessoa: " << nomes[i] << " , " << idades[i] << std::endl;
    }

    mediaAritmetica = static_cast<double>(soma) / 5;
    mediaGeometrica = pow(mediaGeometrica, 1.0 / 5.0);

    std::cout << soma << std::endl;
    std::cout << std::fixed << std::setprecision(1) << mediaAritmetica << std::endl;
    std::cout << static_cast<int>(mediaGeometrica) << std::endl;

    return 0;
}
