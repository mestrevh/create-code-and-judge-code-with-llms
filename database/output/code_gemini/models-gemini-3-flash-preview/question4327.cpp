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

    int x, y;
    static vector<int> dists;
    dists.reserve(500005);

    while (cin >> x >> y) {
        dists.clear();
        int d;
        while (cin >> d && d != 0) {
            dists.push_back(d);
        }

        if (dists.empty()) continue;

        auto it_start = lower_bound(dists.begin(), dists.end(), y);
        auto it_end = upper_bound(dists.begin(), dists.end(), x);

        if (it_start < it_end) {
            int start_idx = (int)(it_start - dists.begin()) + 1;
            int end_idx = (int)(it_end - dists.begin());
            cout << start_idx << " " << end_idx << "\n";
        }
    }

    return 0;
}