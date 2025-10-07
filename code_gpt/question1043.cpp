/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    float dolar;
    while (std::cin >> dolar) {
        std::cout << std::fixed << std::setprecision(2) << dolar * 3.55 << std::endl;
    }
    return 0;
}
