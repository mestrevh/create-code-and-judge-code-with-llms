/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, n2, num;
    std::set<int> numeros;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        numeros.insert(num);
    }

    std::cin >> n2;
    for (int i = 0; i < n2; ++i) {
        std::cin >> num;
        numeros.insert(num);
    }

    std::vector<int> resultado(numeros.begin(), numeros.end());
    std::cout << "[";
    for (size_t i = 0; i < resultado.size(); ++i) {
        std::cout << resultado[i];
        if (i < resultado.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
