/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

int main() {
    std::string gabarito;
    std::cin >> gabarito;
    
    int aluno;
    std::string respostas;
    
    std::map<int, int> notas;
    int totalAlunos = 0, aprovados = 0;

    while (true) {
        std::cin >> aluno;
        if (aluno == 9999) break;
        std::cin >> respostas;

        int nota = 0;
        for (int i = 0; i < 10; ++i) {
            if (gabarito[i] == respostas[i]) {
                nota++;
            }
        }
        
        notas[nota]++;
        totalAlunos++;
        if (nota >= 6) aprovados++;

        std::cout << aluno << " " << std::fixed << std::setprecision(1) << nota << "\n";
    }

    double porcentagem = (static_cast<double>(aprovados) / totalAlunos) * 100;
    std::cout << std::fixed << std::setprecision(1) << porcentagem << "%\n";

    int notaMaisFrequente = 0, freqMaxima = 0;
    for (const auto& n : notas) {
        if (n.second > freqMaxima) {
            freqMaxima = n.second;
            notaMaisFrequente = n.first;
        }
    }
    
    std::cout << notaMaisFrequente << "\n";
    return 0;
}
