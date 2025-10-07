/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ano_inicial, ano_final;
    std::cin >> ano_inicial >> ano_final;
    bool encontrou = false;
    for (int ano = ano_inicial; ano <= ano_final; ++ano) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            std::cout << ano << "\n";
            encontrou = true;
        }
    }
    if (!encontrou) {
        std::cout << "-1\n";
    }
    return 0;
}
