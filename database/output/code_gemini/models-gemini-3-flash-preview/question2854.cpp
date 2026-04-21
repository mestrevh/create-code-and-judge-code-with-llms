/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> intro_students(45);
    for (int i = 0; i < 45; ++i) {
        if (!(std::cin >> intro_students[i])) break;
    }

    std::unordered_set<int> lab_students;
    for (int i = 0; i < 30; ++i) {
        int matricula;
        if (!(std::cin >> matricula)) break;
        lab_students.insert(matricula);
    }

    std::cout << "Digite as matriculas dos alunos de Introducao a Programacao:" << "\n";
    std::cout << "Digite as matriculas dos alunos de Laboratorio de Programacao:" << "\n";
    std::cout << "Alunos matriculados em ambas as disciplinas:" << "\n";

    bool first = true;
    for (int i = 0; i < 45; ++i) {
        if (lab_students.find(intro_students[i]) != lab_students.end()) {
            if (!first) {
                std::cout << " ";
            }
            std::cout << intro_students[i];
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}