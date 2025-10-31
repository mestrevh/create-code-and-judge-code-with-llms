/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::unordered_set<int> matriculasII;
    std::vector<int> matriculasIII;
    int matricula;

    for (int i = 0; i < 45; ++i) {
        std::cin >> matricula;
        matriculasII.insert(matricula);
    }

    for (int i = 0; i < 30; ++i) {
        std::cin >> matricula;
        matriculasIII.push_back(matricula);
    }

    for (const auto& m : matriculasIII) {
        if (matriculasII.count(m)) {
            std::cout << m << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
