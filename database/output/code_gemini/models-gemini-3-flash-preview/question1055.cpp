/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n <= 0) return 0;

    vector<double> diagonal(n);
    double trace_sum = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double value;
            cin >> value;
            if (i == j) {
                diagonal[i] = value;
                trace_sum += value;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "tr(A) = ";
    for (int i = 0; i < n; ++i) {
        cout << "(" << diagonal[i] << ")";
        if (i < n - 1) {
            cout << " + ";
        }
    }
    cout << " = " << trace_sum << endl;

    return 0;
}