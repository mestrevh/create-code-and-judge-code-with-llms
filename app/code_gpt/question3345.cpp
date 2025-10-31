/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    
    vector<int> max_vals(n, INT_MIN);
    vector<int> min_vals(n, INT_MAX);
    
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            max_vals[j] = max(max_vals[j], value);
            min_vals[j] = min(min_vals[j], value);
        }
    }
    
    vector<int> readings(n);
    for (int j = 0; j < n; ++j) {
        cin >> readings[j];
    }
    
    vector<int> normalized(n);
    for (int j = 0; j < n; ++j) {
        double norm_val = (static_cast<double>(readings[j] - min_vals[j]) / (max_vals[j] - min_vals[j])) * 1000;
        norm_val = max(0.0, min(1000.0, norm_val));
        normalized[j] = 1000 - static_cast<int>(norm_val);
    }
    
    int position = 0;
    for (int j = 0; j < n; ++j) {
        position += normalized[j] * j;
    }
    
    cout << max_vals[j] << " ";
    cout << min_vals[j] << " ";
    for (int j = 0; j < n; ++j) {
        cout << normalized[j] << " ";
    }
    cout << endl << position / 3000.0 << endl;

    return 0;
}
