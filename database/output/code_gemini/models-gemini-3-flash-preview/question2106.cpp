/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

/**
 * Problem: Jogo do Pulador (The Jumper Game)
 * We have a board of size n, where each cell contains a value indicating the jump distance.
 * The board is circular. Find the starting cell that maximizes the total distance in k jumps.
 * In case of a tie, the smaller starting index is preferred.
 * 
 * Solution:
 * This is a functional graph problem where each node has exactly one outgoing edge.
 * Since the number of jumps k can be large, we use Binary Lifting (Sparse Table for functional graphs).
 * 
 * Complexity:
 * Time: O(N log K)
 * Space: O(N log K)
 */

int main() {
    // Standard I/O optimization for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k;
    if (!(cin >> n >> k)) return 0;

    // v[i] stores the jump distance from cell i
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Special case: no jumps allowed
    if (k <= 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }

    // Find the highest bit set in k to determine the sparse table depth
    int max_j = 0;
    for (int j = 62; j >= 0; j--) {
        if ((k >> j) & 1) {
            max_j = j;
            break;
        }
    }

    // up[j][i] = the position reached after 2^j jumps starting from cell i
    // dist[j][i] = the total distance covered after 2^j jumps starting from cell i
    vector<vector<int>> up(max_j + 1, vector<int>(n));
    vector<vector<ll>> dist(max_j + 1, vector<ll>(n));

    // Base case for sparse table: 2^0 = 1 jump
    for (int i = 0; i < n; i++) {
        // Modular arithmetic handles the circular nature of the board
        up[0][i] = (int)((1LL * i + (v[i] % (ll)n)) % (ll)n);
        dist[0][i] = v[i];
    }

    // Precompute sparse table transitions using the power-of-2 property
    for (int j = 1; j <= max_j; j++) {
        for (int i = 0; i < n; i++) {
            int mid = up[j - 1][i];
            up[j][i] = up[j - 1][mid];
            dist[j][i] = dist[j - 1][i] + dist[j - 1][mid];
        }
    }

    ll max_total_dist = -1;
    int best_start = 0;

    // For every possible starting cell, calculate the total jump distance in k jumps
    for (int i = 0; i < n; i++) {
        ll current_dist = 0;
        int current_pos = i;
        
        // Decompose k into powers of 2 and sum up the distances/positions
        for (int j = max_j; j >= 0; j--) {
            if ((k >> j) & 1) {
                current_dist += dist[j][current_pos];
                current_pos = up[j][current_pos];
            }
        }
        
        // Update the maximum distance and the best starting index
        // The comparison > ensures that the smallest index is kept in case of a tie.
        if (current_dist > max_total_dist) {
            max_total_dist = current_dist;
            best_start = i;
        }
    }

    // Final result: starting index followed by the total distance
    cout << best_start << " " << max_total_dist << endl;

    return 0;
}