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

    int n, a;
    if (!(cin >> n >> a)) return 0;

    vector<int> min_vals(n, INT_MAX);
    vector<int> max_vals(n, INT_MIN);

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            if (val < min_vals[j]) min_vals[j] = val;
            if (val > max_vals[j]) max_vals[j] = val;
        }
    }

    vector<int> current_readings(n);
    for (int j = 0; j < n; ++j) {
        cin >> current_readings[j];
    }

    for (int j = 0; j < n; ++j) {
        cout << max_vals[j] << " ";
    }
    cout << "\n";

    for (int j = 0; j < n; ++j) {
        cout << min_vals[j] << " ";
    }
    cout << "\n";

    vector<long long> final_vals(n);
    for (int j = 0; j < n; ++j) {
        long long diff = (long long)max_vals[j] - min_vals[j];
        long long norm;
        if (diff == 0) {
            norm = (current_readings[j] >= min_vals[j]) ? 1000 : 0;
        } else {
            norm = (long long)(current_readings[j] - min_vals[j]) * 1000 / diff;
        }
        
        if (norm < 0) norm = 0;
        if (norm > 1000) norm = 1000;
        
        final_vals[j] = 1000 - norm;
        cout << final_vals[j] << " ";
    }
    cout << "\n";

    long long numerator = 0;
    long long denominator = 0;
    for (int j = 0; j < n; ++j) {
        numerator += (final_vals[j] * (long long)j * 1000);
        denominator += final_vals[j];
    }

    if (denominator == 0) {
        cout << 0 << "\n";
    } else {
        cout << numerator / denominator << "\n";
    }

    return 0;
}