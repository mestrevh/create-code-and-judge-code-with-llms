/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Aluno {
    std::string nome;
    double nota;
};

void lerTurma(std::vector<Aluno>& turma) {
    Aluno aluno;
    while (true) {
        std::cin >> aluno.nome;
        if (aluno.nome == "*") break;
        std::cin >> aluno.nota;
        turma.push_back(aluno);
    }
}

double mediaTurma(const std::vector<Aluno>& turma) {
    double soma = 0;
    for (const auto& aluno : turma) {
        soma += aluno.nota;
    }
    return turma.empty() ? 0 : soma / turma.size();
}

Aluno melhorAluno(const std::vector<Aluno>& turma) {
    Aluno melhor{"", 0};
    for (const auto& aluno : turma) {
        if (aluno.nota > melhor.nota) {
            melhor = aluno;
        }
    }
    return melhor;
}

int main() {
    std::vector<Aluno> turmaA, turmaB;
    lerTurma(turmaA);
    lerTurma(turmaB);

    double mediaA = mediaTurma(turmaA);
    double mediaB = mediaTurma(turmaB);

    bool viagemA = mediaA > 8;
    bool viagemB = mediaB > 8;

    if (viagemA && viagemB) {
        std::cout << "Viagem para todos!" << std::endl;
    } else if (viagemA) {
        std::cout << "Viagem para turma A" << std::endl;
    } else if (viagemB) {
        std::cout << "Viagem para turma B" << std::endl;
    } else {
        std::cout << "Nenhuma das turmas viaja..." << std::endl;
    }

    Aluno melhorA = melhorAluno(turmaA);
    Aluno melhorB = melhorAluno(turmaB);
    Aluno melhor;

    if (melhorA.nota > 8 && melhorA.nota > melhorB.nota) {
        melhor = melhorA;
    } else if (melhorB.nota > 8) {
        melhor = melhorB;
    }

    if (melhor.nota > 0) {
        std::cout << melhor.nome << " ganhou viagem e ingresso no parque!" << std::endl;
        std::cout << "Nota: " << std::fixed << std::setprecision(2) << melhor.nota << std::endl;
    } else {
        std::cout << "Ninguem ganhou viagem e ingresso no parque..." << std::endl;
    }

    return 0;
}
