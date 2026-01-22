/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int total_cadeiras, cadeiras_por_linha, coluna;
    std::cin >> total_cadeiras >> cadeiras_por_linha >> coluna;
    for (int i = coluna; i <= total_cadeiras; i += cadeiras_por_linha) {
        std::cout << i << std::endl;
    }
    return 0;
}
