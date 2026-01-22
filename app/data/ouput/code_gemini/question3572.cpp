/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int total_dias_entrada;
    std::cin >> total_dias_entrada;
    int anos = total_dias_entrada / 365;
    int dias_restantes = total_dias_entrada % 365;
    int semanas = dias_restantes / 7;
    int dias = dias_restantes % 7;
    std::cout << anos << " ano(s), " << semanas << " semana(s) e " << dias << " dia(s)" << std::endl;
    return 0;
}
