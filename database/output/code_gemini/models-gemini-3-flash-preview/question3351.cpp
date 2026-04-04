/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A[3][3], B[3][3], C[3][3];

    while (cin >> A[0][0]) {
        for (int j = 1; j < 3; ++j) cin >> A[0][j];
        for (int i = 1; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> B[i][j];
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                C[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << C[i][j] << (j == 2 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}