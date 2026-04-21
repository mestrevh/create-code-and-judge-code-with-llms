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

    int n;
    if (!(cin >> n)) return 0;

    if (n < 1) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> h[i])) break;
    }

    vector<int> left_max(n);
    int current_left_max = 0;
    for (int i = 0; i < n; ++i) {
        if (h[i] > current_left_max) {
            current_left_max = h[i];
        }
        left_max[i] = current_left_max;
    }

    int sections_covered = 0;
    int current_right_max = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (h[i] > current_right_max) {
            current_right_max = h[i];
        }
        
        int water_level = (left_max[i] < current_right_max) ? left_max[i] : current_right_max;
        
        if (water_level > h[i]) {
            sections_covered++;
        }
    }

    cout << sections_covered << "\n";

    return 0;
}