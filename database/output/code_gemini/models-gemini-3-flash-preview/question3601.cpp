/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 1) {
        return 0;
    }

    long long first_h;
    cin >> first_h;

    long long max_dist = 0;
    long long best_prev = first_h - 0; // Stores the maximum of (H[j] - j) for all j < i

    for (int i = 1; i < n; ++i) {
        long long h;
        cin >> h;
        
        // The distance formula is H[i] + H[j] + (i - j) for i > j.
        // This can be rewritten as (H[i] + i) + (H[j] - j).
        // For each building i, we want to maximize (H[j] - j) for all j < i.
        
        long long current_dist = h + i + best_prev;
        if (current_dist > max_dist) {
            max_dist = current_dist;
        }
        
        long long current_val = h - i;
        if (current_val > best_prev) {
            best_prev = current_val;
        }
    }

    cout << max_dist << endl;

    return 0;
}