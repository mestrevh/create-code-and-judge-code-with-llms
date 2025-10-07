/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int total_dias;
    std::cin >> total_dias;
    int anos = total_dias / 365;
    int meses = (total_dias % 365) / 30;
    int dias = (total_dias % 365) % 30;
    std::cout << anos << " ano(s)\n";
    std::cout << meses << " mes(es)\n";
    std::cout << dias << " dia(s)\n";
    return 0;
}
