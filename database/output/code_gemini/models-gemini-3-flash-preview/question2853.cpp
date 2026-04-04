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

    int r, c;
    cout << "Digite as dimensoes da matriz:" << endl;
    if (!(cin >> r >> c)) return 0;

    cout << "Digite os elementos da matriz:" << endl;
    vector<vector<int>> mat(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "Matriz transposta:" << endl;
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i) {
            cout << left << setw(6) << mat[i][j];
        }
        cout << "\n";
    }

    return 0;
}