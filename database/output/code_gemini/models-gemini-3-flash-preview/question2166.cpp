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

    int n_cases;
    if (!(cin >> n_cases)) return 0;
    
    while (n_cases--) {
        int t;
        if (!(cin >> t)) break;
        
        vector<int> h(t);
        vector<int> c(t);
        
        int low = 1000000, high = -1000000;
        
        for (int i = 0; i < t; ++i) {
            if (!(cin >> h[i])) break;
            if (h[i] < low) low = h[i];
            if (h[i] > high) high = h[i];
        }
        
        for (int i = 0; i < t; ++i) {
            if (!(cin >> c[i])) break;
        }

        if (t <= 0) {
            cout << "0\n";
            continue;
        }

        long long min_total_cost = -1;

        for (int target = low; target <= high; ++target) {
            long long current_cost = 0;
            for (int i = 0; i < t; ++i) {
                int diff = h[i] - target;
                if (diff < 0) diff = -diff;
                current_cost += (long long)diff * c[i];
            }
            if (min_total_cost == -1 || current_cost < min_total_cost) {
                min_total_cost = current_cost;
            }
        }

        if (min_total_cost == -1) {
            cout << "0\n";
        } else {
            cout << min_total_cost << "\n";
        }
    }

    return 0;
}