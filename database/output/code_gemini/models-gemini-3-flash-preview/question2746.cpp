/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The total cost to disassemble the figure is the sum of costs to remove each piece.
 * For each piece i, the cost is the sum of t_j for all its neighbors j still in the figure.
 * 
 * Consider an edge (u, v) connecting pieces u and v.
 * When we remove u and v, one of them must be removed before the other.
 * - If u is removed before v, we pay the cost t_v at the moment u is removed.
 * - If v is removed before u, we pay the cost t_u at the moment v is removed.
 * 
 * Each edge (u, v) contributes exactly once to the total cost, either as t_u or t_v.
 * To minimize the total cost, for every edge (u, v), we want to pay min(t_u, t_v).
 * 
 * This lower bound is achievable:
 * Sort all pieces in descending order of their times t_i and remove them in that order.
 * For any edge (u, v), the piece with the higher t_i will be removed first (or later if ties),
 * meaning the piece with the lower t_i will be "seen" as a remaining neighbor, or vice versa.
 * Specifically, if we remove the pieces with the largest t_i values first, then for any edge (u, v)
 * where t_u >= t_v, u is removed while v is still there, adding t_v to the total cost.
 * Since t_v = min(t_u, t_v), we achieve the minimum possible contribution for that edge.
 */

int main() {
    // Standard I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Piece removal times
    vector<long long> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    long long total_min_time = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // For each cord (u, v), we choose to pay the smaller of the two costs
        if (t[u] < t[v]) {
            total_min_time += t[u];
        } else {
            total_min_time += t[v];
        }
    }

    cout << total_min_time << endl;

    return 0;
}