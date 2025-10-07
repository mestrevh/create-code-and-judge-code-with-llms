/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == -1) {
                int base = matrix[i][0];
                matrix[i][j] = (int)pow(base, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j];
            if (j < M - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
