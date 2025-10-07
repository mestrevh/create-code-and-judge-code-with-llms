/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int Ai, Aj, Bi, Bj;
    cin >> Ai >> Aj >> Bi >> Bj;

    if (Aj != Bi) {
        cout << "Nao e possivel multiplicar" << endl;
        return 0;
    }

    vector<vector<int>> A(Ai, vector<int>(Aj)), B(Bi, vector<int>(Bj)), C(Ai, vector<int>(Bj, 0));

    for (int i = 0; i < Ai; ++i)
        for (int j = 0; j < Aj; ++j)
            cin >> A[i][j];

    for (int i = 0; i < Bi; ++i)
        for (int j = 0; j < Bj; ++j)
            cin >> B[i][j];

    for (int i = 0; i < Ai; ++i)
        for (int j = 0; j < Bj; ++j)
            for (int k = 0; k < Aj; ++k)
                C[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < Ai; ++i) {
        for (int j = 0; j < Bj; ++j) {
            cout << C[i][j] << (j == Bj - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
