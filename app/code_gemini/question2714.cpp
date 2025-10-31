/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int soma = 0;
    for (int i = 1; i <= 100; ++i) {
        soma += i;
    }
    std::cout << "Soma dos 100 primeiros inteiros: " << soma << std::endl;
    return 0;
}
