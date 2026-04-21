/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Troca de cartas (Card Exchange)
 * Goal: Find the maximum number of cards Alice and Beatriz can swap.
 * Constraints: Alice and Beatriz can only receive cards they don't already have.
 *              They swap N distinct cards for N distinct cards in a single operation.
 * Logic: 
 * 1. Find unique cards for Alice (S_A) and Beatriz (S_B).
 * 2. Identify cards Alice has that Beatriz does not (OnlyA).
 * 3. Identify cards Beatriz has that Alice does not (OnlyB).
 * 4. Max swap N = min(|OnlyA|, |OnlyB|).
 */

int main() {
    // Optimize I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    while (cin >> A >> B && (A != 0 || B != 0)) {
        vector<int> alice;
        vector<int> beatriz;
        
        // Use reserve to avoid multiple reallocations
        alice.reserve(A);
        beatriz.reserve(B);

        int x, last = -1;
        // Read Alice's cards and keep only unique values (input is already sorted)
        for (int i = 0; i < A; ++i) {
            cin >> x;
            if (x != last) {
                alice.push_back(x);
                last = x;
            }
        }

        last = -1;
        // Read Beatriz's cards and keep only unique values (input is already sorted)
        for (int i = 0; i < B; ++i) {
            cin >> x;
            if (x != last) {
                beatriz.push_back(x);
                last = x;
            }
        }

        int onlyA = 0;
        int onlyB = 0;

        // Use a two-pointer approach to find set differences in O(A+B)
        size_t i = 0, j = 0;
        while (i < alice.size() && j < beatriz.size()) {
            if (alice[i] < beatriz[j]) {
                // Current card is unique to Alice
                onlyA++;
                i++;
            } else if (alice[i] > beatriz[j]) {
                // Current card is unique to Beatriz
                onlyB++;
                j++;
            } else {
                // Both have this card, cannot be swapped
                i++;
                j++;
            }
        }
        
        // Add remaining cards if one collection was longer than the other
        onlyA += (alice.size() - i);
        onlyB += (beatriz.size() - j);

        // Result is the bottleneck: they can only trade as many as the person with fewer unique cards can offer
        if (onlyA < onlyB) {
            cout << onlyA << "\n";
        } else {
            cout << onlyB << "\n";
        }
    }

    return 0;
}