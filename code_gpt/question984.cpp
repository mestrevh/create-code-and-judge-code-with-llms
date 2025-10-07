/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <limits>
#include <vector>

int main() {
    int num;
    int menor = std::numeric_limits<int>::max();
    int maior = std::numeric_limits<int>::min();
    std::vector<int> inputs;

    while (std::cin >> num && num != -1) {
        inputs.push_back(num);
        if (num < menor) menor = num;
        if (num > maior) maior = num;
        std::cout << "menor=" << menor << "||MAIOR=" << maior << std::endl;
    }

    std::vector<int> multiplos;
    for (int i = menor; i <= maior; i++) {
        if (i % menor == 0) {
            multiplos.push_back(i);
        }
    }

    for (size_t i = 0; i < multiplos.size(); i++) {
        std::cout << multiplos[i];
        if (i < multiplos.size() - 1) std::cout << "||";
    }
    std::cout << std::endl;

    return 0;
}
