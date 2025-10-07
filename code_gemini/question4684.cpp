/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> col_counts(m, 0);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] == x) {
                col_counts[j]++;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << col_counts[i] << (i == m - 1 ? "" : " ");
    }
    cout << endl << endl;

    int max_count = 0;
    for (int count : col_counts) {
        max_count = max(max_count, count);
    }

    vector<vector<int>> histogram(max_count, vector<int>(m, 0));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < col_counts[j]; ++i) {
            histogram[i][j] = 1;
        }
    }

    for (int i = 0; i < max_count; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << histogram[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
