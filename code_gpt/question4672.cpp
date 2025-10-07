/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

struct Aluno {
    std::string nome;
    int idade;
};

int main() {
    int N;
    std::cin >> N;
    std::vector<Aluno> alunos(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> alunos[i].nome >> alunos[i].idade;
    }

    for (const auto& aluno : alunos) {
        if (aluno.idade <= 14) {
            std::cout << aluno.nome << std::endl << aluno.idade << std::endl;
        }
    }
    for (const auto& aluno : alunos) {
        if (aluno.idade > 14) {
            std::cout << aluno.nome << std::endl << aluno.idade << std::endl;
        }
    }

    return 0;
}
