/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T, C;
    if (!(cin >> T >> C)) {
        return 0;
    }

    // A game day is 24000 ticks (20 minutes real time).
    // Tantan only builds during the day (0 to 12000 ticks).
    // So, in 24000 ticks of game time, he only works for 12000 ticks.
    //
    // Tantan plays for 3 hours (180 minutes) per real day.
    // 180 minutes / 20 minutes = 9 game days per real day.
    // In each game day, he works 12000 ticks.
    // Total working ticks per real day = 9 * 12000 = 108000 ticks.

    long long total_ticks_needed = T * C;
    long long ticks_per_real_day = 108000;

    // Calculate real days needed, rounding up for any fraction of a day.
    long long days_needed = (total_ticks_needed + ticks_per_real_day - 1) / ticks_per_real_day;

    cout << days_needed << endl;

    return 0;
}