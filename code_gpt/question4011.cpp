/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int votosA, votosB, votosC, votosNulos;
    std::cout << "Digite a quantidade de votos do candidato A:\n";
    std::cin >> votosA;
    std::cout << "Digite a quantidade de votos do candidato B:\n";
    std::cin >> votosB;
    std::cout << "Digite a quantidade de votos do candidato C:\n";
    std::cin >> votosC;
    std::cout << "Digite a quantidade de votos nulos:\n";
    std::cin >> votosNulos;

    int totalVotos = votosA + votosB + votosC + votosNulos;

    if (totalVotos > 0) {
        double percentualA = (static_cast<double>(votosA) / totalVotos) * 100;
        double percentualB = (static_cast<double>(votosB) / totalVotos) * 100;
        double percentualC = (static_cast<double>(votosC) / totalVotos) * 100;
        double percentualNulos = (static_cast<double>(votosNulos) / totalVotos) * 100;

        std::cout << std::fixed << std::setprecision(3);
        std::cout << "Candidato A: " << percentualA << " %\n";
        std::cout << "Candidato B: " << percentualB << " %\n";
        std::cout << "Candidato C: " << percentualC << " %\n";
        std::cout << "Votos Nulos: " << percentualNulos << " %\n";
    }

    return 0;
}
