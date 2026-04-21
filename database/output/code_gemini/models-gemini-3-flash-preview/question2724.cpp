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

    int L1, C1, L2, C2;
    if (!(cin >> L1 >> C1)) return 0;
    if (!(cin >> L2 >> C2)) return 0;

    bool possible = (C1 == L2);

    vector<vector<int>> A(L1, vector<int>(C1));
    for (int i = 0; i < L1; ++i) {
        for (int j = 0; j < C1; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(L2, vector<int>(C2));
    for (int i = 0; i < L2; ++i) {
        for (int j = 0; j < C2; ++j) {
            cin >> B[i][j];
        }
    }

    if (!possible) {
        cout << "impossivel multiplicar" << endl;
        return 0;
    }

    for (int i = 0; i < L1; ++i) {
        for (int j = 0; j < C2; ++j) {
            long long sum = 0;
            for (int k = 0; k < C1; ++k) {
                sum += (long long)A[i][k] * B[k][j];
            }
            cout << sum << (j == C2 - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}