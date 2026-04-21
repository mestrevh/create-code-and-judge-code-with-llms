/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: Laser Sculpture
 * Logic:
 * Let A be the initial height of the block.
 * Let Xi be the final height of the block at position i.
 * The depth to be cut at position i is Di = A - Xi.
 * The laser moves horizontally. To calculate the number of times the laser is turned on,
 * we observe that if we move from position i-1 to position i:
 * - If Di > Di-1, we need to turn on the laser (Di - Di-1) additional times to cut deeper layers.
 * - If Di <= Di-1, the layers being cut at position i were already being cut at position i-1.
 * 
 * Therefore, total "ons" = D0 + sum(max(0, Di - Di-1)) for i = 1 to C-1.
 * Since Di = A - Xi, then:
 * D0 = A - X0
 * Di - Di-1 = (A - Xi) - (A - Xi-1) = Xi-1 - Xi.
 * Total = (A - X0) + sum(max(0, Xi-1 - Xi)).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, C;
    while (cin >> A >> C && (A != 0 || C != 0)) {
        int prev_X;
        cin >> prev_X;

        long long total_ons = A - prev_X;

        for (int i = 1; i < C; ++i) {
            int current_X;
            cin >> current_X;
            if (prev_X > current_X) {
                total_ons += (prev_X - current_X);
            }
            prev_X = current_X;
        }

        cout << total_ons << "\n";
    }

    return 0;
}

