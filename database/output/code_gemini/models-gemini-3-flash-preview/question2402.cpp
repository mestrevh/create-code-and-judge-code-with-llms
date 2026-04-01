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

    int n;
    if (!(cin >> n)) return 0;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> m[i])) break;
    }

    long long best_sum = -1;
    int best_start = -1;
    int best_end = -1;

    long long current_sum = m[0];
    int current_start_idx = 0;

    for (int i = 1; i < n; ++i) {
        if (m[i] > m[i - 1]) {
            current_sum += m[i];
        } else {
            // Check if the strictly increasing interval has at least two days
            if (i - current_start_idx >= 2) {
                if (current_sum > best_sum) {
                    best_sum = current_sum;
                    best_start = current_start_idx + 1;
                    best_end = i;
                }
            }
            current_sum = m[i];
            current_start_idx = i;
        }
    }

    // Final check for the segment ending at the last day
    if (n - current_start_idx >= 2) {
        if (current_sum > best_sum) {
            best_sum = current_sum;
            best_start = current_start_idx + 1;
            best_end = n;
        }
    }

    cout << best_start << " " << best_end << " " << best_sum << endl;

    return 0;
}