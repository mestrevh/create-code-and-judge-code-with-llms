/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        int m;
        if (!(cin >> m)) break;

        vector<int> arrival_order(m);
        for (int i = 0; i < m; ++i) {
            cin >> arrival_order[i];
        }

        vector<int> sorted_order = arrival_order;
        sort(sorted_order.begin(), sorted_order.end(), greater<int>());

        int unchanged_count = 0;
        for (int i = 0; i < m; ++i) {
            if (arrival_order[i] == sorted_order[i]) {
                unchanged_count++;
            }
        }

        cout << unchanged_count << "\n";
    }

    return 0;
}