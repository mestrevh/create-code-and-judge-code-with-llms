/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Fibonacci Tree path existence problem.
 * Leonardo's tree T(N) is defined as:
 * - Root has diameter N.
 * - Each ball of diameter k >= 3 has two children: diameters k-1 and k-2.
 * - Balls of diameter 1 and 2 have no children.
 * A path in the tree must:
 * 1. Have adjacent diameters connected in the tree.
 * 2. Not reuse any ball (simple path).
 * 
 * Property: In any tree, a non-backtracking path (B_i != B_{i-2}) is a simple path.
 * In this Fibonacci tree, every neighbor of a ball has a unique diameter.
 * Neighbor diameters of ball d: {Parent, d-1, d-2}.
 * Since Parent > d > d-1 > d-2, all neighbor diameters are distinct.
 * Therefore, B_i != B_{i-2} is equivalent to L_i != L_{i-2}.
 */

void solve(int N, int K) {
    vector<int> L(K);
    for (int i = 0; i < K; ++i) cin >> L[i];

    // Check if diameters exist in T(N)
    // d exists in T(N) if d == N or (d < N and N >= 3)
    for (int i = 0; i < K; ++i) {
        if (L[i] > N || L[i] < 1 || (L[i] < N && N < 3)) {
            cout << "N" << endl;
            return;
        }
    }

    if (K == 1) {
        cout << "S" << endl;
        return;
    }

    // bit 0: parent is L[i]+1
    // bit 1: parent is L[i]+2
    // bit 2: parent is None (root)
    int mask = 0;
    if (L[0] + 1 <= N && L[0] + 1 >= 3) mask |= 1;
    if (L[0] + 2 <= N && L[0] + 2 >= 3) mask |= 2;
    if (L[0] == N) mask |= 4;

    for (int i = 0; i < K - 1; ++i) {
        int curr_L = L[i];
        int next_L = L[i + 1];
        int prev_L = (i > 0) ? L[i - 1] : -1;

        int diff = abs(next_L - curr_L);
        if (diff == 0 || diff > 2) {
            cout << "N" << endl;
            return;
        }
        // backtracking check
        if (next_L == prev_L) {
            cout << "N" << endl;
            return;
        }

        int new_mask = 0;
        // Option 1: next_L is a child of curr_L (so parent of next_L is curr_L)
        if (curr_L >= 3 && mask != 0) {
            if (next_L == curr_L - 1) new_mask |= 1; // parent is next_L + 1
            if (next_L == curr_L - 2) new_mask |= 2; // parent is next_L + 2
        }

        // Option 2: next_L is the parent of curr_L
        if (next_L >= 3) {
            if (((mask & 1) && next_L == curr_L + 1) || ((mask & 2) && next_L == curr_L + 2)) {
                if (next_L + 1 <= N) new_mask |= 1;
                if (next_L + 2 <= N) new_mask |= 2;
                if (next_L == N) new_mask |= 4;
            }
        } else if (next_L == N) { 
            // Case where N < 3, root can't have children but we check it for consistency
            if ((mask & 1) && next_L == curr_L + 1) new_mask |= 4;
            if ((mask & 2) && next_L == curr_L + 2) new_mask |= 4;
        }

        mask = new_mask;
        if (mask == 0) {
            cout << "N" << endl;
            return;
        }
    }
    cout << "S" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    while (cin >> N >> K) {
        solve(N, K);
    }
    return 0;
}