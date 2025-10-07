/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Aluno {
    std::string nome;
    int idade;
    double nota;
};

bool compNota(const Aluno &a, const Aluno &b) {
    return a.nota < b.nota;
}

bool compIdade(const Aluno &a, const Aluno &b) {
    return a.idade < b.idade;
}

double media(const std::vector<Aluno> &alunos, char tipo) {
    double soma = 0;
    for (const auto &a : alunos) {
        soma += (tipo == 'n') ? a.nota : a.idade;
    }
    return soma / alunos.size();
}

double mediana(std::vector<Aluno> alunos, char tipo) {
    if (tipo == 'n') {
        std::sort(alunos.begin(), alunos.end(), compNota);
    } else {
        std::sort(alunos.begin(), alunos.end(), compIdade);
    }
    int n = alunos.size();
    return (n % 2 == 0) ? (tipo == 'n' ? (alunos[n/2 - 1].nota + alunos[n/2].nota) / 2 : (alunos[n/2 - 1].idade + alunos[n/2].idade) / 2) :
                          (tipo == 'n' ? alunos[n/2].nota : alunos[n/2].idade);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Aluno> alunos(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> alunos[i].nome >> alunos[i].idade >> alunos[i].nota;
    }

    std::vector<Aluno> alunosPorNota = alunos;
    std::vector<Aluno> alunosPorIdade = alunos;

    std::sort(alunosPorNota.begin(), alunosPorNota.end(), compNota);
    std::sort(alunosPorIdade.begin(), alunosPorIdade.end(), compIdade);

    std::cout << "--- Notas ---\n";
    for (const auto &aluno : alunosPorNota) {
        std::cout << aluno.nome << " " << std::fixed << std::setprecision(2) << aluno.nota << "\n";
    }
    std::cout << "---------\n";
    std::cout << "Media Nota: " << std::fixed << std::setprecision(2) << media(alunos, 'n') << "\n";
    std::cout << "Mediana Nota: " << std::fixed << std::setprecision(2) << mediana(alunos, 'n') << "\n\n";

    std::cout << "--- Idade ---\n";
    for (const auto &aluno : alunosPorIdade) {
        std::cout << aluno.nome << " " << aluno.idade << "\n";
    }
    std::cout << "---------\n";
    std::cout << "Media Idade: " << std::fixed << std::setprecision(2) << media(alunos, 'i') << "\n";
    std::cout << "Mediana Idade: " << std::fixed << std::setprecision(2) << mediana(alunos, 'i') << "\n";

    return 0;
}
