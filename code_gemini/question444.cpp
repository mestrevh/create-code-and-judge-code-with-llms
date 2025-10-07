/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int caixas;
    std::cin >> caixas;
    int total_comprimidos = caixas * 35;
    int dias = total_comprimidos / 4;
    int sobra = total_comprimidos % 4;
    std::cout << dias << '\n';
    std::cout << sobra << '\n';
    return 0;
}
