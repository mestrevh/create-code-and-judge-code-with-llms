/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string EstacaoAno(int dia, int mes) {
    if ((mes == 3 && dia >= 21) || (mes > 3 && mes < 6) || (mes == 6 && dia <= 20)) {
        return "OUTONO";
    } else if ((mes == 6 && dia >= 21) || (mes > 6 && mes < 9) || (mes == 9 && dia <= 20)) {
        return "INVERNO";
    } else if ((mes == 9 && dia >= 21) || (mes > 9 && mes < 12) || (mes == 12 && dia <= 20)) {
        return "PRIMAVERA";
    } else {
        return "VERAO";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int dia, mes;
    std::cin >> dia >> mes;
    std::cout << EstacaoAno(dia, mes) << std::endl;
    return 0;
}
