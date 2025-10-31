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

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Candidato A: " << (static_cast<double>(votosA) / totalVotos) * 100 << " %\n";
    std::cout << "Candidato B: " << (static_cast<double>(votosB) / totalVotos) * 100 << " %\n";
    std::cout << "Candidato C: " << (static_cast<double>(votosC) / totalVotos) * 100 << " %\n";
    std::cout << "Votos Nulos: " << (static_cast<double>(votosNulos) / totalVotos) * 100 << " %\n";

    return 0;
}
