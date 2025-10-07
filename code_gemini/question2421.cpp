/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p;
    std::cin >> p;
    int moedas_500 = p / 500;
    p %= 500;
    int moedas_100 = p / 100;
    p %= 100;
    int moedas_50 = p / 50;
    p %= 50;
    int moedas_10 = p / 10;
    p %= 10;
    int moedas_5 = p / 5;
    p %= 5;
    int moedas_1 = p;
    std::cout << moedas_500 << " moedas de 500.\n";
    std::cout << moedas_100 << " moedas de 100.\n";
    std::cout << moedas_50 << " moedas de 50.\n";
    std::cout << moedas_10 << " moedas de 10.\n";
    std::cout << moedas_5 << " moedas de 5.\n";
    std::cout << moedas_1 << " moedas de 1.\n";
    return 0;
}
