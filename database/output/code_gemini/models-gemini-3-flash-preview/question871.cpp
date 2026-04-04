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

    int L, C;
    if (!(cin >> L >> C)) return 0;

    vector<vector<long long>> mat(L, vector<long long>(C));
    long long lt0 = 0, gt0 = 0;

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            if (!(cin >> mat[i][j])) break;
            if (mat[i][j] < 0) {
                lt0++;
            } else if (mat[i][j] > 0) {
                gt0++;
            }
        }
    }

    cout << "Matriz formada:" << "\n";
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << mat[i][j] << (j == C - 1 ? "" : " ");
        }
        cout << "\n";
    }

    if (L == C && L > 0) {
        long long d1 = 0, d2 = 0;
        for (int i = 0; i < L; ++i) {
            d1 += mat[i][i];
            d2 += mat[i][L - 1 - i];
        }
        cout << "A diagonal principal e secundaria tem valor(es) " << d1 << " e " << d2 << " respectivamente." << "\n";
    } else {
        cout << "A diagonal principal e secundaria nao pode ser obtida." << "\n";
    }

    cout << "A matriz possui " << lt0 << " numero(s) menor(es) que zero." << "\n";
    cout << "A matriz possui " << gt0 << " numero(s) maior(es) que zero." << "\n";

    return 0;
}