/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The clock has 60 marks, each representing 360/60 = 6 degrees.
 * The minute hand (M) moves 1 mark every minute.
 * The hour hand (H) moves 1 mark every 12 minutes.
 * Both hands move discretely and are always on a mark.
 * 
 * At minute t (0 to 719):
 * Pos_M = t % 60
 * Pos_H = (t / 12) % 60
 * 
 * The distance in marks between them is d = |Pos_M - Pos_H|.
 * The minimum distance in marks is min_d = min(d, 60 - d).
 * The angle A = min_d * 6 degrees.
 * 
 * Since min_d is always an integer, any reachable angle A must be a multiple of 6.
 * As t increases, the difference Pos_M - Pos_H either stays the same (when both move) 
 * or increases by 1 (when only M moves). This ensures all integer differences 
 * from 0 to 30 marks are reachable, and thus all multiples of 6 from 0 to 180 degrees.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A;
    while (cin >> A && A != -1) {
        if (A % 6 == 0) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }

    return 0;
}