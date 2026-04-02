/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<double> alphas(n);
    double max_alpha = -1.0;

    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            
            double val = abs(matrix[i][j]);
            if (j < i) {
                sum += val * alphas[j];
            } else {
                sum += val;
            }
        }
        alphas[i] = sum / abs(matrix[i][i]);
        if (alphas[i] > max_alpha) {
            max_alpha = alphas[i];
        }
    }

    if (max_alpha < 1.0) {
        cout << "SIM" << "\n";
    } else {
        cout << "NAO" << "\n";
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i) {
        cout << alphas[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
溺