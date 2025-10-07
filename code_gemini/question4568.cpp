/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <limits>

using namespace std;

int main() {
    vector<vector<int>> matrix(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
        }
    }

    double sum = 0;
    int max_val = numeric_limits<int>::min();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum += matrix[i][j];
            max_val = max(max_val, matrix[i][j]);
        }
    }

    double average = sum / 9.0;
    int delta = (max_val > 0) ? 1 : (max_val < 0 ? -1 : 0);
    int diagonal_sum = 0;
    for (int i = 0; i < 3; ++i) {
        diagonal_sum += matrix[i][i];
    }

    cout << fixed << setprecision(2) << average << " " << max_val << " " << delta << " " << diagonal_sum << endl;

    return 0;
}
