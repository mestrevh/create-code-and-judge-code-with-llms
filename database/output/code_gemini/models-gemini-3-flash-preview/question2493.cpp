/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n < 2) {
        return 0;
    }

    long long prev_val;
    if (!(cin >> prev_val)) return 0;

    long long max_prod = numeric_limits<long long>::min();
    bool initialized = false;

    for (int i = 1; i < n; ++i) {
        long long curr_val;
        if (!(cin >> curr_val)) break;
        long long current_prod = prev_val * curr_val;
        if (!initialized) {
            max_prod = current_prod;
            initialized = true;
        } else if (current_prod > max_prod) {
            max_prod = current_prod;
        }
        prev_val = curr_val;
    }

    cout << max_prod << endl;

    return 0;
}