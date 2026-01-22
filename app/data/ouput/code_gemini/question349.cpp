/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int mes, ano;
    std::cin >> mes >> ano;

    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            std::cout << 29 << std::endl;
        } else {
            std::cout << 28 << std::endl;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        std::cout << 30 << std::endl;
    } else {
        std::cout << 31 << std::endl;
    }

    return 0;
}
