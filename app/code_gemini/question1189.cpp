/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int power;
    int max_power = 0;
    while (std::cin >> power && power != 0) {
        if (power > max_power) {
            max_power = power;
        }
    }
    std::cout << max_power << std::endl;
    return 0;
}
