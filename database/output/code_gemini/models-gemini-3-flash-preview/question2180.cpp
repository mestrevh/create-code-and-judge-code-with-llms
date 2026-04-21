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

    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; ++t) {
        int n;
        if (!(cin >> n)) break;

        vector<int> r(n);
        int max_diff = 0;
        int last_h = 0;
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
            int d = r[i] - last_h;
            if (d > max_diff) {
                max_diff = d;
            }
            last_h = r[i];
        }

        int cur_k = max_diff;
        bool ok = true;
        last_h = 0;
        for (int i = 0; i < n; ++i) {
            int d = r[i] - last_h;
            if (d == cur_k) {
                cur_k--;
            } else if (d > cur_k) {
                ok = false;
                break;
            }
            last_h = r[i];
        }

        cout << "Case " << t << ": ";
        if (ok) {
            cout << max_diff << "\n";
        } else {
            cout << max_diff + 1 << "\n";
        }
    }

    return 0;
}