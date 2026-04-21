/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Passadas do Relógio
 * Persona: Grande Mestre em Programação Competitiva
 * Logic:
 *   - 12-hour analog clock where the hour hand stays at its position for the entire hour.
 *   - The hour hand position (ph) for hour H (1..12) is (H % 12) * 5 in minute-units.
 *   - The minute hand position (m) moves continuously from 0 to 60.
 *   - A "pass" occurs if the minute hand crosses the stationary hour hand during its movement.
 *   - As per Test 1, starting exactly at the hour hand (which happens at 12:00:00 where ph=0 and m=0)
 *     does not count as "passing". Thus, the pass condition for an hour H is m_start < ph < m_end.
 */

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, m1, h2, m2;
    // Reading hours and minutes for start and end times
    if (!(cin >> h1 >> m1 >> h2 >> m2)) return 0;

    // Convert times to total minutes from a 12:00:00 reference point.
    // In a 12-hour clock, 12:00 behaves as the 0-th minute.
    int t1 = (h1 % 12) * 60 + m1;
    int t2 = (h2 % 12) * 60 + m2;

    // If the final time is less than or equal to the start time, 
    // it implies the interval spans across the 12-hour boundary (next day/cycle).
    if (t2 <= t1) {
        t2 += 720; // 12 hours * 60 minutes
    }

    int passes = 0;
    int t = t1;

    // Simulate the time interval hour by hour
    while (t < t2) {
        // Calculate the boundaries of the current clock hour
        int current_hour_base = (t / 60) * 60;
        int next_hour_base = current_hour_base + 60;
        int step_end = min(t2, next_hour_base);

        // Hour h in [0, 11] where 0 is hour 12, 1 is hour 1, ..., 11 is hour 11.
        int h = (t / 60) % 12;
        
        // Hour hand position (stationary for the duration of the hour)
        int ph = h * 5;

        // Start and end positions of the minute hand in the current segment
        int m_start = t - current_hour_base;
        int m_end = step_end - current_hour_base;

        // A crossing occurs if ph is strictly between m_start and m_end.
        // This handles the "jump" of the hour hand at the start of every hour.
        if (m_start < ph && m_end > ph) {
            passes++;
        }

        // Advance to the next segment (either next hour or end of interval)
        t = step_end;
    }

    // Output the total number of times the minute hand passed the hour hand
    cout << passes << endl;

    return 0;
}