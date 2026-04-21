/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int level;
    if (!(std::cin >> level)) return 0;

    long long result = 0;
    if (level >= 1 && level <= 20) {
        result = 20 + (long long)level * level * level;
    } else if (level >= 21 && level <= 40) {
        result = 8000 + (long long)(level - 10) * (level - 10);
    } else if (level >= 41 && level <= 60) {
        result = 9000 + 5LL * level;
    } else if (level >= 61 && level <= 80) {
        result = 9300 + 2LL * level;
    } else if (level >= 81 && level <= 100) {
        result = 9500 + (long long)level;
    }

    std::cout << "Potencia de : " << result << " W" << std::endl;

    return 0;
}