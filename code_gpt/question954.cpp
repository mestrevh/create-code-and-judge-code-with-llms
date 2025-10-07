/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Aluno {
    int matricula;
    std::string nome;
    double nota;
};

bool comp(const Aluno &a, const Aluno &b) {
    if (a.nota == b.nota)
        return a.matricula < b.matricula;
    return a.nota > b.nota;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Aluno> alunos(N);
    double soma = 0.0;

    for (int i = 0; i < N; ++i) {
        std::cin >> alunos[i].matricula;
        std::cin.ignore();
        std::getline(std::cin, alunos[i].nome);
        std::cin >> alunos[i].nota;
        soma += alunos[i].nota;
    }

    double media = soma / N;
    std::vector<Aluno> acimaDaMedia;

    for (const auto &aluno : alunos) {
        if (aluno.nota > media)
            acimaDaMedia.push_back(aluno);
    }

    std::sort(acimaDaMedia.begin(), acimaDaMedia.end(), comp);

    for (const auto &aluno : acimaDaMedia) {
        std::cout << "Matricula: " << aluno.matricula << " Nome: " << aluno.nome << " Nota: " << aluno.nota << std::endl;
    }
    
    std::cout << std::fixed << std::setprecision(2) << "Media = " << media << std::endl;
    
    return 0;
}
