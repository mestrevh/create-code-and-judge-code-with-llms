/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int idade, soma = 0, cont = 0;
    std::vector<int> idades;

    while (true) {
        std::cin >> idade;
        if (idade == 0) break;
        idades.push_back(idade);
        soma += idade;
        cont++;
    }

    if (cont == 0) return 0;

    int media = std::round(static_cast<float>(soma) / cont);
    std::cout << "media de idade da turma: " << media << std::endl;

    if (media <= 25) {
        std::cout << "jovem" << std::endl;
    } else if (media <= 60) {
        std::cout << "adulta" << std::endl;
    } else {
        std::cout << "idosa" << std::endl;
    }

    return 0;
}
