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

    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int idx1, idx2;
    if (!(cin >> idx1 >> idx2)) return 0;

    int i = idx1 - 1;
    int j = idx2 - 1;

    cout << fixed << setprecision(2);
    cout << matrix[i][i] << " " << matrix[i][j] << "\n";
    cout << matrix[j][i] << " " << matrix[j][j] << "\n";

    return 0;
}