/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

struct Aluno {
    std::string nome;
    double ab1;
    double ab2;
    double media;
    std::string situacao;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Aluno> alunos(n);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, alunos[i].nome);
        std::cin >> alunos[i].ab1 >> alunos[i].ab2;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        alunos[i].media = (alunos[i].ab1 + alunos[i].ab2) / 2.0;

        if (alunos[i].media >= 7.0) {
            alunos[i].situacao = "AP";
        } else {
            alunos[i].situacao = "RP";
        }
    }

    std::cout << std::fixed << std::setprecision(2);

    for (const auto& aluno : alunos) {
        std::cout << "Nome:  " << aluno.nome << '\n';
        std::cout << "AB1: " << aluno.ab1 << '\n';
        std::cout << "AB2: " << aluno.ab2 << '\n';
        std::cout << "Media: " << aluno.media << '\n';
        std::cout << "Situacao:  " << aluno.situacao << '\n';
    }

    return 0;
}
