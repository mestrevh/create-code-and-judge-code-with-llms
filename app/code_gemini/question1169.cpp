/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int level;
    std::cin >> level;
    int potencia = 0;
    if (level >= 1 && level <= 20) {
        potencia = 20 + (level * level * level);
    } else if (level >= 21 && level <= 40) {
        potencia = 8000 + (level - 10) * (level - 10);
    } else if (level >= 41 && level <= 60) {
        potencia = 9000 + 5 * level;
    } else if (level >= 61 && level <= 80) {
        potencia = 9300 + 2 * level;
    } else if (level >= 81 && level <= 100) {
        potencia = 9500 + level;
    }
    std::cout << "Potencia de : " << potencia << " W\n";
    return 0;
}
