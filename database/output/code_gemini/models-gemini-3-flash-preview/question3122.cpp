/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem Logic:
 * 1. Tantan plays 3 real-world hours per day.
 * 2. 1 second in game = 20 ticks.
 * 3. 1 full in-game day cycle = 24,000 ticks.
 * 4. Daylight lasts from tick 0 to 12,000 (12,000 ticks total).
 * 5. Tantan only builds during daylight.
 * 
 * Calculations:
 * - Real-world seconds per playing session: 3 hours * 60 min * 60 sec = 10,800 seconds.
 * - Total game ticks per playing session: 10,800 seconds * 20 ticks/sec = 216,000 ticks.
 * - Since 216,000 / 24,000 = 9, he plays exactly 9 in-game day/night cycles per session.
 * - Daylight ticks per playing session: 9 cycles * 12,000 daylight-ticks/cycle = 108,000 ticks.
 * - Total building ticks for D days: D * 108,000.
 * - Ticks per house: (D * 108,000) / C.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long d, c;
    if (cin >> d >> c) {
        // We use 108000LL as the constant derived from (3 * 3600 * 20 / 2)
        long long total_daylight_ticks = d * 108000LL;
        long long ticks_per_house = total_daylight_ticks / c;
        
        cout << ticks_per_house << "\n";
    }

    return 0;
}