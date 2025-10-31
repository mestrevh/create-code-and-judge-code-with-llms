/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mat(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> mat[i][j];

    int lastCol = M;
    for (int i = 0; i < N; ++i) {
        int currentCol = -1;
        for (int j = 0; j < M; ++j) {
            if (mat[i][j] != 0) {
                currentCol = j;
            }
        }

        if (currentCol == -1) {
            for (int k = i + 1; k < N; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (mat[k][l] != 0) {
                        cout << "N";
                        return 0;
                    }
                }
            }
            break;
        }

        if (currentCol >= lastCol) {
            cout << "N";
            return 0;
        }

        lastCol = currentCol;
        for (int k = i + 1; k < N; ++k) {
            for (int l = 0; l <= currentCol; ++l) {
                if (mat[k][l] != 0) {
                    cout << "N";
                    return 0;
                }
            }
        }
    }
    cout << "S";
    return 0;
}
