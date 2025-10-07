/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

int main() {
    int Y, count = 0, sum = 0, validCount = 0;
    std::cin >> Y;
    int number;

    for (int i = 0; i < 20; i++) {
        std::cin >> number;
        if (number == -1) break;
        if (number == Y) count++;
        if (number > 0 && (number < 15 || number > 20)) {
            sum += number;
            validCount++;
        }
    }

    std::cout << "O número " << Y << " apareceu " << count << " vez(es)\n";
    if (validCount > 0) {
        std::cout << std::fixed << std::setprecision(2) << "A média dos números foi de: " << (double)sum / validCount << "\n";
    } else {
        std::cout << "Sem valores para calcular a média\n";
    }

    return 0;
}
