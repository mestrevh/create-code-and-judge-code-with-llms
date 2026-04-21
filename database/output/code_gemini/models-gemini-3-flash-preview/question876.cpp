/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int ano_nascimento, ano_atual;
    if (std::cin >> ano_nascimento >> ano_atual) {
        std::cout << (ano_atual - ano_nascimento) << "\n";
    }

    return 0;
}