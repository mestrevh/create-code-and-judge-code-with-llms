/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void eh_bissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        std::cout << "bissexto" << std::endl;
    } else {
        std::cout << "nao bissexto" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ano;
    std::cin >> ano;
    eh_bissexto(ano);
    return 0;
}
