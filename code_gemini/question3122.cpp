/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long D, C;
    std::cin >> D >> C;
    long long total_real_seconds = D * 3 * 3600;
    long long total_game_ticks = total_real_seconds * 20;
    long long building_ticks = total_game_ticks / 2;
    long long ticks_per_house = building_ticks / C;
    std::cout << ticks_per_house << std::endl;
    return 0;
}
