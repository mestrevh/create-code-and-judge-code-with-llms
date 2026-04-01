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

    int N, Q, caseNum = 1;
    while (cin >> N >> Q && (N != 0 || Q != 0)) {
        vector<int> marbles(N);
        for (int i = 0; i < N; ++i) {
            cin >> marbles[i];
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << caseNum++ << ":\n";
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