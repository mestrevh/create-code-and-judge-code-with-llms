/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort (though not strictly needed due to loop structure)

// Using 1-based indexing for musician IDs, up to N (N < 100).
// A matrix of size 101x101 is sufficient to store scores for musicians 1 through 100.
int entrosamento[101][101];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    // Loop continues as long as N or M is not zero.
    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        // Initialize the entrosamento matrix for the current test case.
        // This ensures scores from previous test cases don't interfere.
        // N is small (max 99), so N*N initialization is fast enough.
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                entrosamento[i][j] = 0;
            }
        }

        // Read M pairs of musicians and their entrosamento scores.
        for (int k = 0; k < M; ++k) {
            int X, Y, Z;
            std::cin >> X >> Y >> Z;
            entrosamento[X][Y] = Z;
            entrosamento[Y][X] = Z; // Entrosamento is symmetric between two musicians.
        }

        int max_score = -1; // Initialize max_score to a value lower than any possible score (min score is 0 if no entrosamento).
        std::vector<int> best_trio_members(3); // To store the IDs of the musicians in the best band.

        // Iterate through all possible combinations of 3 distinct musicians.
        // Since N is less than 100, an O(N^3) brute-force approach is efficient enough.
        // The nested loops ensure that i < j < k, which guarantees:
        // 1. Each trio is considered exactly once.
        // 2. Trios are considered in lexicographical order.
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                for (int k = j + 1; k <= N; ++k) {
                    // Calculate the total entrosamento score for the current trio (i, j, k).
                    int current_score = entrosamento[i][j] + entrosamento[i][k] + entrosamento[j][k];

                    // If this trio has a higher score, update max_score and best_trio_members.
                    // Due to the lexicographical iteration order (i, j, k increasing),
                    // if multiple trios have the same max_score, the first one encountered
                    // (which is lexicographically smallest) will be kept.
                    if (current_score > max_score) {
                        max_score = current_score;
                        best_trio_members[0] = i;
                        best_trio_members[1] = j;
                        best_trio_members[2] = k;
                    }
                }
            }
        }
        
        // Output the IDs of the three musicians that form the best band,
        // separated by spaces and followed by a newline.
        // The IDs are already in ascending order due to the loop structure.
        std::cout << best_trio_members[0] << " " << best_trio_members[1] << " " << best_trio_members[2] << "\n";
    }

    return 0;
}