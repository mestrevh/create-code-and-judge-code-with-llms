/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Football (Maximize points by buying goals)
 * Scoring: Win = 3, Draw = 1, Loss = 0.
 * Budget: G goals.
 * Strategy: 
 * 1. Calculate points from existing wins.
 * 2. Prioritize turning draws into wins (cost: 1 goal, gain: +2 points).
 * 3. Turn losses into wins (cost: (R-S)+1 goals, gain: +3 points), 
 *    processing those with the smallest goal difference first.
 * 4. If a loss cannot be turned into a win, check if it can be turned 
 *    into a draw (cost: (R-S) goals, gain: +1 point).
 */

int main() {
    // Optimize Standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, g;
    // Handle input - single or multiple test cases
    while (cin >> n >> g) {
        long long points = 0;
        vector<int> losses;
        int draws = 0;

        for (int i = 0; i < n; ++i) {
            int s, r;
            cin >> s >> r;
            if (s > r) {
                // Already a win
                points += 3;
            } else if (s == r) {
                // Currently a draw
                draws++;
            } else {
                // Currently a loss, store the goal difference
                losses.push_back(r - s);
            }
        }

        // Each existing draw currently provides 1 point.
        points += (long long)draws;
        
        // Strategy: Turn draws into wins first (cost 1, gain +2)
        int can_win_draws = min(draws, g);
        points += (long long)can_win_draws * 2;
        g -= can_win_draws;

        // Sort losses by the number of goals needed to change the result
        sort(losses.begin(), losses.end());

        // Process losses: prioritized by smallest goal difference
        for (int diff : losses) {
            if (g >= diff + 1) {
                // Turn loss into a win
                g -= (diff + 1);
                points += 3;
            } else if (g == diff) {
                // Turn loss into a draw
                g -= diff;
                points += 1;
            }
            // If g < diff, no goals can be spent effectively on this match
        }

        // Output the result for the test case
        cout << points << "\n";
    }

    return 0;
}