/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k) {
        vector<int> m(k);
        int max_m = 0;
        for (int i = 0; i < k; ++i) {
            cin >> m[i];
            if (m[i] > max_m) {
                max_m = m[i];
            }
        }

        int low = 1, high = max_m;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid <= 0) break;

            long long total_slices = 0;
            for (int i = 0; i < k; ++i) {
                total_slices += (m[i] / mid);
            }

            if (total_slices >= (long long)n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}