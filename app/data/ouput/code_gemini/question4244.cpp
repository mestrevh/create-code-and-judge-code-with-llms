/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Aluno {
    std::string nome;
    double n1, n2, n3;
};

bool compararPorNome(const Aluno& a, const Aluno& b) {
    return a.nome < b.nome;
}

void ordenarAlunos(std::vector<Aluno>& alunos) {
    std::sort(alunos.begin(), alunos.end(), compararPorNome);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<Aluno> alunos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> alunos[i].nome;
        std::cin >> alunos[i].n1 >> alunos[i].n2 >> alunos[i].n3;
    }

    ordenarAlunos(alunos);

    for (int i = 0; i < n; ++i) {
        double media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3) / 3.0;
        
        std::cout << "Aluno: " << alunos[i].nome << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Media: " << media << std::endl;

        if (media >= 7.0) {
            std::cout << "Situcao: Aprovado" << std::endl;
        } else if (media >= 3.0) {
            std::cout << "Situcao: Final" << std::endl;
        } else {
            std::cout << "Situcao: Reprovado" << std::endl;
        }

        if (i < n - 1) {
            std::cout << std::endl;
        }
    }
    
    return 0;
}
