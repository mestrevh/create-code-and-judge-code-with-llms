/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int area_total;
    int area_ceramica;
    std::cin >> area_total >> area_ceramica;
    int quantidade_ceramicas = (area_total + area_ceramica - 1) / area_ceramica;
    int area_comprada = quantidade_ceramicas * area_ceramica;
    int preco_total = area_comprada * 25;
    std::cout << quantidade_ceramicas << std::endl;
    std::cout << preco_total << std::endl;
    return 0;
}
