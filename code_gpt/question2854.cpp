/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::vector<int> intro(45), lab(30);
    std::unordered_set<int> lab_set;
    
    std::cout << "Digite as matriculas dos alunos de Introducao a Programacao:\n";
    for (int i = 0; i < 45; ++i) {
        std::cin >> intro[i];
    }
    
    std::cout << "Digite as matriculas dos alunos de Laboratorio de Programacao:\n";
    for (int i = 0; i < 30; ++i) {
        std::cin >> lab[i];
        lab_set.insert(lab[i]);
    }
    
    std::cout << "Alunos matriculados em ambas as disciplinas:\n";
    for (int i = 0; i < 45; ++i) {
        if (lab_set.find(intro[i]) != lab_set.end()) {
            std::cout << intro[i] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
