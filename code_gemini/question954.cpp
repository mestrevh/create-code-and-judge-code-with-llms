/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>

struct Aluno {
    int matricula;
    std::string nome;
    double nota;
};

bool compararAlunos(const Aluno& a, const Aluno& b) {
    if (a.nota < b.nota) {
        return true;
    }
    if (a.nota > b.nota) {
        return false;
    }
    return a.matricula < b.matricula;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << std::fixed << std::setprecision(2) << "Media = 0.00\n";
        return 0;
    }

    std::vector<Aluno> alunos(n);
    double somaNotas = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cin >> alunos[i].matricula;
        std::cin.ignore();
        std::getline(std::cin, alunos[i].nome);
        std::cin >> alunos[i].nota;
        somaNotas += alunos[i].nota;
    }

    double media = somaNotas / n;

    std::vector<Aluno> acimaDaMedia;
    for (const auto& aluno : alunos) {
        if (aluno.nota > media) {
            acimaDaMedia.push_back(aluno);
        }
    }

    std::sort(acimaDaMedia.begin(), acimaDaMedia.end(), compararAlunos);

    std::cout << std::fixed;
    
    std::cout << std::setprecision(1);
    for (const auto& aluno : acimaDaMedia) {
        std::cout << "Matricula: " << aluno.matricula 
                  << " Nome: " << aluno.nome 
                  << " Nota: " << aluno.nota << '\n';
    }

    std::cout << std::setprecision(2);
    std::cout << "Media = " << media << '\n';

    return 0;
}
