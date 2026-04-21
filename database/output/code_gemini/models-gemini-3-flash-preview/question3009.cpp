/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    if (!(cin >> Q)) return 0;

    while (Q--) {
        int N;
        long long K;
        if (!(cin >> N >> K)) break;

        vector<long long> P(N);
        long long min_P = 5e18; // Large enough value for initialization
        long long max_P = -5e18;

        for (int i = 0; i < N; ++i) {
            cin >> P[i];
            if (P[i] < min_P) min_P = P[i];
            if (P[i] > max_P) max_P = P[i];
        }

        if (N == 0) continue;

        set<long long> candidates;
        for (int i = 0; i < N; ++i) {
            candidates.insert(P[i] - K);
            candidates.insert(P[i] + K);
            candidates.insert(P[i]);
        }
        candidates.insert(min_P);
        candidates.insert(max_P);

        long long best_X = min_P;
        int max_count = -1;

        for (long long x : candidates) {
            if (x < min_P || x > max_P) continue;

            int current_count = 0;
            for (int i = 0; i < N; ++i) {
                if (x - P[i] <= K && P[i] - x <= K) {
                    current_count++;
                }
            }

            if (current_count > max_count) {
                max_count = current_count;
                best_X = x;
            } else if (current_count == max_count) {
                // The set is already sorted, so the first x we encounter
                // that gives max_count is already the smallest.
                // This else if is technically redundant but kept for clarity.
                if (x < best_X) best_X = x;
            }
        }

        cout << best_X << "\n";
    }

    return 0;
}