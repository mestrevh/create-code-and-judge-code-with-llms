/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q, case_number = 1;
    while (true) {
        cin >> N >> Q;
        if (N == 0 && Q == 0) break;

        vector<int> marbles(N);
        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << case_number++ << ":\n";
        for (int i = 0; i < Q; ++i) {
            int query;
            cin >> query;
            auto it = lower_bound(marbles.begin(), marbles.end(), query);
            if (it != marbles.end() && *it == query) {
                cout << query << " found at " << (it - marbles.begin() + 1) << "\n";
            } else {
                cout << query << " not found\n";
            }
        }
    }
    return 0;
}
