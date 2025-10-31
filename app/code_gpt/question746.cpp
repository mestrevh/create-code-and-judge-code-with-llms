/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, O;
    cin >> N >> M >> O;
    vector<vector<int>> A(N, vector<int>(M)), B(M, vector<int>(O)), C(N, vector<int>(O, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < O; ++j)
            cin >> B[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < O; ++j)
            for (int k = 0; k < M; ++k)
                C[i][j] += A[i][k] * B[k][j];

    for (const auto& row : C) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
