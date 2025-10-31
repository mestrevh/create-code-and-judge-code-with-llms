/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    double peso;
    int count = 0;
    double totalPeso = 0.0;
    
    while (true) {
        std::cin >> peso;
        if (peso == 0 || count >= 7 || totalPeso + peso > 560) {
            break;
        }
        totalPeso += peso;
        count++;
    }

    std::cout << count << std::endl;
    std::cout << std::fixed << std::setprecision(1) << totalPeso << std::endl;

    return 0;
}
