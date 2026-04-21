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

    int t_cases;
    if (!(cin >> t_cases)) return 0;
    while (t_cases--) {
        int n;
        if (!(cin >> n)) break;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (n == 1) {
            cout << "1 1\n";
            continue;
        }

        int best_start = 0;
        int best_end = 1;
        int max_len = 2;

        int cur_start = 0;
        long long cur_diff = a[1] - a[0];

        for (int i = 2; i < n; i++) {
            long long diff = a[i] - a[i - 1];
            if (diff == cur_diff) {
                int cur_len = i - cur_start + 1;
                if (cur_len > max_len) {
                    max_len = cur_len;
                    best_start = cur_start;
                    best_end = i;
                }
            } else {
                cur_start = i - 1;
                cur_diff = diff;
                // Note: Every two consecutive elements form an AP of length 2.
                // If max_len is 2, it will naturally keep the earliest one
                // because we only update best_start/end if cur_len > max_len.
            }
        }

        cout << best_start + 1 << " " << best_end + 1 << "\n";
    }

    return 0;
}