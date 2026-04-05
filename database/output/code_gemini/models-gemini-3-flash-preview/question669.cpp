/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T_cases;
    if (!(cin >> T_cases)) return 0;

    while (T_cases--) {
        long long N;
        int R;
        if (!(cin >> N >> R)) break;

        vector<long long> rows, cols;
        if (R > 0) {
            rows.reserve(R);
            cols.reserve(R);
        }

        for (int i = 0; i < R; ++i) {
            int t;
            long long p;
            cin >> t >> p;
            if (t == 0) {
                rows.push_back(p);
            } else {
                cols.push_back(p);
            }
        }

        sort(rows.begin(), rows.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());

        sort(cols.begin(), cols.end());
        cols.erase(unique(cols.begin(), cols.end()), cols.end());

        long long total = 2 * N * N + 2 * N + 1;

        long long pins_in_R = 0;
        vector<long long> ar;
        ar.reserve(rows.size());
        for (long long r : rows) {
            long long d = (r > (N + 1)) ? (r - (N + 1)) : ((N + 1) - r);
            if (d <= N) {
                pins_in_R += (2 * (N - d) + 1);
                ar.push_back(d);
            }
        }
        sort(ar.begin(), ar.end());

        long long pins_in_C = 0;
        long long intersection = 0;
        for (long long c : cols) {
            long long d = (c > (N + 1)) ? (c - (N + 1)) : ((N + 1) - c);
            if (d <= N) {
                long long K = N - d;
                pins_in_C += (2 * K + 1);
                intersection += (long long)(upper_bound(ar.begin(), ar.end(), K) - ar.begin());
            }
        }

        long long ans = total - pins_in_R - pins_in_C + intersection;
        cout << ans << "\n";
    }

    return 0;
}