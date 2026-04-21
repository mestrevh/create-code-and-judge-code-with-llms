/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long D, C;
    if (!(cin >> D >> C)) return 0;

    // Tantan plays 3 hours per real day.
    // 3 hours = 180 minutes.
    // One full game cycle (day + night) is 24000 ticks.
    // At 20 ticks per second, one game cycle takes: 24000 / 20 = 1200 seconds = 20 minutes.
    // Number of game cycles in 3 hours: 180 / 20 = 9 cycles.
    // In each cycle, he only builds during the day (0 to 12000 ticks).
    // Ticks spent building per real day: 9 cycles * 12000 ticks/cycle = 108000 ticks.
    
    // Total ticks for D days: D * 108000.
    // Ticks per house: (D * 108000) / C.

    long long total_ticks = D * 108000LL;
    long long ticks_per_house = total_ticks / C;

    cout << ticks_per_house << endl;

    return 0;
}