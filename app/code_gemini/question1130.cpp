/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long T, C;
    std::cin >> T >> C;

    long long total_ticks_needed = T * C;
    
    // Tantan plays for 3 real hours. 3 hours = 180 minutes.
    // 1 game day = 20 minutes of real time.
    // Real playtime in game days = 180 / 20 = 9 game days.
    // Safe building time per game day = 12000 ticks.
    // Total usable ticks per real day = 9 * 12000 = 108000 ticks.
    const long long usable_ticks_per_real_day = 108000LL;

    long long days_needed = (total_ticks_needed + usable_ticks_per_real_day - 1) / usable_ticks_per_real_day;

    std::cout << days_needed << std::endl;

    return 0;
}
