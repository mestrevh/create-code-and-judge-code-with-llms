/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, X;
    if (!(cin >> N >> M >> X)) return 0;

    vector<vector<string>> mat(N, vector<string>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mat[i][j];
        }
    }

    int k = (X % 4 + 4) % 4;
    int R = (k % 2 == 0) ? N : M;
    int idx = (X % N + N) % N;
    idx %= R; 

    vector<string> result;
    if (k == 0) {
        for (int j = 0; j < M; ++j) {
            result.push_back(mat[idx][j]);
        }
    } else if (k == 1) {
        for (int j = 0; j < N; ++j) {
            result.push_back(mat[N - 1 - j][idx]);
        }
    } else if (k == 2) {
        for (int j = 0; j < M; ++j) {
            result.push_back(mat[N - 1 - idx][M - 1 - j]);
        }
    } else if (k == 3) {
        for (int j = 0; j < N; ++j) {
            result.push_back(mat[j][M - 1 - idx]);
        }
    }

    for (int i = 0; i < M; ++i) {
        if (i < (int)result.size()) {
            cout << result[i];
        } else {
            cout << "Qualquer";
        }
        if (i < M - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}