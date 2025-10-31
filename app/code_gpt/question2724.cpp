/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int L1, C1, L2, C2;
    cin >> L1 >> C1 >> L2 >> C2;

    if (C1 != L2) {
        cout << "impossivel multiplicar" << endl;
        return 0;
    }

    int A[25][25], B[25][25], C[25][25] = {0};

    for (int i = 0; i < L1; i++)
        for (int j = 0; j < C1; j++)
            cin >> A[i][j];

    for (int i = 0; i < L2; i++)
        for (int j = 0; j < C2; j++)
            cin >> B[i][j];

    for (int i = 0; i < L1; i++)
        for (int j = 0; j < C2; j++)
            for (int k = 0; k < C1; k++)
                C[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < L1; i++) {
        for (int j = 0; j < C2; j++) {
            cout << C[i][j];
            if (j < C2 - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
