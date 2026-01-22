/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

void generateSubsets(int n, int index, std::vector<int>& current) {
    if (index > n) {
        std::cout << "{";
        for (size_t i = 0; i < current.size(); ++i) {
            std::cout << (i > 0 ? " " : "") << current[i];
        }
        std::cout << "}" << std::endl;
        return;
    }
    // Incluir o número atual
    current.push_back(index);
    generateSubsets(n, index + 1, current);
    // Não incluir o número atual
    current.pop_back();
    generateSubsets(n, index + 1, current);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> current;
    generateSubsets(n, 1, current);
    std::cout << "{}" << std::endl; // Imprime o conjunto vazio
    return 0;
}
