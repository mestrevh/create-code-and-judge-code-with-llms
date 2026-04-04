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

    int Ai, Aj, Bi, Bj;
    if (!(cin >> Ai >> Aj >> Bi >> Bj)) return 0;

    if (Aj != Bi) {
        cout << "Nao e possivel multiplicar" << endl;
        return 0;
    }

    vector<vector<long long>> A(Ai, vector<long long>(Aj));
    for (int i = 0; i < Ai; ++i) {
        for (int j = 0; j < Aj; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> B(Bi, vector<long long>(Bj));
    for (int i = 0; i < Bi; ++i) {
        for (int j = 0; j < Bj; ++j) {
            cin >> B[i][j];
        }
    }

    vector<vector<long long>> C(Ai, vector<long long>(Bj, 0));
    for (int i = 0; i < Ai; ++i) {
        for (int k = 0; k < Aj; ++k) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < Bj; ++j) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < Ai; ++i) {
        for (int j = 0; j < Bj; ++j) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

