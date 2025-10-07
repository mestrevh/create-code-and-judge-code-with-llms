/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

bool isCavity(vector<vector<int>>& matrix, int i, int j) {
    int val = matrix[i][j];
    return val < matrix[i-1][j] && val < matrix[i+1][j] &&
           val < matrix[i][j-1] && val < matrix[i][j+1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    vector<pair<int, int>> cavities;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (isCavity(matrix, i, j)) {
                cavities.emplace_back(i, j);
            }
        }
    }

    cout << "[";
    for (size_t k = 0; k < cavities.size(); k++) {
        cout << "(" << cavities[k].first << ", " << cavities[k].second << ")";
        if (k < cavities.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
