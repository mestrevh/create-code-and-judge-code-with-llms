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

    if (ano < 1900 || ano > 2020) {
        std::cout << "Ano inexistente\n";
        return 0;
    }
    if (mes < 1 || mes > 12) {
        std::cout << "Mês inexistente\n";
        return 0;
    }
    if (dia < 1 || dia > 31) {
        std::cout << "Dia inexistente\n";
        return 0;
    }

    bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

    int max_dias_no_mes;

    if (mes == 2) {
        if (bissexto) {
            max_dias_no_mes = 29;
        } else {
            max_dias_no_mes = 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        max_dias_no_mes = 30;
    } else {
        max_dias_no_mes = 31;
    }

    if (dia > max_dias_no_mes) {
        if (mes == 2 && dia == 29 && !bissexto) {
            std::cout << "Esse ano não é bissexto\n";
        } else {
            std::cout << "Esse dia não existe nesse mês\n";
        }
        return 0;
    }

    std::cout << "Data Validada\n";

    return 0;
}
