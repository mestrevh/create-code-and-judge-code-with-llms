/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <set>

int main() {
    std::set<int> numeros;
    int num;

    while (true) {
        std::cin >> num;
        if (num == 99) break;
        numeros.insert(num);
    }

    if (numeros.size() < 2) return 1; // Garantido pelo enunciado

    auto it = numeros.rbegin();
    ++it; // Pula o maior
    std::cout << *it << std::endl;

    return 0;
}
