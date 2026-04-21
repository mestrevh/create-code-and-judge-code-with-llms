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

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<long long>> matrix(N, vector<long long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (N == M) {
        long long trace = 0;
        long long secondary_diag = 0;
        for (int i = 0; i < N; ++i) {
            trace += matrix[i][i];
            secondary_diag += matrix[i][N - 1 - i];
        }
        cout << trace << "\n";
        cout << secondary_diag << "\n";
    } else {
        cout << "A matriz nao possui traco\n";
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << matrix[i][j] << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}