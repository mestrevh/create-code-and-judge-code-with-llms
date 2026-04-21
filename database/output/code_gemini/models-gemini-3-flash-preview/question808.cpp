/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/**
 * generate_half1:
 * Generates all possible combinations (total price, number of items) for the first half
 * of the items using a backtracking approach with basic pruning.
 */
void generate_half1(int idx, int end, ll current_p, int current_c, const vector<ll>& p, vector<pair<ll, int>>& res, ll Q) {
    if (current_p > Q) return;
    if (idx == end) {
        res.push_back({current_p, current_c});
        return;
    }
    // Decision 1: Do not include the item at 'idx'
    generate_half1(idx + 1, end, current_p, current_c, p, res, Q);
    // Decision 2: Include the item at 'idx'
    generate_half1(idx + 1, end, current_p + p[idx], current_c + 1, p, res, Q);
}

/**
 * generate_half2:
 * Generates all possible total prices for the second half of the items,
 * categorizing them by the count of items in the subset.
 */
void generate_half2(int idx, int end, ll current_p, int current_c, const vector<ll>& p, vector<ll> res[], ll Q) {
    if (current_p > Q) return;
    if (idx == end) {
        res[current_c].push_back(current_p);
        return;
    }
    // Decision 1: Do not include the item at 'idx'
    generate_half2(idx + 1, end, current_p, current_c, p, res, Q);
    // Decision 2: Include the item at 'idx'
    generate_half2(idx + 1, end, current_p + p[idx], current_c + 1, p, res, Q);
}

int main() {
    // Fast I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K)) return 0;

    for (int case_num = 0; case_num < K; ++case_num) {
        int L;
        if (!(cin >> L)) break;

        vector<ll> p(L);
        for (int i = 0; i < L; ++i) {
            cin >> p[i];
        }

        int M;
        ll Q;
        if (!(cin >> M >> Q)) break;

        // Meet-in-the-Middle split
        int L1 = L / 2;
        int L2 = L - L1;

        // Generate subsets for the first half
        vector<pair<ll, int>> s1;
        s1.reserve(1 << L1);
        generate_half1(0, L1, 0, 0, p, s1, Q);

        // Generate subsets for the second half, indexed by count
        vector<ll> s2[32]; // Max count is L (30)
        generate_half2(L1, L, 0, 0, p, s2, Q);

        // Sort each count-category in the second half for binary search
        for (int i = 0; i <= L2; ++i) {
            if (!s2[i].empty()) {
                sort(s2[i].begin(), s2[i].end());
            }
        }

        ll ans = 0;
        // Merge results using the meet-in-the-middle technique
        for (const auto& item1 : s1) {
            ll p1 = item1.first;
            int c1 = item1.second;
            
            // For each subset from the first half, find valid complements in the second half
            for (int c2 = 0; c2 <= L2; ++c2) {
                // Rule 1: Total count must be at least M
                if (c1 + c2 >= M) {
                    ll target = Q - p1;
                    // Rule 2: Total price must not exceed Q
                    if (target >= 0) {
                        // Binary search to find how many prices p2 in s2[c2] are <= target
                        ans += upper_bound(s2[c2].begin(), s2[c2].end(), target) - s2[c2].begin();
                    }
                }
            }
        }

        // Output results for the current test case
        cout << "caso " << case_num << ": " << ans << "\n";
    }

    return 0;
}

