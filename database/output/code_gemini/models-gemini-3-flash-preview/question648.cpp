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

    int n, p;
    while (cin >> n >> p && (n != 0 || p != 0)) {
        vector<int> q(p);
        int s1 = -1, idx1 = -1;
        
        for (int i = 0; i < p; ++i) {
            cin >> q[i];
            for (int j = 0; j < q[i]; ++j) {
                int box_id;
                cin >> box_id;
                if (box_id == 1) {
                    s1 = i;
                    idx1 = j;
                }
            }
        }

        // Boxes to be removed in box 1's own stack (those above it)
        int above = q[s1] - 1 - idx1;

        // Count boxes that must be removed if we clear the left side
        int left_cost = 0;
        for (int i = s1 - 1; i >= 0; --i) {
            if (q[i] > idx1) {
                left_cost += (q[i] - idx1);
            } else {
                // The cascade stops if a stack is already shorter than or equal to box 1's height
                break;
            }
        }

        // Count boxes that must be removed if we clear the right side
        int right_cost = 0;
        for (int i = s1 + 1; i < p; ++i) {
            if (q[i] > idx1) {
                right_cost += (q[i] - idx1);
            } else {
                // The cascade stops if a stack is already shorter than or equal to box 1's height
                break;
            }
        }

        // Total minimum boxes to remove is boxes above + the cheaper side to clear
        cout << above + min(left_cost, right_cost) << "\n";
    }

    return 0;
}