/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int votosA, votosB, votosC, votosNulos;

    std::cin >> votosA >> votosB >> votosC >> votosNulos;

    std::cout << "Digite a quantidade de votos do candidato A:\n";
    std::cout << "Digite a quantidade de votos do candidato B:\n";
    std::cout << "Digite a quantidade de votos do candidato C:\n";
    std::cout << "Digite a quantidade de votos nulos:\n";

    double totalVotos = votosA + votosB + votosC + votosNulos;

    if (totalVotos > 0) {
        double pA = (static_cast<double>(votosA) / totalVotos) * 100.0;
        double pB = (static_cast<double>(votosB) / totalVotos) * 100.0;
        double pC = (static_cast<double>(votosC) / totalVotos) * 100.0;
        double pNulos = (static_cast<double>(votosNulos) / totalVotos) * 100.0;

        std::cout << "Candidato A: " << pA << " %\n";
        std::cout << "Candidato B: " << pB << " %\n";
        std::cout << "Candidato C: " << pC << " %\n";
        std::cout << "Votos Nulos: " << pNulos << " %\n";
    } else {
        std::cout << "Candidato A: 0 %\n";
        std::cout << "Candidato B: 0 %\n";
        std::cout << "Candidato C: 0 %\n";
        std::cout << "Votos Nulos: 0 %\n";
    }

    return 0;
}
