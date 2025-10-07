/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Aluno {
    std::string nome;
    double nota1, nota2, nota3;
    double media;
    std::string situacao;
};

bool comparaPorNome(const Aluno& a, const Aluno& b) {
    return a.nome < b.nome;
}

void ordenarAlunos(std::vector<Aluno>& alunos) {
    std::sort(alunos.begin(), alunos.end(), comparaPorNome);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Aluno> alunos(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> alunos[i].nome;
        std::cin >> alunos[i].nota1 >> alunos[i].nota2 >> alunos[i].nota3;

        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;

        if (alunos[i].media >= 7.0) {
            alunos[i].situacao = "Aprovado";
        } else if (alunos[i].media >= 3.0) {
            alunos[i].situacao = "Final";
        } else {
            alunos[i].situacao = "Reprovado";
        }
    }

    ordenarAlunos(alunos);

    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < n; ++i) {
        std::cout << "Aluno: " << alunos[i].nome << "\n";
        std::cout << "Media: " << alunos[i].media << "\n";
        std::cout << "Situcao: " << alunos[i].situacao << "\n";

        if (i < n - 1) {
            std::cout << "\n";
        }
    }

    return 0;
}
