/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C)) {
        return 0;
    }

    if (R <= 0 || C <= 0) {
        return 0;
    }

    vector<vector<int>> matrix(R, vector<int>(C));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int j = 0; j < C; ++j) {
        for (int i = 0; i < R; ++i) {
            cout << matrix[i][j] << (i == R - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}