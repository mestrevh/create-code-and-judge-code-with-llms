/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    while (cin >> n && n != -1) {
        if (!(cin >> x)) break;

        vector<int> original(n);
        for (int i = 0; i < n; ++i) {
            cin >> original[i];
        }

        vector<int> sorted_v = original;
        sort(sorted_v.begin(), sorted_v.end());

        struct Match {
            int orig_val;
            int sort_val;
            int pos;
        };

        vector<Match> results;
        for (int i = 0; i < n; ++i) {
            int diff = original[i] - sorted_v[i];
            if (diff < 0) diff = -diff;
            if (diff == x) {
                results.push_back({original[i], sorted_v[i], i + 1});
            }
        }

        cout << results.size() << "\n";
        for (const auto& m : results) {
            cout << m.orig_val << " " << m.sort_val << " " << m.pos << "\n";
        }
    }

    return 0;
}