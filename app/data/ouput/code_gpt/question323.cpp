/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

void printMatrix(int N) {
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    int numLayers = (N + 1) / 2;

    for (int layer = 0; layer < numLayers; ++layer) {
        int value = layer + 1;
        for (int i = layer; i < N - layer; ++i) {
            matrix[layer][i] = value;
            matrix[N - layer - 1][i] = value;
        }
        for (int i = layer; i < N - layer; ++i) {
            matrix[i][layer] = value;
            matrix[i][N - layer - 1] = value;
        }
    }

    for (const auto& row : matrix) {
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << row[i];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        printMatrix(N);
    }
    return 0;
}
