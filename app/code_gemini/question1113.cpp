/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int dia, mes, ano;
    std::cin >> dia >> mes >> ano;

    if (ano < 1900 || ano > 2100) {
        std::cout << "invalida\n";
        return 0;
    }

    if (mes < 1 || mes > 12) {
        std::cout << "invalida\n";
        return 0;
    }

    int max_dias;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        max_dias = 30;
    } else if (mes == 2) {
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        max_dias = bissexto ? 29 : 28;
    } else {
        max_dias = 31;
    }

    if (dia < 1 || dia > max_dias) {
        std::cout << "invalida\n";
    } else {
        std::cout << "valida\n";
    }

    return 0;
}
