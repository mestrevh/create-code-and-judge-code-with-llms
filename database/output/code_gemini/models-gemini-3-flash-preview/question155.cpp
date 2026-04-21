/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Pão a metro (Bread by the meter)
 * Technique: Binary Search on the Answer
 * Complexity: O(K log(max_M))
 */

bool can_cut(const vector<int>& sandwiches, int N, int length) {
    if (length == 0) return true;
    long long count = 0;
    for (int m : sandwiches) {
        count += (m / length);
    }
    return count >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> M(K);
    int max_m = 0;
    for (int i = 0; i < K; ++i) {
        cin >> M[i];
        if (M[i] > max_m) max_m = M[i];
    }

    int low = 1, high = max_m;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid == 0) {
            low = 1;
            continue;
        }
        
        if (can_cut(M, N, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}

