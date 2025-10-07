/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Aluno {
    std::string nome;
    double notaAB1;
    double notaAB2;
    double media;
    std::string situacao;
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    
    std::vector<Aluno> alunos(n);

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, alunos[i].nome);
        std::cin >> alunos[i].notaAB1 >> alunos[i].notaAB2;
        std::cin.ignore();

        alunos[i].media = (alunos[i].notaAB1 + alunos[i].notaAB2) / 2.0;
        alunos[i].situacao = (alunos[i].media >= 7.0) ? "AP" : "RP";
    }

    for (const auto& aluno : alunos) {
        std::cout << "Nome: " << aluno.nome << std::endl;
        std::cout << "AB1: " << std::fixed << std::setprecision(2) << aluno.notaAB1 << std::endl;
        std::cout << "AB2: " << std::fixed << std::setprecision(2) << aluno.notaAB2 << std::endl;
        std::cout << "Media: " << std::fixed << std::setprecision(2) << aluno.media << std::endl;
        std::cout << "Situacao: " << aluno.situacao << std::endl;
    }

    return 0;
}
