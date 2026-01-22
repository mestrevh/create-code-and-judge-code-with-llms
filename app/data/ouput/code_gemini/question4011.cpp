/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double votosA, votosB, votosC, votosNulos;

    std::cout << "Digite a quantidade de votos do candidato A:" << std::endl;
    std::cin >> votosA;

    std::cout << "Digite a quantidade de votos do candidato B:" << std::endl;
    std::cin >> votosB;

    std::cout << "Digite a quantidade de votos do candidato C:" << std::endl;
    std::cin >> votosC;

    std::cout << "Digite a quantidade de votos nulos:" << std::endl;
    std::cin >> votosNulos;

    double totalVotos = votosA + votosB + votosC + votosNulos;

    std::cout << std::fixed << std::setprecision(3);

    if (totalVotos > 0) {
        std::cout << "Candidato A: " << (votosA / totalVotos) * 100.0 << " %" << std::endl;
        std::cout << "Candidato B: " << (votosB / totalVotos) * 100.0 << " %" << std::endl;
        std::cout << "Candidato C: " << (votosC / totalVotos) * 100.0 << " %" << std::endl;
        std::cout << "Votos Nulos: " << (votosNulos / totalVotos) * 100.0 << " %" << std::endl;
    } else {
        std::cout << "Candidato A: 0.000 %" << std::endl;
        std::cout << "Candidato B: 0.000 %" << std::endl;
        std::cout << "Candidato C: 0.000 %" << std::endl;
        std::cout << "Votos Nulos: 0.000 %" << std::endl;
    }

    return 0;
}
