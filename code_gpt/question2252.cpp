/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

struct Aluno {
    std::string nome;
    double media;
};

double calcularMedia(std::vector<double> notas) {
    while (notas.size() < 3) {
        notas.push_back(0);
    }
    std::sort(notas.begin(), notas.end());
    notas[0] = std::max(notas[0], notas.size() > 3 ? notas[3] : 0.0);
    return (notas[1] + notas[2] + notas[0]) / 3.0;
}

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();
    std::vector<Aluno> alunos(N);

    for (int i = 0; i < N; ++i) {
        std::string linha;
        std::getline(std::cin, linha);
        std::stringstream ss(linha);
        std::string token;

        std::getline(ss, alunos[i].nome, ',');
        std::vector<double> notas;
        while (std::getline(ss, token, ',')) {
            notas.push_back(std::stod(token));
        }
        alunos[i].media = calcularMedia(notas);
    }

    std::sort(alunos.begin(), alunos.end(), [](const Aluno &a, const Aluno &b) {
        if (a.media == b.media) return a.nome < b.nome;
        return a.media < b.media;
    });

    for (const auto &aluno : alunos) {
        std::cout << aluno.nome << " " << std::fixed << std::setprecision(2) << aluno.media << std::endl;
    }

    return 0;
}
