/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Formula 1
 * Approach: Simulation of the scoring systems.
 * Given the finishing position of each pilot in each race, we compute the
 * total score for each pilot under different scoring systems and output the
 * winner(s) with the highest score. Pilot IDs are 1-indexed.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int G, P;
    // Read number of Grand Prix (G) and number of pilots (P)
    while (cin >> G >> P && (G != 0 || P != 0)) {
        // arrival_ranks[race][pilot_id] stores the rank of the pilot in that race
        // pilot_id is 0-indexed internally
        vector<vector<int>> arrival_ranks(G, vector<int>(P));
        for (int i = 0; i < G; ++i) {
            for (int j = 0; j < P; ++j) {
                cin >> arrival_ranks[i][j];
            }
        }

        int S;
        cin >> S;
        while (S--) {
            int K;
            cin >> K;
            // point_map[rank] stores points awarded for that finishing position
            vector<int> point_map(K + 1, 0);
            for (int i = 1; i <= K; ++i) {
                cin >> point_map[i];
            }

            // scores[pilot_id] stores accumulated points for the pilot
            vector<int> scores(P, 0);
            for (int i = 0; i < G; ++i) {
                for (int j = 0; j < P; ++j) {
                    int rank = arrival_ranks[i][j];
                    if (rank <= K) {
                        scores[j] += point_map[rank];
                    }
                }
            }

            // Find the maximum points obtained across all pilots
            int max_score = -1;
            for (int i = 0; i < P; ++i) {
                if (scores[i] > max_score) {
                    max_score = scores[i];
                }
            }

            // Identify and print IDs of all pilots who have the maximum points
            bool first = true;
            for (int i = 0; i < P; ++i) {
                if (scores[i] == max_score) {
                    if (!first) {
                        cout << " ";
                    }
                    cout << i + 1;
                    first = false;
                }
            }
            cout << "\n";
        }
    }

    return 0;
}

