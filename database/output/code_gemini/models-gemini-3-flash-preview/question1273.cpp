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

    int N;
    if (!(cin >> N)) return 0;

    if (N <= 0) return 0;

    vector<vector<int>> mat(N, vector<int>(N));
    int current = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = current++;
        }
    }

    cout << "Matriz:" << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(3) << mat[i][j];
        }
        cout << "\n";
    }

    cout << "\nDiagonal Principal:" << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "   ";
        }
        cout << setw(3) << mat[i][i] << "\n";
    }

    cout << "\nDiagonal Secundaria:" << "\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (N - 1 - i); ++j) {
            cout << "   ";
        }
        cout << setw(3) << mat[i][N - 1 - i] << "\n";
    }

    return 0;
}