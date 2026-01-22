/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iomanip>

struct Aluno {
    int matricula;
    std::string nome;
    double nota;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (n == 0) {
        std::cout << "Alunos abaixo da media:" << std::endl;
        std::cout << "Alunos iguais ou acima da media:" << std::endl;
        std::cout << "Media = " << std::fixed << std::setprecision(2) << 0.0 << std::endl;
        return 0;
    }

    std::vector<Aluno> todos_alunos;
    double soma_notas = 0.0;

    for (int i = 0; i < n; ++i) {
        std::string linha;
        std::getline(std::cin, linha);

        size_t pos1 = linha.find('-');
        size_t pos2 = linha.rfind('-');

        Aluno aluno;
        aluno.matricula = std::stoi(linha.substr(0, pos1));
        aluno.nome = linha.substr(pos1 + 1, pos2 - pos1 - 1);
        aluno.nota = std::stod(linha.substr(pos2 + 1));

        todos_alunos.push_back(aluno);
        soma_notas += aluno.nota;
    }

    double media = soma_notas / n;

    std::vector<Aluno> abaixo_media;
    std::vector<Aluno> acima_media;

    for (const auto& aluno : todos_alunos) {
        if (aluno.nota < media) {
            abaixo_media.push_back(aluno);
        } else {
            acima_media.push_back(aluno);
        }
    }

    auto comparaAlunos = [](const Aluno& a, const Aluno& b) {
        if (a.nota != b.nota) {
            return a.nota < b.nota;
        }
        return a.matricula < b.matricula;
    };

    std::sort(abaixo_media.begin(), abaixo_media.end(), comparaAlunos);
    std::sort(acima_media.begin(), acima_media.end(), comparaAlunos);

    std::cout << "Alunos abaixo da media:" << std::endl;
    for (const auto& aluno : abaixo_media) {
        std::cout << "Matricula: " << aluno.matricula
                  << " Nome: " << aluno.nome
                  << " Nota: " << std::fixed << std::setprecision(1) << aluno.nota
                  << std::endl;
    }

    std::cout << "Alunos iguais ou acima da media:" << std::endl;
    for (const auto& aluno : acima_media) {
        std::cout << "Matricula: " << aluno.matricula
                  << " Nome: " << aluno.nome
                  << " Nota: " << std::fixed << std::setprecision(1) << aluno.nota
                  << std::endl;
    }

    std::cout << "Media = " << std::fixed << std::setprecision(2) << media << std::endl;

    return 0;
}
