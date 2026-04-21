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

    int N, M, O;
    if (!(cin >> N >> M >> O)) return 0;

    vector<vector<long long>> A(N, vector<long long>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> B(M, vector<long long>(O));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < O; ++j) {
            cin >> B[i][j];
        }
    }

    vector<vector<long long>> C(N, vector<long long>(O, 0));

    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < M; ++k) {
            long long temp = A[i][k];
            for (int j = 0; j < O; ++j) {
                C[i][j] += temp * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < O; ++j) {
            cout << C[i][j] << (j == O - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}