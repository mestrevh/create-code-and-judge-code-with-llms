/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) {
        if (n == 0) cout << "[]" << endl;
        return 0;
    }

    vector<double> jumps(n);
    double current_max;

    for (int i = 0; i < n; ++i) {
        if (!(cin >> jumps[i])) break;
        if (i == 0 || jumps[i] > current_max) {
            current_max = jumps[i];
        }
        cout << fixed << setprecision(1) << current_max << "\n";
    }

    sort(jumps.begin(), jumps.end());

    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(1) << jumps[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}