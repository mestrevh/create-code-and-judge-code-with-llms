/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) return 0;

    if (n == 1) {
        double val;
        cin >> val;
        cout << fixed << setprecision(2) << 0.00 << endl;
        return 0;
    }

    vector<double> v(n);
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    double mean = sum / n;
    double sum_sq_diff = 0;
    for (int i = 0; i < n; ++i) {
        double diff = v[i] - mean;
        sum_sq_diff += diff * diff;
    }

    double std_dev = sqrt(sum_sq_diff / (n - 1));

    cout << fixed << setprecision(2) << std_dev << endl;

    return 0;
}