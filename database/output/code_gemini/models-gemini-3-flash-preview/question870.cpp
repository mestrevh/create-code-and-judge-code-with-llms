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

    int X;
    if (!(cin >> X) || X <= 0) {
        return 0;
    }

    long long val;
    if (!(cin >> val)) {
        return 0;
    }

    long long total_sum = val;
    long long max_k = val;
    long long cur_max = val;
    long long min_k = val;
    long long cur_min = val;

    for (int i = 1; i < X; ++i) {
        if (!(cin >> val)) break;
        total_sum += val;

        cur_max = max(val, cur_max + val);
        if (cur_max > max_k) {
            max_k = cur_max;
        }

        cur_min = min(val, cur_min + val);
        if (cur_min < min_k) {
            min_k = cur_min;
        }
    }

    if (total_sum == min_k) {
        cout << max_k << "\n";
    } else {
        long long circular_max = total_sum - min_k;
        if (circular_max > max_k) {
            cout << circular_max << "\n";
        } else {
            cout << max_k << "\n";
        }
    }

    return 0;
}