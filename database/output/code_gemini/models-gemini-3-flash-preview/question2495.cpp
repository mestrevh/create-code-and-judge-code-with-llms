/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 1) {
        int dummy;
        for(int i = 0; i < n; ++i) cin >> dummy;
        cout << 0 << endl;
        return 0;
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    
    for (int i = 0; i < n; ++i) {
        int current;
        cin >> current;
        if (current < min_val) min_val = current;
        if (current > max_val) max_val = current;
    }

    int total_needed_range = max_val - min_val + 1;
    int additional_statues = total_needed_range - n;

    cout << (additional_statues < 0 ? 0 : additional_statues) << endl;

    return 0;
}