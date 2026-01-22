/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int calcularPotencia(int level) {
    if (level >= 1 && level <= 20) {
        return 20 + (level * level * level);
    } else if (level >= 21 && level <= 40) {
        return 8000 + ((level - 10) * (level - 10));
    } else if (level >= 41 && level <= 60) {
        return 9000 + 5 * level;
    } else if (level >= 61 && level <= 80) {
        return 9300 + 2 * level;
    } else {
        return 9500 + level;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int level;
    std::cin >> level;
    int potencia = calcularPotencia(level);
    std::cout << "Potencia de : " << potencia << " W" << std::endl;
    return 0;
}
