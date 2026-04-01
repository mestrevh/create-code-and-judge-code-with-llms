/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Botas Perdidas (Lost Boots)
 * Solution: Count pairs of boots with the same size but opposite sides.
 * Strategy: Use frequency arrays for left (E) and right (D) boots per size.
 * Complexity: O(N) per test case.
 */

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read N until N is -1
    while (cin >> N && N != -1) {
        // According to constraints, 30 <= M <= 60. 
        // We use size 61 to index directly by size value.
        int countD[61] = {0};
        int countE[61] = {0};

        for (int i = 0; i < N; ++i) {
            int M;
            char L;
            cin >> M >> L;
            if (L == 'D') {
                countD[M]++;
            } else {
                countE[M]++;
            }
        }

        int totalPairs = 0;
        // Check every possible size and sum the minimum counts of D and E boots
        for (int i = 30; i <= 60; ++i) {
            if (countD[i] > 0 && countE[i] > 0) {
                totalPairs += (countD[i] < countE[i] ? countD[i] : countE[i]);
            }
        }

        // Print result for current test case
        cout << totalPairs << "\n";
    }

    return 0;
}