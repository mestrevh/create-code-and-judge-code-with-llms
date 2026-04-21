/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Calculate P1 of a binary tree of height H.
 * Pi = Vi if node i is a leaf.
 * Pi = max(Vi * PL, Vi * PR) if node i has children L and R.
 * Tree is indexed 1 to N top-to-bottom, left-to-right.
 * 
 * Strategy:
 * 1. Read height H. Total nodes N = 2^H - 1.
 * 2. Read values Vi into an array.
 * 3. Calculate Pi values bottom-up starting from the last node.
 * 4. Complexity: O(N) time and space.
 */

int main() {
    // Optimize Standard I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H;
    if (!(cin >> H)) return 0;

    // A full binary tree of height H has N = 2^H - 1 nodes.
    // Given H <= 15, N is at most 32767.
    int N = (1 << H) - 1;
    if (N <= 0) return 0;

    // Vector to store node values Vi. Using 1-based indexing.
    vector<long long> V(N + 1);
    for (int i = 1; i <= N; ++i) {
        if (!(cin >> V[i])) break;
    }

    // Vector to store calculated Pi values.
    // Using long long to accommodate potential large products.
    vector<long long> P(N + 1);

    // Process nodes from N down to 1 (bottom-up).
    for (int i = N; i >= 1; --i) {
        int leftChild = i << 1;      // 2 * i
        int rightChild = leftChild | 1; // 2 * i + 1

        if (leftChild > N) {
            // If the left child index exceeds N, the node is a leaf.
            P[i] = V[i];
        } else {
            // For internal nodes, Pi = max(Vi * P_left, Vi * P_right).
            // Since Vi is positive, Pi = Vi * max(P_left, P_right).
            // This assumes rightChild also exists, which is true for a full binary tree.
            long long leftProd = V[i] * P[leftChild];
            long long rightProd = V[i] * P[rightChild];
            
            if (leftProd > rightProd) {
                P[i] = leftProd;
            } else {
                P[i] = rightProd;
            }
        }
    }

    // Output the calculated P1 value.
    cout << P[1] << endl;

    return 0;
}