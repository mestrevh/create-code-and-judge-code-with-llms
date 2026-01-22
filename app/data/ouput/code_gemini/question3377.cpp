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
    if (idade >= 18) {
        std::cout << "maior de idade" << std::endl;
    } else {
        std::cout << "menor de idade" << std::endl;
    }
    return 0;
}
