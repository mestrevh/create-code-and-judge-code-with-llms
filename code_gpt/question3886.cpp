/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double massa;
    std::cin >> massa;

    double gravidade[10] = {9.81, 3.71, 8.87, 24.79, 10.44, 8.69, 11.15, 22.58, 3.7, 1.62};
    double pesos[10];

    for(int i = 0; i < 10; i++) {
        pesos[i] = massa * gravidade[i];
    }

    std::cout << std::fixed << std::setprecision(2);
    for(int i = 0; i < 10; i++) {
        std::cout << pesos[i] << std::endl;
    }

    return 0;
}
