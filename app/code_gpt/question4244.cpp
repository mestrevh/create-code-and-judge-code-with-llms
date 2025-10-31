/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Aluno {
    std::string nome;
    float nota1, nota2, nota3;
    float media;
    std::string situacao;
};

bool comparaAlunos(const Aluno &a, const Aluno &b) {
    return a.nome < b.nome;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Aluno> alunos(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> alunos[i].nome;
        std::cin >> alunos[i].nota1 >> alunos[i].nota2 >> alunos[i].nota3;
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;

        if (alunos[i].media >= 7.0) {
            alunos[i].situacao = "Aprovado";
        } else if (alunos[i].media >= 4.0) {
            alunos[i].situacao = "Final";
        } else {
            alunos[i].situacao = "Reprovado";
        }
    }

    std::sort(alunos.begin(), alunos.end(), comparaAlunos);

    for (const auto &aluno : alunos) {
        std::cout << "Aluno: " << aluno.nome << "\n";
        std::cout << "Media: " << std::fixed << std::setprecision(2) << aluno.media << "\n";
        std::cout << "Situacao: " << aluno.situacao << "\n\n";
    }

    return 0;
}
