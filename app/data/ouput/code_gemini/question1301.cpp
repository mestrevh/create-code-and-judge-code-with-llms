/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric>

struct Aluno {
    std::string nome;
    double nota = -1.0;
};

std::vector<Aluno> lerDadosTurma() {
    std::vector<Aluno> turma;
    std::string nome;
    while (std::cin >> nome && nome != "*") {
        Aluno aluno;
        aluno.nome = nome;
        std::cin >> aluno.nota;
        turma.push_back(aluno);
    }
    return turma;
}

Aluno encontrarMelhorAluno(const std::vector<Aluno>& turma) {
    if (turma.empty()) {
        return Aluno{"", -1.0};
    }

    Aluno melhor = turma[0];
    for (size_t i = 1; i < turma.size(); ++i) {
        if (turma[i].nota > melhor.nota) {
            melhor = turma[i];
        }
    }
    return melhor;
}

double calcularMedia(const std::vector<Aluno>& turma) {
    if (turma.empty()) {
        return 0.0;
    }
    double soma = 0.0;
    for (const auto& aluno : turma) {
        soma += aluno.nota;
    }
    return soma / turma.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Aluno> turmaA = lerDadosTurma();
    std::vector<Aluno> turmaB = lerDadosTurma();

    double mediaA = calcularMedia(turmaA);
    double mediaB = calcularMedia(turmaB);

    bool viagemA = mediaA > 8.0;
    bool viagemB = mediaB > 8.0;

    if (viagemA && viagemB) {
        std::cout << "Viagem para todos!" << std::endl;
    } else if (viagemA) {
        std::cout << "Viagem para turma A" << std::endl;
    } else if (viagemB) {
        std::cout << "Viagem para turma B" << std::endl;
    } else {
        std::cout << "Nenhuma das turmas viaja..." << std::endl;
    }

    Aluno melhorA = encontrarMelhorAluno(turmaA);
    Aluno melhorB = encontrarMelhorAluno(turmaB);

    Aluno melhorGeral;
    if (melhorA.nota > melhorB.nota) {
        melhorGeral = melhorA;
    } else {
        melhorGeral = melhorB;
    }

    if (melhorGeral.nota > 8.0) {
        std::cout << melhorGeral.nome << " ganhou viagem e ingresso no parque!" << std::endl;
        std::cout << "Nota: " << std::fixed << std::setprecision(2) << melhorGeral.nota << std::endl;
    } else {
        std::cout << "Ninguem ganhou viagem e ingresso no parque..." << std::endl;
    }

    return 0;
}
