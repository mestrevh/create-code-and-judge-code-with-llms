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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> matrix;
    try {
        matrix.resize((long long)n * m);
    } catch (...) {
        return 0;
    }

    for (long long i = 0; i < (long long)n * m; ++i) {
        cin >> matrix[i];
    }

    int p;
    if (!(cin >> p)) return 0;

    long long total_points = 0;
    for (int i = 0; i < p; ++i) {
        int r, c;
        cin >> r >> c;
        if (r >= 1 && r <= n && c >= 1 && c <= m) {
            total_points += matrix[(long long)(r - 1) * m + (c - 1)];
        }
    }

    int t;
    if (!(cin >> t)) return 0;

    double result = 0.0;
    if (t != 0) {
        result = (double)total_points / t;
    }

    cout << fixed << setprecision(2) << result << endl;

    return 0;
}