/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

int main() {
    int power, max_power = 0;
    while (true) {
        std::cin >> power;
        if (power == 0) break;
        max_power = std::max(max_power, power);
    }
    std::cout << max_power << std::endl;
    return 0;
}
