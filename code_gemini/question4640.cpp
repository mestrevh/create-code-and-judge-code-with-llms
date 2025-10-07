/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>

struct Aluno {
    std::string nome;
    int idade;
    double nota;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Aluno> alunos(n);
    double soma_notas = 0.0;
    double soma_idades = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> alunos[i].nome >> alunos[i].idade >> alunos[i].nota;
        soma_notas += alunos[i].nota;
        soma_idades += alunos[i].idade;
    }

    std::cout << std::fixed << std::setprecision(2);

    // --- Processamento por Notas ---
    std::cout << "---Notas---" << "\n";

    std::sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.nota < b.nota;
    });

    for (const auto& aluno : alunos) {
        std::cout << aluno.nome << " " << aluno.nota << "\n";
    }

    std::cout << "---------" << "\n";

    double media_nota = soma_notas / n;
    double mediana_nota;
    if (n % 2 == 1) {
        mediana_nota = alunos[n / 2].nota;
    } else {
        mediana_nota = (alunos[n / 2 - 1].nota + alunos[n / 2].nota) / 2.0;
    }
    std::cout << "Media Nota: " << media_nota << "\n";
    std::cout << "Mediana Nota: " << mediana_nota << "\n";
    std::cout << "\n";

    // --- Processamento por Idade ---
    std::cout << "---Idade---" << "\n";

    std::sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.idade < b.idade;
    });

    for (const auto& aluno : alunos) {
        std::cout << aluno.nome << " " << aluno.idade << "\n";
    }

    std::cout << "---------" << "\n";

    double media_idade = soma_idades / n;
    double mediana_idade;
    if (n % 2 == 1) {
        mediana_idade = static_cast<double>(alunos[n / 2].idade);
    } else {
        mediana_idade = (static_cast<double>(alunos[n / 2 - 1].idade) + static_cast<double>(alunos[n / 2].idade)) / 2.0;
    }
    std::cout << "Media Idade: " << media_idade << "\n";
    std::cout << "Mediana Idade: " << mediana_idade << "\n";

    return 0;
}
