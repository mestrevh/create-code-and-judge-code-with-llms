/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Bolhas e Baldes (Inversion Parity)
 * The game consists of swapping adjacent out-of-order elements in a permutation.
 * Each such swap reduces the total number of inversions by exactly one.
 * The game ends when the sequence is sorted (0 inversions).
 * Since the number of moves is equal to the initial number of inversions,
 * the winner is determined by the parity of the inversion count.
 * Marcelo wins if the inversion count is odd, Carlos wins if it is even.
 * 
 * Permutation Parity Property:
 * The parity of the number of inversions is the same as the parity of (N - C),
 * where N is the number of elements and C is the number of disjoint cycles in the permutation.
 * This allows an O(N) solution.
 */

int p[100005];
bool visited[100005];

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n && n != 0) {
        // Read the permutation and reset visited status
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            visited[i] = false;
        }

        // Count disjoint cycles in the permutation
        int cycles = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                cycles++;
                int curr = i;
                // Traverse the cycle
                while (!visited[curr]) {
                    visited[curr] = true;
                    curr = p[curr];
                }
            }
        }

        // The number of inversions has the same parity as (n - cycles)
        // Marcelo plays first and wins if the total moves is odd
        if ((n - cycles) % 2 != 0) {
            cout << "Marcelo\n";
        } else {
            cout << "Carlos\n";
        }
    }

    return 0;
}