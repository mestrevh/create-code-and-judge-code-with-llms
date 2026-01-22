/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int dias, km;
    std::cin >> dias >> km;

    double valorTotal = dias * 90;
    int kmExcedente = km - (dias * 100);
    
    if (kmExcedente > 0) {
        valorTotal += kmExcedente * 12;
    }

    std::cout << std::fixed << std::setprecision(2) << valorTotal << std::endl;
    return 0;
}
