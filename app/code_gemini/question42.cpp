/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idade;
    std::cin >> idade;
    if (idade < 16) {
        std::cout << "nao eleitor\n";
    } else if (idade >= 18 && idade <= 65) {
        std::cout << "eleitor obrigatorio\n";
    } else {
        std::cout << "eleitor facultativo\n";
    }
    return 0;
}
