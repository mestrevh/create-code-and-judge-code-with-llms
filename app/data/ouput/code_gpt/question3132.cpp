/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Aluno {
    std::string matricula;
    std::string nome;
};

bool comparar(const Aluno &a, const Aluno &b) {
    return a.nome < b.nome;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<Aluno> alunos(N);

    for (int i = 0; i < N; i++) {
        std::string linha;
        std::cin >> linha;
        size_t pos = linha.find('-');
        alunos[i].matricula = linha.substr(0, pos);
        alunos[i].nome = linha.substr(pos + 1);
    }

    std::sort(alunos.begin(), alunos.end(), comparar);

    std::cout << "Matricula: " << alunos[K - 1].matricula << std::endl;
    std::cout << "Nome: " << alunos[K - 1].nome << std::endl;

    return 0;
}
