/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    const int N_INTRO = 45;
    const int N_LAB = 30;

    std::vector<int> intro_prog(N_INTRO);
    std::unordered_set<int> lab_prog_set;

    std::cout << "Digite as matriculas dos alunos de Introducao a Programacao:\n";
    for (int i = 0; i < N_INTRO; ++i) {
        std::cin >> intro_prog[i];
    }

    std::cout << "Digite as matriculas dos alunos de Laboratorio de Programacao:\n";
    for (int i = 0; i < N_LAB; ++i) {
        int matricula;
        std::cin >> matricula;
        lab_prog_set.insert(matricula);
    }

    std::cout << "Alunos matriculados em ambas as disciplinas:\n";

    bool first_output = true;
    for (int matricula : intro_prog) {
        if (lab_prog_set.count(matricula)) {
            if (!first_output) {
                std::cout << " ";
            }
            std::cout << matricula;
            first_output = false;
        }
    }

    return 0;
}
