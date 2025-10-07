/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ano_inicial, intervalo;
    std::cin >> ano_inicial >> intervalo;
    for (int i = 0; i < 3; ++i) {
        ano_inicial += intervalo;
        std::cout << ano_inicial << (i == 2 ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}
