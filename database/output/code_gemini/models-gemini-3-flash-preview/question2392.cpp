/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: A grande estreia
 * Objective: Minimize the distance walked in the rain, given N meters, two sidewalks, 
 *            and at most one crossing. The street itself is not covered (cost 1).
 * Complexity: O(N) time and O(N) space.
 */

int main() {
    // Standard I/O optimization for Competitive Programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Coverage data for side 1 and side 2
    // 1 = covered (0 wet), 0 = not covered (1 wet)
    vector<int> s1(n), s2(n);
    for (int i = 0; i < n; ++i) cin >> s1[i];
    for (int i = 0; i < n; ++i) cin >> s2[i];

    // Prefix sums of wet meters for each sidewalk
    // p1[i] = total wet meters on side 1 for the first i meters
    vector<int> p1(n + 1, 0), p2(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p1[i + 1] = p1[i] + (1 - s1[i]);
        p2[i + 1] = p2[i] + (1 - s2[i]);
    }

    // Option 0: No crossing. Take side 1 or side 2 for all n meters.
    int ans = min(p1[n], p2[n]);

    // Check all possible crossing points.
    // If they cross at meter index k, that meter is always wet (cost 1).
    for (int k = 0; k < n; ++k) {
        // Path A: Start on side 1 for meters [0, k-1], cross at meter k, then side 2 for [k+1, n-1]
        int current1 = p1[k] + 1 + (p2[n] - p2[k + 1]);
        
        // Path B: Start on side 2 for meters [0, k-1], cross at meter k, then side 1 for [k+1, n-1]
        int current2 = p2[k] + 1 + (p1[n] - p1[k + 1]);
        
        if (current1 < ans) ans = current1;
        if (current2 < ans) ans = current2;
    }

    cout << ans << endl;

    return 0;
}